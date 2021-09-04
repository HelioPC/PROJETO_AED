#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LDL_FUNC__
#define __LS_FUNC__
#define __DT_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;
extern LISTAHIST *LHS;
extern LISTA_KID *LKD;

int strcountc(char *s, char c){
	int i, qt=0;
	for(i=0; s[i]!='\0'; i++){
		if(s[i] == c) qt++;
	}
	
	return qt;
}

int isFloat(char *s){
	int i, qt=0;
	
	if(!strlen(s)) return 0;
	if(!isdigit(s[0]) && !isdigit(s[strlen(s)-1])) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(isdigit(s[i])) qt++;
	}
	
	if((long unsigned int) qt != strlen(s)){
		if(strcountc(s, ',') == 0 && strcountc(s, '.') == 0) return 0;
	}
	
	if(strcountc(s, '.')){
		s[strcspn(s, ".")] = ',';
	}
	
	return (long unsigned int) qt >= strlen(s)-1;
}

int isNome(char *s){
	int i, qt=0;
	
	if(strlen(s) < 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(isdigit(s[i])) return 0;
		if(isalpha(s[i]) || isspace(s[i])) qt++;
	}
	
	return (long unsigned int) qt == strlen(s);
}

int isTel(char *s){
	int i;
	
	if(strlen(s) != 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(!isdigit(s[i])) return 0;
	}
	
	if(atoi(s) < 920000000 || atoi(s) > 999999999) return 0;
	
	return 1;
}

int isBI(char *s){
	int i;
	
	if(strlen(s) != 14) return 0;
	if(!isalpha(s[10]) || !isalpha(s[9])) return 0;
	if(!isupper(s[10]) || !isupper(s[9])) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(ispunct(s[i])) return 0;
		if(i == 9 || i == 10) continue;
		if(!isdigit(s[i])) return 0;
	}
	
	return 1;
}

int isCED(char *s){
	int i;
	
	if(strlen(s) != 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(!isdigit(s[i])) return 0;
	}
	
	return 1;
}

int getOption(int min, int max){
	int opc, cont=0;

	if(min > max){
		min += max;
		max = min-max;
		min -= max;
	}

	opc = min-1;

	while(opc<min || opc>max){
		printf("\nEscolha uma opção: ");

		if(cont++ == 10) system(limpa);

		scanf("%d", &opc);
		__fpurge(stdin);
	}

	return opc;
}

void load(){
	FILE *fp;
	CLI cli;
	HIST hst;
	CONTA_KID kd;

	if(access(CLIFILE, F_OK)){
		puts("\nFicheiros inexistentes ou incompletos");
		_pause();
		return;
	}

	fp = fopen(CLIFILE, "r+b");

	while(fread(&cli, sizeof(CLI), 1, fp) == 1){
		inserirK(cli);
	}

	fclose(fp);

	if(!access(HISTFILE, F_OK)){
		fp = fopen(HISTFILE, "r+b");

		while(fread(&hst, sizeof(HIST), 1, fp) == 1){
			inserirF_LH(hst);
		}

		fclose(fp);
	}

	if(!access(KIDFILE, F_OK)){
		fp = fopen(KIDFILE, "r+b");

		if(fread(LKD->kid, sizeof(CONTA_KID), 1, fp) < 1){
			puts("Erro 6B6964R");
		}

		else{
			LKD->qt = 0;
			while(isData(LKD->kid[LKD->qt].dat_nasc)){
				LKD->qt++;
			}
		}

		fclose(fp);
	}

	puts("Dados carregados com sucesso...");
}

void save(){
	FILE *fp;
	NOCli *aux;
	NOHIST *walk;

	if(LCL == NULL || *LCL == NULL){
		puts("Sem dados para salvar.");
		_pause();
		return;
	}

	fp = fopen(CLIFILE, "w+b");

	aux = *LCL;

	while(aux != NULL){
		if(fwrite(&aux->cliente, sizeof(CLI), 1, fp) != 1) puts("Erro 636C69");
		fflush(fp);
		aux = aux->prox;
	}

	fclose(fp);

	if(*LHS != NULL){
		fp = fopen(HISTFILE, "w+b");

		walk = *LHS;

		while(walk != NULL){
			if(fwrite(&walk->h, sizeof(HIST), 1, fp)) puts("Erro 68697374");
			fflush(fp);
			walk = walk->prox;
		}

		fclose(fp);
	}

	if(LKD->qt != 0){
		fp = fopen(KIDFILE, "w+b");

		if(fwrite(LKD->kid, sizeof(CONTA_KID), LKD->qt, fp) != (size_t)LKD->qt){
			puts("Erro 6B6964");
		}
		fflush(fp);

		fclose(fp);
	}

	puts("\n\nOperação concluída..."); _pause();
}

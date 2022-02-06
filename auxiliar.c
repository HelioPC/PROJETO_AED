#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LDL_FUNC__
#define __LS_FUNC__
#define __DT_FUNC__
#define __COLORS__
#include "Declaração.h"

extern LISTACLI *LCL;
extern LISTAHIST *LHS;
extern LISTA_KID *LKD;
extern int loaded;

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
	
	if(strcountc(s, ',')){
		s[strcspn(s, ",")] = '.';
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

	puts(NORM);

	while(opc<min || opc>max){
		printf("\nEscolha uma opção: ");

		if(cont++ == 10) system(limpa);
		
		printf("%s", GREEN);

		scanf("%d", &opc);
		fflush(stdin);
	}

	puts(NORM);

	return opc;
}

void getout(){
	puts(GREEN_A);
	printf("Saindo..."); sleep(1);
	puts(NORM);
}

void pressEnter(){
	puts(GREEN_A);
	printf("\nPress enter to continue...");
	puts(NORM);
	_pause();
}

void load(){
	FILE *fp;
	CLI cli;
	HIST hst;

	if(access(CLIFILE, F_OK)){
		puts("\nFicheiros inexistentes ou incompletos");
		pressEnter();
		return;
	}

	if(loaded){
		puts("\n\nNão é possível carregar os dados"); pressEnter();
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

	loaded = 1;

	puts("\n\nDados carregados com sucesso..."); pressEnter();
}

void save(){
	FILE *fp;
	NOCli *aux;
	NOHIST *walk;

	if(LCL == NULL || *LCL == NULL){
		puts("Sem dados para salvar.");
		pressEnter();
		return;
	}

	fp = fopen(CLIFILE, "wb");

	aux = *LCL;

	while(aux != NULL){
		if(fwrite(&aux->cliente, sizeof(CLI), 1, fp) != 1) puts("Erro 636C69");
		fflush(fp);
		aux = aux->prox;
	}

	fclose(fp);

	if(*LHS != NULL){
		fp = fopen(HISTFILE, "wb");

		walk = *LHS;

		while(walk != NULL){
			if(fwrite(&walk->h, sizeof(HIST), 1, fp) != 1) puts("Erro 68697374");
			fflush(fp);
			walk = walk->prox;
		}

		fclose(fp);
	}

	if(LKD->qt != 0){
		fp = fopen(KIDFILE, "wb");

		if(fwrite(LKD->kid, sizeof(CONTA_KID), LKD->qt, fp) != (size_t)LKD->qt){
			puts("Erro 6B6964");
		}
		fflush(fp);

		fclose(fp);
	}

	puts("\n\nOperação concluída..."); pressEnter();
}

void readaccount(char n_conta[15]){
	printf("Introduza o número da conta: ");
	fgets(n_conta, 15, stdin);
	fflush(stdin);
	n_conta[strcspn(n_conta, "\n")] = '\0';

	while(n_conta[0] != 'B'){
		printf("Conta inválida!");
		printf("\nIntroduza o número da conta: ");
		fgets(n_conta, 15, stdin);
		fflush(stdin);
		n_conta[strcspn(n_conta, "\n")] = '\0';
	}
}

void readname(char nome[80]){
	do{
		printf("\nIntroduza o seu nome: ");
		fflush(stdin);
		fgets(nome, 80, stdin);
		nome[strcspn(nome, "\n")] = '\0';
	}while(!isNome(nome));
}

DATA readdata(char *msg){
	char str[11];
	DATA d;

	printf("\nIntroduza a data%s: ", msg);
	fgets(str, 11, stdin);d = strToData(str);
	fflush(stdin);
	str[strcspn(str, "\n")] = '\0';
	
	while(!isData(d)){
		printf("\nIntroduza a data%s: ", msg);
		fgets(str, 11, stdin);d = strToData(str);
		fflush(stdin);
		str[strcspn(str, "\n")] = '\0';
	}

	return d;
}

double getvalue(){
	char s[14];

	printf("\n\nIntroduza o valor: ");
	fgets(s, 14, stdin);
	fflush(stdin);
	s[strcspn(s, "\n")] = '\0';
	
	while(!isFloat(s)){
		printf("\n\nIntroduza o valor: ");
		fgets(s, 14, stdin);
		fflush(stdin);
		s[strcspn(s, "\n")] = '\0';
	}

	return atof(s);
}

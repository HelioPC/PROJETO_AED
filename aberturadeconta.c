#include <string.h>
#include <locale.h>
#define __ALL_TYPES__
#define __CLI_FUNC__
#define __DT_FUNC__
#define __AUX_FUNC__
#define __LL_FUNC__
#define __MN_FUNC__
#define __LS_FUNC__
#define __CLIK_FUNC__
#define __MSG_FUNC__
#include "Declaração.h"

extern int loaded;

void abreConta(void){
	char nome[80], valStr[15], telStr[11];
	DATA dat_nasc, dat_atual=criaData();
	long int tel=0;
	double valor=6894.0;
	int idade;
	char gen;
	char n_conta[15], n_bi[16];
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=======================Abertura De Conta=======================");
	
	/* GET NAME*/
	readname(nome);
	
	/*GET BIRTHDAY*/
	do{
		dat_nasc = readdata(" de nascimento");
		idade = dat_atual.a - dat_nasc.a;
	}while(idade < 18);
	
	/*GET GENRE*/
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu gênero(M/F): ");
		fflush(stdin);
		gen = getchar();
	}
	
	/*GET PHONE NUMBER*/
	do{
		printf("\nIntroduza o seu número de tel.: ");
		fflush(stdin);
		fgets(telStr, 10, stdin);
	}while(!isTel(telStr));
	
	tel = atoi(telStr);
	
	/*GET B.I NUMBER*/
	do{
		printf("\nIntroduza o número do B.I: ");
		fflush(stdin);
		fgets(n_bi, 15, stdin);
	}while(!isBI(n_bi));
	
	/*GET MONEY*/
	if(idade > 11 && idade < 21){
		while(valor < 6895.0){
			do{
				printf("\nIntroduza o valor: ");
				fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}while(!isFloat(valStr));
			
			valor = atof(valStr);
		}
	}
	else if(idade > 20 && idade < 35){
		while(valor < 10000.0){
			do{
				printf("\nIntroduza o valor: ");
				fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}while(!isFloat(valStr));
			
			valor = atof(valStr);
		}
	}else{
		while(valor < 15000.0){
			do{
				printf("\nIntroduza o valor: ");
				fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}while(!isFloat(valStr));
			
			valor = atof(valStr);
		}
	}
	
	sprintf(n_conta, "%s+%ld", BANO, tel);
	
	if(is_CLI_in(n_conta) || is_CLI_in3(n_bi)){
		printf("\n\nA conta %s já foi criada ou o cliente %s já existe!\n\n",
		n_conta, n_bi);
		_pause();
		return;
	}
	
	inserirK(iniCli(nome, dat_nasc, tel, valor, n_bi, n_conta, gen,
	criaData()));
	opsucess();
	loaded = 1;
	_pause();
}

void abreContaKid(CLI *cl){
	char nome[80];
	unsigned short int i;
	DATA d_nasc;
	char ced[11];
	char gen;
	long int tel;
	double val;
	char n_conta[15];
	DATA d=criaData();
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=====================Abertura De Conta Kid=====================");
	
	/* GET NAME*/
	readname(nome);
	
	do{
		d_nasc = readdata(" de nascimento");
		i = d.a - d_nasc.a;
	}while(i > 14);
	
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu gênero(M/F): ");fflush(stdin);
		gen = getchar();
	}
	
	do{
		printf("\nIntroduza o número da cédula: ");fflush(stdin);
		fgets(ced, 10, stdin);
		ced[strcspn(ced, "\n")] = '\0';
	}while(!isCED(ced));
	
	if(is_KID_in(ced)){
		printf("\n\nO número da cédula já está registado.\n\n");
		_pause();
		return;
	}

	tel = cl->tel;
	val = 20000.0;
	cl->valor -= 20000.0;
	
	strcpy(n_conta, cl->n_conta);
	
	inserirF_KID(iniKID(nome, ced, gen, tel, val, n_conta, d_nasc, d, i));
	opsucess();
	loaded = 1;
	_pause();
}

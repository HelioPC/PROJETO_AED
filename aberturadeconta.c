#include <locale.h>
#define __ALL_TYPES__
#define __CLI_FUNC__
#define __DT_FUNC__
#include "Declaração.h"

void abreConta(void){
	char nome[31], data[11], valStr[15], telStr[11];
	DATA dat_nasc, dat_atual=criaData();
	long int tel=0;
	double valor=6894.0;
	int idade;
	char gen;
	char n_conta[15], n_bi[16];
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=======================Abertura De Conta=======================");
	
	printf("\nIntroduza o seu nome: ");fflush(stdin);
	fgets(nome, 80, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	while(!isNome(nome)){
		printf("\nIntroduza o seu nome: ");fflush(stdin);
		fgets(nome, 80, stdin);
		nome[strcspn(nome, "\n")] = '\0';
	}
	
	printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
	fgets(data, 11, stdin);dat_nasc = strToData(data);
	data[strcspn(data, "\n")] = '\0';
	idade = dat_atual.a - dat_nasc.a;
	
	while(idade < 12){
		printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
		fgets(data, 11, stdin);dat_nasc = strToData(data);
		data[strcspn(data, "\n")] = '\0';
		idade = dat_atual.a - dat_nasc.a;
	}
	
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu gênero(M/F): ");fflush(stdin);
		gen = getchar();
	}
	
	printf("\nIntroduza o seu número de tel.: ");fflush(stdin);
	fgets(telStr, 10, stdin);
	
	while(!isTel(telStr)){
		printf("\nIntroduza o seu número de tel.: ");fflush(stdin);
		fgets(telStr, 10, stdin);
	}
	
	tel = atoi(telStr);
	
	printf("\nIntroduza o número do B.I: ");fflush(stdin);
	fgets(n_bi, 15, stdin);
	
	while(!isBI(n_bi)){
		printf("\nIntroduza o número do B.I: ");fflush(stdin);
		fgets(n_bi, 15, stdin);
	}
	
	if(idade > 11 && idade < 21){
		while(valor < 6895.0){
			printf("\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}
	else if(idade > 20 && idade < 35){
		while(valor < 10000.0){
			printf("\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}else{
		while(valor < 15000.0){
			printf("\n\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}
	
	sprintf(n_conta, "%s+%d", BANO, tel);
	
	if(is_CLI_in(n_conta) || is_CLI_in3(n_bi)){
		printf("\n\nA conta %s já foi criada ou o cliente %s já existe!\n\n",
		n_conta, n_bi);
		_pause();
		menuSys();
	}
	
	inserirF(iniCli(nome, dat_nasc, tel, valor, n_bi, n_conta, gen,
	criaData()));
	printf("\n\nAbertura de conta efetuada com sucesso...\n\n");
	_pause();
	menuSys();
}

void abreContaKid(CLI *cl){
	char nome[80];
	unsigned short int i;
	DATA d_nasc;
	char ced[11];
	char gen;
	long int tel;
	double val;
	char n_conta[15], data[11];
	DATA d=criaData();
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=====================Abertura De Conta Kid=====================");
	
	printf("\nIntroduza o seu nome: ");fflush(stdin);
	fgets(nome, 80, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	while(!isNome(nome)){
		printf("\nIntroduza o seu nome: ");fflush(stdin);
		fgets(nome, 80, stdin);
		nome[strcspn(nome, "\n")] = '\0';
	}
	
	printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
	fgets(data, 11, stdin);d_nasc = strToData(data);
	data[strcspn(data, "\n")] = '\0';
	i = d.a - d_nasc.a;
	
	while(i > 11){
		printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
		fgets(data, 11, stdin);d_nasc = strToData(data);
		data[strcspn(data, "\n")] = '\0';
		i = d.a - d_nasc.a;
	}
	
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu gênero(M/F): ");fflush(stdin);
		gen = getchar();
	}
	
	tel = cl->tel;
	val = 20000.0;
	cl->valor -= 20000.0;
	
	printf("\nIntroduza o número da cédula: ");fflush(stdin);
	fgets(ced, 10, stdin);
	ced[strcspn(ced, "\n")] = '\0';
	
	while(!isCED(ced)){
		printf("\nIntroduza o número da cédula: ");fflush(stdin);
		fgets(ced, 10, stdin);
		ced[strcspn(ced, "\n")] = '\0';
	}
	
	if(is_KID_in(ced)){
		printf("\n\nO número da cédula já está registado.\n\n");
		_pause();
		menuCli(cl);
	}
	
	strcpy(n_conta, cl->n_conta);
	
	inserirF_KID(iniKID(nome, ced, gen, tel, val, n_conta, d_nasc, d, i));
	printf("\n\nAbertura de conta efetuada com sucesso...\n\n");
	_pause();
	menuCli(cl);
}
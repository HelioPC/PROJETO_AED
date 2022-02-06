#include <string.h>
#include <unistd.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LDL_FUNC__
#define __LS_FUNC__
#define __CLI_FUNC__
#define __CLIK_FUNC__
#define __DT_FUNC__
#define __HST_FUNC__
#define __MN_FUNC__
#define __MSG_FUNC__
#define __AUX_FUNC__
#define __COLORS__
#include "Declaração.h"

extern LISTACLI *LCL;
extern LISTAHIST *LHS;
extern LISTA_KID *LKD;

void menu(void){
	char n_conta[15];
	
	while(1){
		system(limpa);
		puts(YELLOW_A);
		printf("=======================BANCO BANO=======================");
		puts(NORM);
		printf("\n\t1- Cliente\n\t2- Sistema\n\t3- Salvar\n\t4- Carregar\n\t5"
		"- Sair\n");
		puts(YELLOW_A);
		printf("========================================================\n");

		switch(getOption(1, 5)){
			case 1:
				system(limpa);
				
				readaccount(n_conta);

				if(is_CLI_in(n_conta)){
					menuCli(getCLI(n_conta));
				}else{
					printf("\nNº de conta não está associado a nenhuma conta.\n\n");
				}
				break;

			case 2:
				menuSys();
				break;
			
			case 3:
				save();
				break;
			
			case 4:
				load();
				break;

			default: goodbye(); exit(0);
		}
	}
}

void menuCli(CLI *cl){
	unsigned short int i;
	char ced[11];
	double val=0.0;
	CONTA_KID *k;
	char n_conta[15];
	
	while(1){
		system(limpa);
		puts(YELLOW_A);
		printf("==================BANCO BANO (Cliente)==================");
		puts(NORM);
		printf("\n\t1- Transferir\n\t2- Depositar\n\t3- Consultar");
		printf("\n\t4- Levantar\n\t5- Depositar Em Kid");
		printf("\n\t6- Criar Conta Em Kid\n\t7- Histórico De Operações");
		printf("\n\t8- Voltar\n");
		puts(YELLOW_A);
		printf("========================================================\n");

		switch(getOption(1, 8)){
			case 7:
				menuHist(cl);
				break;

			case 6:
				if(cl->valor < 150001.0){
					printf("\nSaldo insuficiente na conta para a abertura!");
					printf("\nFaça mais depósitos!\n\n");
					pressEnter();
					break;
				}
				abreContaKid(cl);
				break;

			case 5:
				if(qtKID(cl) == 1){
					for(i=0; i<LKD->qt; i++){
						if(LKD->kid[i].tel == cl->tel) k = &LKD->kid[i];
					}
					
					val = getvalue();
					
					while(val >= cl->valor) val = getvalue();
					
					if(depositarKID(cl, k->n_ced, val)){
						opsucess();
					}else{
						opsucess();
					}
					pressEnter();
					break;
				}else if(qtKID(cl) > 1){
					do{
						printf("\nIntroduza o número da cédula: ");
						fgets(ced, 10, stdin);
						fflush(stdin);
						ced[strcspn(ced, "\n")] = '\0';
					}while(!isCED(ced) || !is_KID_in(ced));
					
					k = getKID(ced);

					val = getvalue();
					
					while(val >= cl->valor) val = getvalue();
					
					if(depositarKID(cl, k->n_ced, val)){
						opsucess();
					}else{
						opsucess();
					}
					pressEnter();
					break;
				}else{
					printf("\nSem conta Kid.\n");
					pressEnter();
					break;
				}

			case 4:
				val = getvalue();
					
				while(val < 1) val = getvalue();
				
				if(levantar(cl, val)){
					opsucess();
				}else{
					opsucess();
				}
				
				pressEnter();
				break;

			case 3:
				consultar(cl);
				pressEnter();
				break;

			case 2:
				val = getvalue();
					
				while(val < 1) val = getvalue();
				
				if(depositar(cl, val)){
					opsucess();
				}else{
					opsucess();
				}
				
				pressEnter();
				break;

			case 1:
				readaccount(n_conta);
				
				if(is_CLI_in(n_conta)){
					val = getvalue();
					
					while(val < 1) val = getvalue();
					
					if(transferir(cl, val, n_conta)){
						opsucess();
						pressEnter();
						break;
					}else{
						opsucess();
						pressEnter();
						break;
					}
				}else{
					printf("\nNº de conta não está associado a nenhuma conta.\n\n");
					pressEnter();
					break;
				}

			default: getout(); return;
		}
	}
}

void menuSys(void){
	unsigned short int n, x=0, y=0;
	char str[15];
	double v;
	DATA d, d2;
	
	while(1){
		system(limpa);
		puts(YELLOW_A);
		printf("=====================BANCO BANO (Sistema)=====================");
		puts(NORM);
		printf("\n\t1- Registar Cliente.\n");
		printf("\t2- Ver a quantidade de Contas existentes.\n");
		printf("\t3- Ver a quantidade de contas kids existentes.\n");
		printf("\t4- Listar os clientes com mais de n contas kids.\n");
		printf("\t5- Lista um ranking dos clientes mais activos no banco.\n");
		printf("\t6- Listar as informações dos Clientes.\n");
		printf("\t7- Listar a informação de um determinado Cliente.\n");
		printf("\t8- Listar o histórico e os dados de um determinado Cliente.\n");
		printf("\t9- Listar todos os clientes que criaram contas numa data.\n");
		printf("\t10- Listar todos os clientes com idades entre x-y.\n");
		printf("\t11- Debitar 1.5%% do valor de todas as contas.\n");
		printf("\t12- Desativar conta de um cliente.\n");
		printf("\t13- Verificar se existe conta com saldo menor que n.\n");
		printf("\t14- Listar os Clientes em ordem alfabética.\n");
		printf("\t15- Listar as informações dos Clientes Kid.\n");
		printf("\t16- Voltar\n");
		puts(YELLOW_A);
		printf("=============================================================\n");
		
		switch(getOption(1, 16)){
			case 1:
				abreConta();
				break;

			case 2:
				printf("\nExistem %d %s.\n\n", tam(), tam()<2?"conta":"contas");
				pressEnter();
				break;

			case 3:
				printf("\nExistem %d %s.\n", tam_KID(), tam_KID()<2?"conta":"contas");
				putchar('\n');
				pressEnter();
				break;

			case 4:
				if(vazia_KID()){
					printf("\nNão existem contas kids registadas no sistema.\n");
					pressEnter();
					break;
				}
				
				if(vazia()){
					printf("\nNão existem clientes registados no sistema.\n");
					pressEnter();
					break;
				}
				
				printf("\nIntroduza o n: ");
				scanf("%hu", &n);
				fflush(stdin);
				while(n > MAX-1 || n < 1){
					printf("\nValor de n é inválido!\n");
					printf("\nIntroduza o n: ");
					scanf("%hu", &n);
					fflush(stdin);
				}
				cli_n_KID(n);
				pressEnter();
				break;

			case 5:
				rank_mais_act();
				break;

			case 6:
				system(limpa);
				mostraCLI();
				break;

			case 7:
				readaccount(str);
				
				if(is_CLI_in(str)){
					_mostraCLI(getCLI(str));
					pressEnter();
					break;
				}else{
					printf("\nNº de conta não está associado a nenhuma conta.\n\n");
					pressEnter();
					break;
				}

			case 8:
				readaccount(str);
				
				if(is_CLI_in(str)){
					mostraHIST_by_CLI(str);
					break;
				}else{
					printf("\nNº de conta não está associado a nenhuma conta.\n\n");
					pressEnter();
					break;
				}

			case 9:
				d2 = criaData();

				d = readdata("");
				
				while(d.a > d2.a) d = readdata("");
				
				mostraCLI_by_DATA(d);
				pressEnter();
				break;

			case 10:
				system(limpa);
				while(x<12 && y<12 && x >= y){
					printf("\nIntroduza o 1º intervalo: ");
					scanf("%hu", &x);
					fflush(stdin);

					printf("\nIntroduza o 2º intervalo: ");				
					scanf("%hu", &y);
					fflush(stdin);
				}
				
				mostraCLI_idade(x, y);
				pressEnter();
				break;

			case 11:
				debitar_ALL();
				break;

			case 12:
				system(limpa);

				readaccount(str);

				if(is_CLI_in(str)){
					printf("\n\nA conta %s será eliminada!\n\n", str);

					pressEnter();

					if(qtKID(getCLI(str)) > 0){
						rmKID(str);
					}

					if(removeK(str)){
						opsucess();
					}else{
						printf("\nOcorreu um erro inesperado.\n\n");
					}
					
					pressEnter();
					break;
				}else{
					printf("\nNº de conta não está associado a nenhuma conta.\n\n");
					pressEnter();
					break;
				}

			case 13:
				if(*LCL == NULL){
					printf("\n\nNão existem contas no sistema.\n\n");
					pressEnter();
					break;
				}
				
				v = getvalue();
				
				while(v < 0) v = getvalue();
				
				if(valor_menor_n(v) > 0){
					printf("\nExistem %d contas.\n\n", valor_menor_n(v));
					pressEnter();
					break;
				}else{
					printf("\nNão existem contas com menos de %.2lf kz.\n\n", v);
					pressEnter();
					break;
				}

			case 14:
				mostraCLI();
				break;

			case 15:
				system(limpa);
				mostraKID();
				break;

			default: getout(); return;
		}
	}
}

void menuHist(CLI *cl){
	while(1){
		system(limpa);
		puts(YELLOW_A);
		printf("====================BANCO BANO (Histórico)====================");
		puts(NORM);
		printf("\n\t1- Quantidade de processos.");
		printf("\n\t2- Relatório de operações em um dada data.");
		printf("\n\t3- Histórico por tipo de operação.");
		printf("\n\t4- Voltar.");
		puts(YELLOW_A);
		printf("\n========================================================\n");
		
		switch(getOption(1, 4)){
			case 1:
				printf("\nExistem %d %s na conta.\n", qtHIST(cl),
				qtHIST(cl)==1 ? "processo" : "processos");
				
				pressEnter();
				break;

			case 2:
				mostraHIST_by_DATA(readdata(""), cl);
				break;

			case 3:
				mostraHIST_by_OP(cl);
				break;

			default: getout(); return;
		}
	}
}

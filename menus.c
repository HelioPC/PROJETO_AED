#include <stdio_ext.h>
#include <string.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LDL_FUNC__
#define __LS_FUNC__
#define __CLI_FUNC__
#define __CLIK_FUNC__
#define __DT_FUNC__
#define __HST_FUNC__
#define __MN_FUNC__
#define __AUX_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;
extern LISTAHIST *LHS;
extern LISTA_KID *LKD;

void menu(void){
	unsigned short int opc = 0;
	char n_conta[15];
	
	while(1){
		system(limpa);
		printf("=======================BANCO BANO=======================");
		printf("\n\t1- Cliente\n\t2- Sistema\n\t3- Sair\n");
		printf("========================================================\n");
		
		while(opc<1 || opc>3){
			printf("\nEscolha uma opção: ");
			
			scanf("%hu", &opc);
			__fpurge(stdin);
		}
		
		if(opc == 1){
			system(limpa);
			printf("Introduza o número da conta: ");
			fgets(n_conta, 15, stdin);
			__fpurge(stdin);
			n_conta[strcspn(n_conta, "\n")] = '\0';
	
			while(n_conta[0] != 'B'){
				printf("Conta inválida!");
				printf("\nIntroduza o número da conta: ");
				fgets(n_conta, 15, stdin);
				__fpurge(stdin);
				n_conta[strcspn(n_conta, "\n")] = '\0';
			}

			if(is_CLI_in(n_conta)){
				menuCli(getCLI(n_conta));
			}else{
				printf("\nNº de conta não está associado a nenhuma conta.\n\n");
			}
			_pause();
			opc = 0;
		}
		else if(opc == 2){
			menuSys();
			opc = 0;
		}else{
			exit(0);
		}
	}
}

void menuCli(CLI *cl){
	unsigned short int opc = 0, i;
	char ced[11];
	double val=0.0;
	char valStr[15];
	CONTA_KID *k;
	char n_conta[15];
	
	while(1){
		system(limpa);
		printf("==================BANCO BANO (Cliente)==================");
		printf("\n\t1- Transferir\n\t2- Depositar\n\t3- Consultar");
		printf("\n\t4- Levantar\n\t5- Depositar Em Kid");
		printf("\n\t6- Criar Conta Em Kid\n\t7- Histórico De Operações");
		printf("\n\t8- Voltar\n");
		printf("========================================================\n");

		while(opc<1 || opc>8){
			printf("\nEscolha uma opção: ");
			
			scanf("%hu", &opc);
			__fpurge(stdin);
		}

		if(opc == 7){
			menuHist(cl);
		}
		else if(opc == 6){
			if(cl->valor < 150001.0){
				printf("\nSaldo insuficiente na conta para a abertura!");
				printf("\nFaça mais depósitos!\n\n");
				_pause();
				continue;
			}
			abreContaKid(cl);
		}
		else if(opc == 5){
			if(qtKID(cl) == 1){
				for(i=0; i<LKD->qt; i++){
					if(LKD->kid[i].tel == cl->tel) k = &LKD->kid[i];
				}
				
				printf("\nIntroduza o valor a depositar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\nIntroduza o valor a depositar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
				
				while(val >= cl->valor){
					printf("\nIntroduza o valor a depositar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
					
					while(!isFloat(valStr)){
						printf("\nIntroduza o valor a depositar: ");
						fgets(valStr, 14, stdin);
						__fpurge(stdin);
						valStr[strcspn(valStr, "\n")] = '\0';
					}
					
					val = atof(valStr);
				}
				
				if(depositarKID(cl, k->n_ced, val)){
					printf("\n\nDepósito na conta kid efetuada com sucesso.\n\n");
				}else{
					printf("\n\nDepósito na conta kid efetuada com sucesso.\n\n");
				}
				_pause();
				continue;
			}else if(qtKID(cl) > 1){
				printf("\nIntroduza o número da cédula: ");
				fgets(ced, 10, stdin);
				__fpurge(stdin);
				ced[strcspn(ced, "\n")] = '\0';

				while(!isCED(ced)){
					printf("\nIntroduza o número da cédula: ");
					fgets(ced, 10, stdin);
					__fpurge(stdin);
					ced[strcspn(ced, "\n")] = '\0';
				}
				
				while(!is_KID_in(ced)){
					printf("\nIntroduza o número da cédula: ");
					fgets(ced, 10, stdin);
					__fpurge(stdin);
					ced[strcspn(ced, "\n")] = '\0';
					
					while(!isCED(ced)){
						printf("\nIntroduza o número da cédula: ");
						fgets(ced, 10, stdin);
						__fpurge(stdin);
						ced[strcspn(ced, "\n")] = '\0';
					}
				}
				
				k = getKID(ced);
				printf("\nIntroduza o valor a depositar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\nIntroduza o valor a depositar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
				
				while(val >= cl->valor){
					printf("\nIntroduza o valor a depositar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
					
					while(!isFloat(valStr)){
						printf("\nIntroduza o valor a depositar: ");
						fgets(valStr, 14, stdin);
						__fpurge(stdin);
						valStr[strcspn(valStr, "\n")] = '\0';
					}
					
					val = atof(valStr);
				}
				
				if(depositarKID(cl, k->n_ced, val)){
					printf("\n\nDepósito na conta kid efetuada com sucesso.\n\n");
				}else{
					printf("\n\nDepósito não foi efetuado com sucesso.\n\n");
				}
				_pause();
				continue;
			}else{
				printf("\nSem conta Kid.\n");
				_pause();
				continue;
			}
		}
		else if(opc == 4){
			printf("\n\nIntroduza o valor a levantar: ");
			fgets(valStr, 14, stdin);
			__fpurge(stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor a levantar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
			
			while(val < 1){
				printf("\n\nIntroduza o valor a levantar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\n\nIntroduza o valor a levantar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
			}
			
			if(levantar(cl, val)){
				printf("\n\nLevantamento efetuado com sucesso...\n\n");
			}else{
				printf("\n\nLevantamento não foi efetuado com sucesso...\n\n");
			}
			
			_pause();
			continue;
		}
		else if(opc == 3){
			consultar(cl);
			_pause();
			continue;
		}
		else if(opc == 2){
			printf("\n\nIntroduza o valor a depositar: ");
			fgets(valStr, 14, stdin);
			__fpurge(stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor a depositar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
			
			while(val < 1){
				printf("\n\nIntroduza o valor a depositar: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\n\nIntroduza o valor a depositar: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
			}
			
			if(depositar(cl, val)){
				printf("\n\nDepósito efetuado com sucesso...\n\n");
			}else{
				printf("\n\nDepósito não foi efetuado com sucesso...\n\n");
			}
			
			_pause();
			continue;
		}
		else if(opc == 1){
			printf("\nIntroduza o número da conta: ");
			fgets(n_conta, 15, stdin);
			__fpurge(stdin);
			n_conta[strcspn(n_conta, "\n")] = '\0';
			while(n_conta[0] != 'B'){
				printf("Conta inválida!");
				printf("\nIntroduza o número da conta: ");
				fgets(n_conta, 15, stdin);
				__fpurge(stdin);
				n_conta[strcspn(n_conta, "\n")] = '\0';
			}
			
			if(is_CLI_in(n_conta)){
				printf("\n\nIntroduza o valor a transferir: ");
				fgets(valStr, 14, stdin);
				__fpurge(stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\n\nIntroduza o valor a transferir: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
				
				while(val < 1){
					printf("\n\nIntroduza o valor a transferir: ");
					fgets(valStr, 14, stdin);
					__fpurge(stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
					
					while(!isFloat(valStr)){
						printf("\n\nIntroduza o valor a transferir: ");
						fgets(valStr, 14, stdin);
						__fpurge(stdin);
						valStr[strcspn(valStr, "\n")] = '\0';
					}
					
					val = atof(valStr);
				}
				
				if(transferir(cl, val, n_conta)){
					printf("\nTransferência efetuada com sucesso...\n\n");
					_pause();
					continue;
				}else{
					printf("\nTransferência não foi efetuada com sucesso...\n\n");
					_pause();
					continue;
				}
			}else{
				printf("\nNº de conta não está associado a nenhuma conta.\n\n");
				_pause();
				continue;
			}
		}
		else{
			return;
		}
	}
}

void menuSys(void){
	unsigned short int opc = 0, n, x=0, y=0;
	char str[15], vStr[15];
	double v;
	DATA d, d2;
	
	while(1){
		system(limpa);
		printf("=====================BANCO BANO (Sistema)=====================");
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
		printf("=============================================================\n");
		
		while(opc<1 || opc>16){
			printf("\nEscolha uma opção: ");
			
			scanf("%hu", &opc);
			__fpurge(stdin);
		}
		
		if(opc == 1){
			abreConta();
			opc = 0;
			continue;
		}
		else if(opc == 2){
			printf("\nExistem %d %s.\n\n", tam(), tam()<2?"conta":"contas");
			_pause();
			opc = 0;
			continue;
		}
		else if(opc == 3){
			printf("\nExistem %d %s.\n", tam_KID(), tam_KID()<2?"conta":"contas");
			putchar('\n');
			_pause();
			opc = 0;
			continue;
		}
		else if(opc == 4){
			if(vazia_KID()){
				printf("\nNão existem contas kids registadas no sistema.\n");
				_pause();
				opc = 0;
				continue;
			}
			
			if(vazia()){
				printf("\nNão existem clientes registados no sistema.\n");
				_pause();
				opc = 0;
				continue;
			}
			
			printf("\nIntroduza o n: ");
			scanf("%hu", &n);
			__fpurge(stdin);
			while(n > MAX-1 || n < 1){
				printf("\nValor de n é inválido!\n");
				printf("\nIntroduza o n: ");
				scanf("%hu", &n);
				__fpurge(stdin);
			}
			cli_n_KID(n);
			_pause();
			opc = 0;
			continue;
		}
		else if(opc == 5){
			rank_mais_act();
			opc = 0;
			continue;
		}
		else if(opc == 6){
			system(limpa);
			mostraCLI();
			opc = 0;
			continue;
		}
		else if(opc == 7){
			printf("\nIntroduza o número da conta: ");
			fgets(str, 15, stdin);
			__fpurge(stdin);
			str[strcspn(str, "\n")] = '\0';
			while(str[0] != 'B'){
				printf("Conta inválida!");
				printf("\nIntroduza o número da conta: ");
				fgets(str, 15, stdin);
				__fpurge(stdin);
				str[strcspn(str, "\n")] = '\0';
			}
			
			if(is_CLI_in(str)){
				_mostraCLI(getCLI(str));
				_pause();
				opc = 0;
				continue;
			}else{
				printf("\nNº de conta não está associado a nenhuma conta.\n\n");
				_pause();
				opc = 0;
				continue;
			}
		}
		else if(opc == 8){
			printf("\nIntroduza o número da conta: ");
			fgets(str, 15, stdin);
			__fpurge(stdin);
			str[strcspn(str, "\n")] = '\0';
			while(str[0] != 'B'){
				printf("Conta inválida!");
				printf("\nIntroduza o número da conta: ");
				fgets(str, 15, stdin);
				__fpurge(stdin);
				str[strcspn(str, "\n")] = '\0';
			}
			
			if(is_CLI_in(str)){
				mostraHIST_by_CLI(str);
				opc = 0;
				continue;
			}else{
				printf("\nNº de conta não está associado a nenhuma conta.\n\n");
				_pause();
				opc = 0;
				continue;
			}
		}
		else if(opc == 9){
			d2 = criaData();
			printf("\nIntroduza a data de criação da conta: ");
			fgets(str, 11, stdin);d = strToData(str);
			__fpurge(stdin);
			str[strcspn(str, "\n")] = '\0';
			
			while(d.a > d2.a){
				printf("\nIntroduza a data de criação da conta: ");
				fgets(str, 11, stdin);d = strToData(str);
				__fpurge(stdin);
				str[strcspn(str, "\n")] = '\0';
			}
			
			mostraCLI_by_DATA(d);
			_pause();
			opc = 0;
			continue;
		}
		else if(opc == 10){
			system(limpa);
			while(x<12 && y<12 && x >= y){
				printf("\nIntroduza o 1º intervalo: ");
				scanf("%hu", &x);
				__fpurge(stdin);

				printf("\nIntroduza o 2º intervalo: ");				
				scanf("%hu", &y);
				__fpurge(stdin);
			}
			
			mostraCLI_idade(x, y);
			_pause();
			opc = 0;
			continue;
		}
		else if(opc == 11){
			debitar_ALL();
			opc = 0;
			continue;
		}
		else if(opc == 12){
			system(limpa);
			printf("\nIntroduza o número da conta: ");
			fgets(str, 15, stdin);
			__fpurge(stdin);
			str[strcspn(str, "\n")] = '\0';
			while(str[0] != 'B'){
				printf("Conta inválida!");
				printf("\nIntroduza o número da conta: ");
				fgets(str, 15, stdin);
				__fpurge(stdin);
				str[strcspn(str, "\n")] = '\0';
			}
			
			if(is_CLI_in(str)){
				printf("\n\nA conta %s será eliminada!\n\n", str);
				_pause();
				if(qtKID(getCLI(str)) > 0){
					rmKID(str);
					opc = 0;
					continue;
				}
				if(removeK(str)){
					printf("\n\nConta removida com sucesso.\n\n");
				}else{
					printf("\nOcorreu um erro inesperado.\n\n");
				}
				_pause();
				opc = 0;
				continue;
			}else{
				printf("\nNº de conta não está associado a nenhuma conta.\n\n");
				_pause();
				opc = 0;
				continue;
			}
		}
		else if(opc == 13){
			if(*LCL == NULL){
				printf("\n\nNão existem contas no sistema.\n\n");
				_pause();
				opc = 0;
				continue;
			}
			
			printf("\n\nIntroduza o valor: ");
			fgets(vStr, 14, stdin);
			__fpurge(stdin);
			vStr[strcspn(vStr, "\n")] = '\0';
			
			while(!isFloat(vStr)){
				printf("\n\nIntroduza o valor: ");
				fgets(vStr, 14, stdin);
				__fpurge(stdin);
				vStr[strcspn(vStr, "\n")] = '\0';
			}
			
			v = atof(vStr);
			
			while(v < 0){
				printf("\n\nIntroduza o valor: ");
				fgets(vStr, 14, stdin);
				__fpurge(stdin);
				vStr[strcspn(vStr, "\n")] = '\0';
				
				while(!isFloat(vStr)){
					printf("\n\nIntroduza o valor: ");
					fgets(vStr, 14, stdin);
					__fpurge(stdin);
					vStr[strcspn(vStr, "\n")] = '\0';
				}
				
				v = atof(vStr);
			}
			
			if(valor_menor_n(v) > 0){
				printf("\nExistem %d contas.\n\n", valor_menor_n(v));
				_pause();
				opc = 0;
				continue;
			}else{
				printf("\nNão existem contas com menos de %.2lf kz.\n\n", v);
				_pause();
				opc = 0;
				continue;
			}
		}
		else if(opc == 14){
			mostraCLI();
			opc = 0;
			continue;
		}
		else if(opc == 15){
			system(limpa);
			mostraKID();
			opc = 0;
			continue;
		}
		else break;
	}
}

void menuHist(CLI *cl){
	unsigned short int opc;
	char str[11];
	DATA d;
	
	while(1){
		system(limpa);
		printf("====================BANCO BANO (Histórico)====================");
		printf("\n\t1- Quantidade de processos.");
		printf("\n\t2- Relatório de operações em um dada data.");
		printf("\n\t3- Histórico por tipo de operação.");
		printf("\n\t4- Voltar.");
		printf("\n========================================================\n");
		
		while(opc<1 || opc>4){
			printf("\nEscolha uma opção: ");
			
			scanf("%hu", &opc);
			__fpurge(stdin);
		}
		
		if(opc == 1){
			printf("\nExistem %d %s na conta.\n", qtHIST(cl),
			qtHIST(cl)==1 ? "processo" : "processos");
			
			_pause();
			continue;
		}
		else if(opc == 2){
			printf("\nIntroduza a data: ");
			fgets(str, 11, stdin);d = strToData(str);
			__fpurge(stdin);
			str[strcspn(str, "\n")] = '\0';
			
			while(!isData(d)){
				printf("\nIntroduza a data: ");
				fgets(str, 11, stdin);d = strToData(str);
				__fpurge(stdin);
				str[strcspn(str, "\n")] = '\0';
			}
			
			mostraHIST_by_DATA(d, cl);
		}
		else if(opc == 3){
			mostraHIST_by_OP(cl);
		}else{
			_pause();
			return;
		}
	}
}
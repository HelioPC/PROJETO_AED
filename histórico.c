#define __ALL_TYPES__
#define __CLIK_FUNC__
#define __DT_FUNC__
#include "Declaração.h"

extern LISTAHIST *LHS;

void mostraHIST_by_DATA(DATA d, CLI *cl){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		menuHist(cl);
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		equalsDATA(d, aux->h.data)){
			printf("Número da conta: %s\n", cl->n_conta);
			printf("Data da operação:");mostraData(d);
			printf("Tipo de operação: %s\n", aux->h.tipo);
			printf("=====================================================\n");
		}
	}
	
	_pause();
	menuHist(cl);
}

void mostraHIST_by_OP(CLI *cl){
	NOHIST *aux = *LHS;
	char op[14];
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		menuHist(cl);
	}
	
	system(limpa);
	printf("Introduza o tipo de operação: ");fflush(stdin);
	fgets(op, 14, stdin);
	op[strcspn(op, "\n")] = '\0';
	
	while(op[0] != 'T' && op[0] != 'L' && op[0] != 'D' && op[0] != 'C'){
		printf("Introduza o tipo de operação: ");fflush(stdin);
		fgets(op, 14, stdin);
		op[strcspn(op, "\n")] = '\0';
	}
	
	switch(op[0]){
		case 'T':
			if(strcmp(op, "Transferência") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				menuHist(cl);
			}break;
		case 'D':
			if(strcmp(op, "Depósito") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				menuHist(cl);
			}break;
		case 'L':
			if(strcmp(op, "Levantamento") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				menuHist(cl);
			}break;
		case 'C':
			if(strcmp(op, "Consulta") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				menuHist(cl);
			}break;
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		strstr(aux->h.tipo, op) != NULL){
			printf("Número da conta: %s\n", cl->n_conta);
			printf("Data da operação:");mostraData(aux->h.data);
			printf("Tipo de operação: %s\n", aux->h.tipo);
			printf("=====================================================\n");
		}
	}
	
	_pause();
	menuHist(cl);
}
#include <string.h>
#define __ALL_TYPES__
#define __LDL_FUNC__
#define __HST_FUNC__
#define __DT_FUNC__
#define __COLORS__
#include "Declaração.h"

extern LISTAHIST *LHS;

void mostraHIST_by_DATA(DATA d, CLI *cl){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		return;
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		equalsDATA(d, aux->h.data)){
			printhst(aux->h);
		}
	}
	
	_pause();
	return;
}

void mostraHIST_by_OP(CLI *cl){
	NOHIST *aux = *LHS;
	char op[14];
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		return;
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
				return;
			}break;
		case 'D':
			if(strcmp(op, "Depósito") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				return;
			}break;
		case 'L':
			if(strcmp(op, "Levantamento") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				return;
			}break;
		case 'C':
			if(strcmp(op, "Consulta") != 0){
				printf("\nParâmetro inválido.\n");
				_pause();
				return;
			}break;
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		strstr(aux->h.tipo, op) != NULL){
			printhst(aux->h);
		}
	}
	
	_pause();
	return;
}

void mostraHIST_by_CLI(char *n_conta){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		return;
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(n_conta, aux->h.n_conta) == 0){
			printhst(aux->h);
		}
	}

	_pause();
}

void printhst(HIST h){
	printf("Número da conta: %s\n", h.n_conta);
	printf("Data da operação:");mostraData(h.data);
	printf("Tipo de operação: %s\n", h.tipo);
	#ifdef __unix__
		puts(YELLOW_A);
	#endif
	printf("===================================================\n\n");
	#ifdef __unix__
		puts(NORM);
	#endif
}

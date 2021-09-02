#include <string.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;

void iniLCLI(){
	LCL = (LISTACLI *) malloc(sizeof(LISTACLI));
	
	if(LCL != NULL) *LCL = NULL;
}

int tam(){
	int cont = 0;
	NOCli *no = *LCL;
	
	if(LCL == NULL) return 0;
	
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	
	return cont;
}

int vazia(){
	if(LCL == NULL) return 1;
	if(*LCL == NULL) return 1;
	
	return 0;
}

int inserirK(CLI cli, int k){
	NOCli *no = (NOCli *) malloc(sizeof(NOCli));
	NOCli *aux;

    if(no == NULL) return 0;

    aux = *LCL;

    while(aux != NULL && strcmp(no->cliente.nome, aux->cliente.nome) > 0){
        aux = aux->prox;
    }

    if(aux != NULL) return 0;

    no->prox = aux;
    aux = no;
	
	return 1;
}

int removeK(char *n_conta){
	NOCli *ant, *no = *LCL;
	
	if(LCL == NULL) return 0;
	if(*LCL == NULL) return 0;
	
	while(no != NULL && strcmp(no->cliente.n_conta, n_conta) != 0){
		ant = no;
		no = no->prox;
	}
	
	if(no == NULL) return 0;
	
	if(no == *LCL){
		*LCL = no->prox;
	}else{
		ant->prox = no->prox;
	}
	free(no);
	
	return 1;
}

int is_CLI_in(char *n_conta){
	NOCli *no;
	if(vazia()) return 0;
	
	no = *LCL;
	
	while(no->prox != NULL){
		if(strcmp(n_conta, no->cliente.n_conta) == 0) return 1;
		no = no->prox;
	}
	
	if(strcmp(n_conta, no->cliente.n_conta) == 0) return 1;
	
	return 0;
}

int is_CLI_in2(LISTACLI *lc, CLI cli){
	NOCli *no;
	if(*lc == NULL) return 0;
	
	no = *lc;
	
	while(no->prox != NULL){
		if(strcmp(cli.n_conta, no->cliente.n_conta) == 0) return 1;
		no = no->prox;
	}
	
	if(strcmp(cli.n_conta, no->cliente.n_conta) == 0) return 1;
	
	return 0;
}

int is_CLI_in3(char *n_bi){
	NOCli *no;
	if(vazia()) return 0;
	
	no = *LCL;
	
	while(no->prox != NULL){
		if(strcmp(n_bi, no->cliente.n_bi) == 0) return 1;
		no = no->prox;
	}
	
	if(strcmp(n_bi, no->cliente.n_bi) == 0) return 1;
	
	return 0;
}

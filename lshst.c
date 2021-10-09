#include <string.h>
#define __ALL_TYPES__
#define __LDL_FUNC__
#include "Declaração.h"

extern LISTAHIST *LHS;

void iniLHIST(void){
	LHS = (LISTAHIST *) malloc(sizeof(LISTAHIST));

	if(LHS != NULL) *LHS = NULL;
}

int tamLH(void){
	NOHIST *noh = *LHS;
	int cont=0;

	if(LHS == NULL) return 0;

	for(; noh!=NULL; noh=noh->prox) cont++;

	return cont;
}

int vaziaLH(void){
	if(LHS == NULL || *LHS == NULL) return 1;
	
	return 0;
}

int inserirF_LH(HIST h){
	NOHIST *aux, *noh = (NOHIST *) malloc(sizeof(NOHIST));
	
	if(LHS == NULL || noh == NULL) return 0;
	
	aux = *LHS;

	noh->h = h;
	noh->prox = NULL;

	if(*LHS == NULL){
		noh->ant = NULL;
		*LHS = noh;
	}else{
		while(aux->prox != NULL) aux = aux->prox;

		noh->ant = aux;
		aux->prox = noh;
	}
	
	return 1;
}

int qtHIST(CLI *cl){
	NOHIST *aux = *LHS;
	int qt=0;
	
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0) qt++;
	}
	
	return qt;
}

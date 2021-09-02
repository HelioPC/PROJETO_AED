#include <string.h>
#define __ALL_TYPES__
#define __LDL_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;
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
	NOHIST *noh = (NOHIST *) malloc(sizeof(NOHIST));
	NOHIST *aux = *LHS;
	
	if(LHS == NULL) return 0;
	
	noh->h = h;
	noh->prox = NULL;
	
	if(*LHS == NULL){
		noh->ant = NULL;
		*LHS = noh;
	}else{
		for(; aux->prox != NULL; aux=aux->prox);
		
		noh->ant = aux;
		aux->prox = noh;
	}
	
	return 1;
}

int qtHIST(CLI *cl){
	NOHIST *aux = *LHS;
	int qt=0;
	
	for(; aux->prox != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0) qt++;
	}
	
	return qt;
}

void rank_mais_act(){
	NOCli *noc = *LCL;
	NOHIST *noh = NULL;
	CLI lcli[MAX], aux;
	int i, j, a;
	
	if(*LCL == NULL || *LHS == NULL){
		printf("\nNada para mostrar.\n");
		_pause();
		menuSys();
	}
	
	if(tam() == 1){
		_mostraCLI(&noc->cliente);
		_pause();
		menuSys();
	}
	
	if(tamLH() == 1){
		noh = *LHS;
		_mostraCLI(getCLI(noh->h.n_conta));
		_pause();
		menuSys();
	}
	
	for(a=0; noc != NULL; noc=noc->prox){
		if(qtHIST(&noc->cliente)){
			lcli[a++] = noc->cliente;
		}
	}
	
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(qtHIST(&lcli[i]) > qtHIST(&lcli[j])){
				aux = lcli[j];
				lcli[j] = lcli[i];
				lcli[i] = aux;
			}
		}
	}
	
	system(limpa);
	for(i=0; i<a; i++){
		_mostraCLI(&lcli[i]);
	}
	
	_pause();
	menuSys();
}

void mostraHIST_by_CLI(char *n_conta){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL || qtHIST(getCLI(n_conta))){
		printf("\nNenhum processo para mostrar.\n");
		_pause();
		menuSys();
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(n_conta, aux->h.n_conta) == 0){
			printf("Número da conta: %s\n", n_conta);
			printf("Data da operação:");mostraData(aux->h.data);
			printf("Tipo de operação: %s\n", aux->h.tipo);
			printf("===================================================\n\n");
		}
	}
	
	_mostraCLI(getCLI(n_conta));
	_pause();
	menuSys();
}

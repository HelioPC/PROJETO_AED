#include <string.h>
#include <locale.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LS_FUNC__
#define __CLI_FUNC__
#define __DT_FUNC__
#define __MN_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;
extern LISTA_KID *LKD;

CLI iniCli(char *nome, DATA nasc, long int tel, double val, char *bi,
	char *n_cont, char gen, DATA d){
	CLI cliente;
	
	strcpy(cliente.nome, nome);
	cliente.dat_nasc = nasc;
	cliente.tel = tel;
	cliente.valor = val;
	strcpy(cliente.n_bi, bi);
	cliente.gen = gen;
	cliente.d = d;
	strcpy(cliente.n_conta, n_cont);
	
	return cliente;
}

CLI *getCLI(char *n_conta){
	NOCli *no;
	if(LCL == NULL || LCL == NULL) return NULL;
	
	no = *LCL;
	
	while(no != NULL){
		if(strcmp(n_conta, no->cliente.n_conta) == 0) return &no->cliente;
		
		no = no->prox;
	}
	
	return NULL;
}

void mostraCLI(){
	NOCli *aux = *LCL;
	
	setlocale(LC_ALL, "Portuguese");
	if(LCL == NULL || *LCL == NULL){
		printf("\nNada para mostrar.\n");
		_pause();
		return;
	}
	
	for(; aux != NULL; aux = aux->prox) _mostraCLI(&aux->cliente);

    _pause();
}

void _mostraCLI(CLI *cl){
	printf("===========================================================\n\n");
	printf("Nome do cliente: %s\n", cl->nome);
	printf("Data de nascimento do cliente:");
	mostraData(cl->dat_nasc);
	printf("Número de telefone do cliente: %ld\n", cl->tel);
	printf("Valor na conta do cliente: %.2lf kz.\n", cl->valor);
	printf("Nº do B.I do cliente: %s\n", cl->n_bi);
	switch(cl->gen){
		case 'M': printf("Gênero: Masculino\n");break;
		case 'F': printf("Gênero: Femenino\n");break;
	}
	printf("Número da conta do cliente: %s\n", cl->n_conta);
	printf("===========================================================\n\n");
}

void mostraCLI_by_DATA(DATA d){
	NOCli *noc;
	
	if(LCL == NULL || *LCL == NULL){
		printf("\nNada para mostrar.\n");
		_pause();
		return;
	}
	
	for(; noc != NULL; noc = noc->prox){
		if(equalsDATA(noc->cliente.d, d)) _mostraCLI(&noc->cliente);
	}
}

void mostraCLI_idade(unsigned short int x, unsigned short int y){
	NOCli *noc = *LCL;
	unsigned short int i;
	DATA d = criaData();
	
	if(LCL == NULL || *LCL == NULL){
		printf("\nNada para mostrar.\n\n");
		_pause();
		return;
	}
	
	for(; noc != NULL; noc = noc->prox){
		i = d.a - noc->cliente.dat_nasc.a;
		if(i >= x && i <= y) _mostraCLI(&noc->cliente);
	}
}

int temKID(CLI *cl){
	int i;

	if(!is_CLI_in(cl->n_conta)) return 0;
	if(vazia_KID()) return 0;

	for(i=0; i<LKD->qt; i++){
		if(LKD->kid[i].tel == cl->tel) return 1;
	}

	return 0;
}

int qtKID(CLI *cl){
	unsigned short int qt, i;
	
	if(vazia_KID()) return 0;
	
	for(i=qt=0; i<LKD->qt; i++){
		if(LKD->kid[i].tel == cl->tel) qt++;
	}
	
	return qt;
}

void cli_n_KID(unsigned short int n){
	unsigned short int i;
	NOCli *noc = *LCL;
	
	for(i=0; noc != NULL; noc=noc->prox){
		i = qtKID(&noc->cliente);
		if(i > n){
			printf("\n%s tem %hu contas kid.\n", noc->cliente.nome, i);
		}
	}
	
	printf("\nNenhuma conta tem mais de %hu contas kid.\n", n);
}

int valor_menor_n(double v){
	NOCli *noc = *LCL;
	unsigned short int qt=0;
	
	if(*LCL == NULL) return 0;
	
	for(; noc!=NULL; noc=noc->prox){
		if(noc->cliente.valor < v){
			qt++;
		}
	}
	
	return qt;
}

/*void mostraCLI_alf(){
	NOCli *noc = *LCL;
	CLI lcli[MAX], aux;
	int i, j, a;
	
	if(*LCL == NULL){
		printf("\nNada para mostrar.\n");
		system(pause);
		menuSys();
	}
	
	if(tam() == 1){
		_mostraCLI(&noc->cliente);
		system(pause);
		menuSys();
	}
	
	for(a=0; noc != NULL; noc=noc->prox){
		lcli[a++] = noc->cliente;
	}
	
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(strcmp(lcli[i].nome, lcli[j].nome) < 0){
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
	
	system(pause);
	menuSys();
}*/

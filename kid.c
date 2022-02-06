#include <string.h>
#include <locale.h>
#define __ALL_TYPES__
#define __LS_FUNC__
#define __CLIK_FUNC__
#define __DT_FUNC__
#define __MN_FUNC__
#include "Declaração.h"

extern LISTA_KID *LKD;

CONTA_KID iniKID(char nome[80], char *n_ced, char gen, long int tel,
	double val, char *n_conta, DATA dat_n, DATA d, unsigned short int i){
	CONTA_KID k;

    k.d = d;
    k.dat_nasc = dat_n;
    k.gen = gen;
    strcpy(k.nome, nome);
    strcpy(k.n_ced, n_ced);
    strcpy(k.n_conta, n_conta);
    k.tel = tel;
    k.valor = val;
    k.idade = i;
    
    return k;
}

int is_KID_in(char *ced){
	int i;
	
	if(vazia_KID()) return 0;
	
	for(i=0; i<LKD->qt; i++){
		if(strcmp(LKD->kid[i].n_ced, ced) == 0) return 1;
	}
	
	return 0;
}

CONTA_KID *getKID(char *ced){
	int i;
	
	if(vazia_KID()) return NULL;
	
	for(i=0; i<LKD->qt; i++){
		if(strcmp(LKD->kid[i].n_ced, ced) == 0) return &LKD->kid[i];
	}
	
	return NULL;
}

void mostraKID(){
	unsigned short int i;
	
	setlocale(LC_ALL, "Portuguese");
	
	if(LKD->qt == 0){
		printf("\nNada para mostrar.\n\n");
		_pause();
		return;
	}
	
	for(i=0; i<LKD->qt; i++){
		printf("\nNome: %s\n", LKD->kid[i].nome);
		printf("Número da cédula: %s\n", LKD->kid[i].n_ced);
		printf("Data de nascimento:");
		mostraData(LKD->kid[i].dat_nasc);
		printf("Idade: %d\n", LKD->kid[i].idade);
		switch(LKD->kid[i].gen){
			case 'M': printf("Gênero Masculino\n");break;
			case 'F': printf("Gênero Femenino\n");break;
		}
		printf("Telefone do encarregado: %ld\n", LKD->kid[i].tel);
		printf("Número da conta do encarregado %s\n", LKD->kid[i].n_conta);
		printf("Data de criação da conta:");
		mostraData(LKD->kid[i].d);
		printf("Saldo na conta: %.2lf kz\n", LKD->kid[i].valor);
		printf("=======================================================\n\n");
	}
	
	_pause();
}

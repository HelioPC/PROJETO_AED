#define __ALL_TYPES__
#define __LS_FUNC__
#include "Declaração.h"

extern LISTA_KID *LKD;

void iniLKID(void){
	LKD = (LISTA_KID *) malloc(sizeof(LISTA_KID));
	
	if(LKD != NULL) LKD->qt=0;
}

int tam_KID(void){
	return LKD->qt;
}

int vazia_KID(void){
	return LKD->qt == 0;
}

int cheio_KID(void){
	return LKD->qt == MAX;
}

int inserirF_KID(CONTA_KID ck){
	if(cheio_KID()) return 0;
	
	LKD->kid[LKD->qt] = ck;
	LKD->qt++;
	
	return 1;
}

int removeK_KID(int k){
	int i;
	
	if(vazia_KID()) return 0;
	if(k > LKD->qt || k < 0) return 0;
	
	for(i=k; i<LKD->qt-2; i++){
		LKD->kid[i] = LKD->kid[i+1];
	}
	LKD->kid[i] = LKD->kid[i+1];
	LKD->qt--;
	
	return 1;
}

int rmKID(char *n_conta){
	int i;
	
	if(vazia_KID()) return 0;
	
	for(i=0; i<LKD->qt; i++){
		if(strcmp(n_conta, LKD->kid[i].n_conta) == 0){
			removeK_KID(i);
		}
	}
	
	return 1;
}

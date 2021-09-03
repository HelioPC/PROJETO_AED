#include <string.h>
#define __ALL_TYPES__
#define __LL_FUNC__
#define __LDL_FUNC__
#define __LS_FUNC__
#define __DT_FUNC__
#define __CLI_FUNC__
#define __CLIK_FUNC__
#define __MN_FUNC__
#include "Declaração.h"

extern LISTACLI *LCL;

int transferir(CLI *cl, double val, char *n_conta){
	HIST h;
	CLI *cl2;

    if(!is_CLI_in(n_conta)) return 0;

	cl2 = getCLI(n_conta);

	cl->valor -= val;
	cl2->valor += val;

	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	sprintf(h.tipo, "Transferência de %.2lf kz de %s para %s.", val,
	cl->nome, cl2->nome);
	inserirF_LH(h);

	return 1;
}

int depositar(CLI *cl, double val){
	HIST h;
	
	if(!is_CLI_in(cl->n_conta)) return 0;
	
	cl->valor += val;
	
	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	sprintf(h.tipo, "Depósito de %.2lf kz.", val);
	inserirF_LH(h);
	
	return 1;
}

void consultar(CLI *cl){
	HIST h;
	
	system(limpa);
	printf("===================Consulta de %s===================", cl->nome);
	printf("\n\n\tSaldo Disponível\t\tSaldo Contabilístico\n");
	printf("\n\t%.2lfkz\t\t%.2lfkz\n", cl->valor, cl->valor);
	printf("\n========================================================\n");
	
	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	strcpy(h.tipo, "Consulta");
	inserirF_LH(h);
}

int levantar(CLI *cl, double val){
	HIST h;
	
	if(!is_CLI_in(cl->n_conta)) return 0;
	
	cl->valor -= val;
	
	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	sprintf(h.tipo, "Levantamento de %.2lf kz.", val);
	inserirF_LH(h);
	
	return 1;
}

int depositarKID(CLI *cl, char *ced, double val){
	CONTA_KID *kd;
	HIST h;
	
	if(!is_CLI_in(cl->n_conta)) return 0;
	if(!is_KID_in(ced)) return 0;
	
	
	kd = getKID(ced);
	cl->valor -= val;
	kd->valor += val;
	
	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	sprintf(h.tipo, "Depósito em Kid de %.2lf kz.", val);
	inserirF_LH(h);
	
	return 1;
}

void debitar_ALL(){
	NOCli *noc = *LCL;
	
	system(limpa);
	if(LCL == NULL || *LCL == NULL){
		printf("Nada para mostrar.\n\n");
		_pause();
		return;
	}
	
	for(; noc != NULL; noc=noc->prox){
		noc->cliente.valor -= (noc->cliente.valor * (1.5/100));
	}
	
	printf("Foi debitado em todas as contas 1.5%%.\n\n");
	_pause();
}

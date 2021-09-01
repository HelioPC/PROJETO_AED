#include "Declaração.h"

/*Fun��es Das Listas (e duplamente) Ligadas (e seus n�s)*/
void iniLCLI(void){
	LCL = (LISTACLI *) malloc(sizeof(LISTACLI));
	
	if(LCL != NULL) *LCL = NULL;
}

void iniLHIST(void){
	LHS = (LISTAHIST *) malloc(sizeof(LISTAHIST));
	
	if(LHS != NULL) *LHS = NULL;
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

int inserirI(CLI cli){
	NOCli *no = (NOCli *) malloc(sizeof(NOCli));
	
	if(LCL == NULL) return 0;
	
	if(no == NULL) return 0;
	
	no->cliente = cli;
	no->prox = *LCL;
	*LCL = no;
	
	return 1;
}

int inserirF(CLI cli){
	NOCli *no = (NOCli *) malloc(sizeof(NOCli));
	NOCli *aux = *LCL;
	
	if(LCL == NULL) return 0;
	
	if(no == NULL) return 0;
	
	no->cliente = cli;
	no->prox = NULL;
	
	if((*LCL) == NULL){
		*LCL = no;
	}else{
		for(; aux->prox != NULL; aux = aux->prox);
		
		aux->prox = no;
	}
	
	return 1;
}

int inserirI2(LISTACLI *lc, CLI cli){
	NOCli *no = (NOCli *) malloc(sizeof(NOCli));
	
	if(lc == NULL) return 0;
	
	if(no == NULL) return 0;
	
	no->cliente = cli;
	no->prox = *lc;
	*lc = no;
	
	return 1;
}

int inserirK(CLI cli, int k){
	NOCli *no = (NOCli *) malloc(sizeof(NOCli));
	NOCli *aux = *LCL;
	int cont=2;
	
	if(aux == NULL) return 0;
	if(no == NULL) return 0;
	if(k > tam()+1) return 0;
	if(LCL == NULL) return 0;
	
	no->cliente = cli;
	
	if(k == 1){
		inserirI(cli);
		return 1;
	}
	
	if(tam()+1 == k){
		inserirF(cli);
		return 1;
	}
	
	for(; aux != NULL && cont < k; aux = aux->prox, cont++);
	
	no->prox = aux->prox;
	aux->prox = no;
	
	return 1;
}

int removeI(){
	NOCli *no = *LCL;
	
	if(LCL == NULL) return 0;
	if(*LCL == NULL) return 0;
	
	*LCL = no->prox;
	free(no);
	
	return 1;
}

int removeF(){
	NOCli *ant, *no = *LCL;
	
	if(LCL == NULL) return 0;
	if(*LCL == NULL) return 0;
	
	while(no->prox != NULL){
		ant = no;
		no = no->prox;
	}
	
	if(no == *LCL){
		*LCL = no->prox;
	}else{
		ant->prox = no->prox;
	}
	free(no);
	
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

int tamLH(void){
	NOHIST *noh = *LHS;
	int cont=0;
	
	if(LHS == NULL) return 0;
	
	for(; noh!=NULL; noh=noh->prox) cont++;
	
	return cont;
}

int vaziaLH(void){
	if(LHS == NULL) return 1;
	if(*LHS == NULL) return 1;
	
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
		system(pause);
		menuSys();
	}
	
	if(tam() == 1){
		_mostraCLI(&noc->cliente);
		system(pause);
		menuSys();
	}
	
	if(tamLH() == 1){
		noh = *LHS;
		_mostraCLI(getCLI(noh->h.n_conta));
		system(pause);
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
	
	system(pause);
	menuSys();
}

void mostraHIST_by_CLI(char *n_conta){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL || qtHIST(getCLI(n_conta))){
		printf("\nNenhum processo para mostrar.\n");
		system(pause);
		menuSys();
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(n_conta, aux->h.n_conta) == 0){
			printf("N�mero da conta: %s\n", n_conta);
			printf("Data da opera��o:");mostraData(aux->h.data);
			printf("Tipo de opera��o: %s\n", aux->h.tipo);
			printf("===================================================\n\n");
		}
	}
	
	_mostraCLI(getCLI(n_conta));
	system(pause);
	menuSys();
}
/*Fim Fun��es Das Listas (e duplamente) Ligadas (e seus n�s)*/

/*Prot�tipos Das Listas Sequenciais*/
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

int inserirI_KID(CONTA_KID ck){
	int i;
	
	if(cheio_KID()) return 0;
	
	for(i=LKD->qt; i>0; i--){
		LKD->kid[i] = LKD->kid[i-1];
	}
	LKD->kid[i] = ck;
	LKD->qt++;
	
	return 1;
}

int inserirF_KID(CONTA_KID ck){
	if(cheio_KID()) return 0;
	
	LKD->kid[LKD->qt] = ck;
	LKD->qt++;
	
	return 1;
}

int inserirK_KID(CONTA_KID ck, int k){
	int i;
	
	if(k > LKD->qt || k < 0) return 0;
	if(cheio_KID()) return 0;
	
	for(i=LKD->qt; i>k; i--){
		LKD->kid[i] = LKD->kid[i-1];
	}
	LKD->kid[i] = ck;
	LKD->qt++;
	
	return 1;
}

int removeI_KID(void){
	int i;
	
	if(vazia_KID()) return 0;
	
	for(i=0; i<LKD->qt-1; i++){
		LKD->kid[i] = LKD->kid[i+1];
	}
	LKD->qt--;
	
	return 1;
}

int removeF_KID(void){
	if(vazia_KID()) return 0;
	
	LKD->qt--;
	
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
/*Fim De Prot�tipos Das Listas Sequenciais*/

/*Fun��es de Data*/
int bissexto(int ano){
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

DATA strToData(char *s){
	DATA d;
	char *dia=strtok(s, "/"), *mes=strtok(NULL, "/"), *ano=strtok(NULL, "/");
	
	d.d = atoi(dia);
	d.a = atoi(ano);
	d.m = atoi(mes);
	
	if(isData(d)) return d;
	
	d.d = 1; d.m = 1; d.a = 2021;
	
	return d;
}

int equalsDATA(DATA d1, DATA d2){
	if(!isData(d1) || !isData(d2)) return 0;
	
	return ((d1.a == d2.a) && (d1.m == d2.m) && (d1.d == d2.d));
}

int isData(DATA d){
	if(d.a < 1900 || d.a > 2021) return 0;
	if(d.m < 1 || d.m > 12) return 0;
	if(d.d < 1 || d.d > 31) return 0;
	if(bissexto(d.a) && d.m == 2 && d.d > 29) return 0;
	if(!bissexto(d.a) && d.m == 2 && d.d > 28) return 0;
	if((d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11) && d.d > 30) return 0;
	
	return 1;
}

int mostraData(DATA d){
	if(!isData(d)) return 0;
	
	switch(d.m){
		case 1: printf("\n%d de Janeiro de %d\n", d.d, d.a); return 1;
		case 2: printf("\n%d de Fevereiro de %d\n", d.d, d.a); return 1;
		case 3: printf("\n%d de Mar�o de %d\n", d.d, d.a); return 1;
		case 4: printf("\n%d de Abril de %d\n", d.d, d.a); return 1;
		case 5: printf("\n%d de Maio de %d\n", d.d, d.a); return 1;
		case 6: printf("\n%d de Junho de %d\n", d.d, d.a); return 1;
		case 7: printf("\n%d de Julho de %d\n", d.d, d.a); return 1;
		case 8: printf("\n%d de Agosto de %d\n", d.d, d.a); return 1;
		case 9: printf("\n%d de Setembro de %d\n", d.d, d.a); return 1;
		case 10: printf("\n%d de Outubro de %d\n", d.d, d.a); return 1;
		case 11: printf("\n%d de Novembro de %d\n", d.d, d.a); return 1;
		case 12: printf("\n%d de Dezembro de %d\n", d.d, d.a); return 1;
		default: return 0;
	}
}

DATA criaData(void){
	DATA d;
	struct tm *PTIME;
	time_t LT;
	
	LT = time(NULL);
	PTIME = localtime(&LT);
	
	d.d = PTIME->tm_mday;
	d.m = PTIME->tm_mon+1;
	d.a = PTIME->tm_year+1900;
	
	if(isData(d)) return d;
	
	d.d = 1; d.m = 1; d.a = 2021;
	
	return d;
}
/*Fim de Fun��es de Data*/

/*Fun��es de Cliente*/
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
		system(pause);
		menuSys();
	}
	
	for(; aux->prox != NULL; aux = aux->prox){
		printf("Nome do cliente: %s\n", aux->cliente.nome);
		printf("Data de nascimento do cliente:");
		mostraData(aux->cliente.dat_nasc);
		printf("N�mero de telefone do cliente: %ld\n", aux->cliente.tel);
		printf("Valor na conta do cliente: %.2lf kz.\n", aux->cliente.valor);
		printf("N� do B.I do cliente: %s\n", aux->cliente.n_bi);
		switch(aux->cliente.gen){
			case 'M': printf("G�nero Masculino\n");break;
			case 'F': printf("G�nero Femenino\n");break;
		}
		printf("N�mero da conta do cliente: %s\n", aux->cliente.n_conta);
		printf("=======================================================\n\n");
	}
	printf("\nNome do cliente: %s\n", aux->cliente.nome);
	printf("Data de nascimento do cliente:");
	mostraData(aux->cliente.dat_nasc);
	printf("N�mero de telefone do cliente: %ld\n", aux->cliente.tel);
	printf("Valor na conta do cliente: %.2lf kz.\n", aux->cliente.valor);
	printf("N� do B.I do cliente: %s\n", aux->cliente.n_bi);
	switch(aux->cliente.gen){
		case 'M': printf("G�nero Masculino\n");break;
		case 'F': printf("G�nero Femenino\n");break;
	}
	printf("N�mero da conta do cliente: %s\n", aux->cliente.n_conta);
	
	printf("===========================================================\n\n");
	
	system(pause);
	menuSys();
}

void _mostraCLI(CLI *cl){
	printf("===========================================================\n\n");
	printf("Nome do cliente: %s\n", cl->nome);
	printf("Data de nascimento do cliente:");
	mostraData(cl->dat_nasc);
	printf("N�mero de telefone do cliente: %ld\n", cl->tel);
	printf("Valor na conta do cliente: %.2lf kz.\n", cl->valor);
	printf("N� do B.I do cliente: %s\n", cl->n_bi);
	switch(cl->gen){
		case 'M': printf("G�nero: Masculino\n");break;
		case 'F': printf("G�nero: Femenino\n");break;
	}
	printf("N�mero da conta do cliente: %s\n", cl->n_conta);
	printf("===========================================================\n\n");
}

void mostraCLI_by_DATA(DATA d){
	NOCli *noc;
	
	if(LCL == NULL || *LCL == NULL){
		printf("\nNada para mostrar.\n");
		system(pause);
		menuSys();
	}
	
	for(; noc != NULL; noc = noc->prox){
		if(equalsDATA(noc->cliente.d, d)){
			printf("===================================================\n\n");
			printf("Nome do cliente: %s\n", noc->cliente.nome);
			printf("Data de nascimento do cliente:");
			mostraData(noc->cliente.dat_nasc);
			printf("N�mero de telefone do cliente: %ld\n", noc->cliente.tel);
			printf("Valor na conta do cliente: %.2lf kz.\n", noc->cliente.valor);
			printf("N� do B.I do cliente: %s\n", noc->cliente.n_bi);
			switch(noc->cliente.gen){
				case 'M': printf("G�nero: Masculino\n");break;
				case 'F': printf("G�nero: Femenino\n");break;
			}
			printf("N�mero da conta do cliente: %s\n", noc->cliente.n_conta);
			printf("===================================================\n\n");
		}
	}
}

void mostraCLI_idade(unsigned short int x, unsigned short int y){
	NOCli *noc = *LCL;
	unsigned short int i;
	DATA d = criaData();
	
	if(LCL == NULL || *LCL == NULL){
		printf("\nNada para mostrar.\n\n");
		system(pause);
		menuSys();
	}
	
	for(; noc != NULL; noc = noc->prox){
		i = d.a - noc->cliente.dat_nasc.a;
		if(i >= x && i <= y){
			printf("===================================================\n\n");
			printf("Nome do cliente: %s\n", noc->cliente.nome);
			printf("Data de nascimento do cliente:");
			mostraData(noc->cliente.dat_nasc);
			printf("N�mero de telefone do cliente: %ld\n", noc->cliente.tel);
			printf("Valor na conta: %.2lf kz.\n", noc->cliente.valor);
			printf("N� do B.I do cliente: %s\n", noc->cliente.n_bi);
			switch(noc->cliente.gen){
				case 'M': printf("G�nero: Masculino\n");break;
				case 'F': printf("G�nero: Femenino\n");break;
			}
			printf("N�mero da conta do cliente: %s\n", noc->cliente.n_conta);
			printf("===================================================\n\n");
		}
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

int transferir(CLI *cl, double val, char *n_conta){
	HIST h;
	CLI *cl2;
	if(!is_CLI_in(n_conta)) return 0;
	
	cl2 = getCLI(n_conta);
	
	cl->valor -= val;
	cl2->valor += val;
	
	h.data = criaData();
	strcpy(h.n_conta, cl->n_conta);
	sprintf(h.tipo, "Transfer�ncia de %.2lf kz de %s para %s.", val,
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
	sprintf(h.tipo, "Dep�sito de %.2lf kz.", val);
	inserirF_LH(h);
	
	return 1;
}

void consultar(CLI *cl){
	HIST h;
	
	system(limpa);
	printf("===================Consulta de %s===================", cl->nome);
	printf("\n\n\tSaldo Dispon�vel\t\tSaldo Contabil�stico\n");
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
	sprintf(h.tipo, "Dep�sito em Kid de %.2lf kz.", val);
	inserirF_LH(h);
	
	return 1;
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

void mostraCLI_alf(){
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
}
/*Fim de Fun��es de Cliente*/

/*Fun��es de Conta Kid*/
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
		system(pause);
		menuSys();
	}
	
	for(i=0; i<LKD->qt; i++){
		printf("\nNome: %s\n", LKD->kid[i].nome);
		printf("N�mero da c�dula: %s\n", LKD->kid[i].n_ced);
		printf("Data de nascimento:");
		mostraData(LKD->kid[i].dat_nasc);
		printf("Idade: %d\n", LKD->kid[i].idade);
		switch(LKD->kid[i].gen){
			case 'M': printf("G�nero Masculino\n");break;
			case 'F': printf("G�nero Femenino\n");break;
		}
		printf("Telefone do encarregado: %ld\n", LKD->kid[i].tel);
		printf("N�mero da conta do encarregado %s\n", LKD->kid[i].n_conta);
		printf("Data de cria��o da conta:");
		mostraData(LKD->kid[i].d);
		printf("Saldo na conta: %.2lf kz\n", LKD->kid[i].valor);
		printf("=======================================================\n\n");
	}
	
	system(pause);
	menuSys();
}
/*Fim de Fun��es de Conta Kid*/

/*Fun��es De Hist�rico*/
void mostraHIST_by_DATA(DATA d, CLI *cl){
	NOHIST *aux = *LHS;
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		system(pause);
		menuHist(cl);
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		equalsDATA(d, aux->h.data)){
			printf("N�mero da conta: %s\n", cl->n_conta);
			printf("Data da opera��o:");mostraData(d);
			printf("Tipo de opera��o: %s\n", aux->h.tipo);
			printf("=====================================================\n");
		}
	}
	
	system(pause);
	menuHist(cl);
}

void mostraHIST_by_OP(CLI *cl){
	NOHIST *aux = *LHS;
	char op[14];
	
	if(*LHS == NULL){
		printf("\nNenhum processo para mostrar.\n");
		system(pause);
		menuHist(cl);
	}
	
	system(limpa);
	printf("Introduza o tipo de opera��o: ");fflush(stdin);
	fgets(op, 14, stdin);
	op[strcspn(op, "\n")] = '\0';
	
	while(op[0] != 'T' && op[0] != 'L' && op[0] != 'D' && op[0] != 'C'){
		printf("Introduza o tipo de opera��o: ");fflush(stdin);
		fgets(op, 14, stdin);
		op[strcspn(op, "\n")] = '\0';
	}
	
	switch(op[0]){
		case 'T':
			if(strcmp(op, "Transfer�ncia") != 0){
				printf("\nPar�metro inv�lido.\n");
				system(pause);
				menuHist(cl);
			}break;
		case 'D':
			if(strcmp(op, "Dep�sito") != 0){
				printf("\nPar�metro inv�lido.\n");
				system(pause);
				menuHist(cl);
			}break;
		case 'L':
			if(strcmp(op, "Levantamento") != 0){
				printf("\nPar�metro inv�lido.\n");
				system(pause);
				menuHist(cl);
			}break;
		case 'C':
			if(strcmp(op, "Consulta") != 0){
				printf("\nPar�metro inv�lido.\n");
				system(pause);
				menuHist(cl);
			}break;
	}
	
	system(limpa);
	for(; aux != NULL; aux=aux->prox){
		if(strcmp(cl->n_conta, aux->h.n_conta) == 0 &&
		strstr(aux->h.tipo, op) != NULL){
			printf("N�mero da conta: %s\n", cl->n_conta);
			printf("Data da opera��o:");mostraData(aux->h.data);
			printf("Tipo de opera��o: %s\n", aux->h.tipo);
			printf("=====================================================\n");
		}
	}
	
	system(pause);
	menuHist(cl);
}
/*Fim De Fun��es De Hist�rico*/

/*Outras Fun��es*/
void debitar_ALL(){
	NOCli *noc = *LCL;
	
	system(limpa);
	if(LCL == NULL || *LCL == NULL){
		printf("Nada para mostrar.\n\n");
		system(pause);
		menuSys();
	}
	
	for(; noc != NULL; noc=noc->prox){
		noc->cliente.valor -= (noc->cliente.valor * (1.5/100));
	}
	
	printf("Foi debitado em todas as contas 1.5%.\n\n");
	system(pause);
	menuSys();
}

void menu(void){
	unsigned short int opc = 0;
	char n_conta[15];
	
	system(limpa);
	printf("=======================BANCO BANO=======================");
	printf("\n\t1- Cliente\n\t2- Sistema\n\t3- Sair\n");
	printf("========================================================\n");
	
	while(opc<1 || opc>3){
		printf("\nEscolha uma op��o: ");
		fflush(stdin);
		scanf("%hu", &opc);
	}
	
	if(opc == 1){
		system(limpa);
		printf("Introduza o n�mero da conta: ");fflush(stdin);
		fgets(n_conta, 15, stdin);
		n_conta[strcspn(n_conta, "\n")] = '\0';
		while(n_conta[0] != 'B'){
			printf("Conta inv�lida!");
			printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
			fgets(n_conta, 15, stdin);
			n_conta[strcspn(n_conta, "\n")] = '\0';
		}
		if(is_CLI_in(n_conta)){
			menuCli(getCLI(n_conta));
		}else{
			printf("\nN� de conta n�o est� associado a nenhuma conta.\n\n");
			system(pause);
			menu();
		}
	}
	else if(opc == 2){
		menuSys();
	}else{
		exit(1);
	}
}

void menuCli(CLI *cl){
	unsigned short int opc = 0, i;
	char ced[11];
	double val=0.0;
	char valStr[15];
	CONTA_KID *k;
	char n_conta[15];
	
	system(limpa);
	printf("==================BANCO BANO (Cliente)==================");
	printf("\n\t1- Transferir\n\t2- Depositar\n\t3- Consultar");
	printf("\n\t4- Levantar\n\t5- Depositar Em Kid");
	printf("\n\t6- Criar Conta Em Kid\n\t7- Hist�rico De Opera��es");
	printf("\n\t8- Voltar\n");
	printf("========================================================\n");
	
	while(opc<1 || opc>8){
		printf("\nEscolha uma op��o: ");
		fflush(stdin);
		scanf("%hu", &opc);
	}
	
	if(opc == 7){
		menuHist(cl);
	}
	else if(opc == 6){
		if(cl->valor < 150001.0){
			printf("\nSaldo insuficiente na conta para a abertura!");
			printf("\nFa�a mais dep�sitos!\n\n");
			system(pause);
			menuCli(cl);
		}
		abreContaKid(cl);
	}
	else if(opc == 5){
		if(qtKID(cl) == 1){
			for(i=0; i<LKD->qt; i++){
				if(LKD->kid[i].tel == cl->tel) k = &LKD->kid[i];
			}
			
			printf("\nIntroduza o valor a depositar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor a depositar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
			
			while(val >= cl->valor){
				printf("\nIntroduza o valor a depositar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\nIntroduza o valor a depositar: ");fflush(stdin);
					fgets(valStr, 14, stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
			}
			
			if(depositarKID(cl, k->n_ced, val)){
				printf("\n\nDep�sito na conta kid efetuada com sucesso.\n\n");
			}else{
				printf("\n\nDep�sito na conta kid efetuada com sucesso.\n\n");
			}
			system(pause);
			menuCli(cl);
		}else if(qtKID(cl) > 1){
			printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
			fgets(ced, 10, stdin);
			ced[strcspn(ced, "\n")] = '\0';
			
			while(!isCED(ced)){
				printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
				fgets(ced, 10, stdin);
				ced[strcspn(ced, "\n")] = '\0';
			}
			
			while(!is_KID_in(ced)){
				printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
				fgets(ced, 10, stdin);
				ced[strcspn(ced, "\n")] = '\0';
				
				while(!isCED(ced)){
					printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
					fgets(ced, 10, stdin);
					ced[strcspn(ced, "\n")] = '\0';
				}
			}
			
			k = getKID(ced);
			printf("\nIntroduza o valor a depositar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor a depositar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
			
			while(val >= cl->valor){
				printf("\nIntroduza o valor a depositar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\nIntroduza o valor a depositar: ");fflush(stdin);
					fgets(valStr, 14, stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
			}
			
			if(depositarKID(cl, k->n_ced, val)){
				printf("\n\nDep�sito na conta kid efetuada com sucesso.\n\n");
			}else{
				printf("\n\nDep�sito n�o foi efetuado com sucesso.\n\n");
			}
			system(pause);
			menuCli(cl);
		}else{
			printf("\nSem conta Kid.\n");
			system(pause);
			menuCli(cl);
		}
	}
	else if(opc == 4){
		printf("\n\nIntroduza o valor a levantar: ");fflush(stdin);
		fgets(valStr, 14, stdin);
		valStr[strcspn(valStr, "\n")] = '\0';
		
		while(!isFloat(valStr)){
			printf("\n\nIntroduza o valor a levantar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
		}
		
		val = atof(valStr);
		
		while(val < 1){
			printf("\n\nIntroduza o valor a levantar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor a levantar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
		}
		
		if(levantar(cl, val)){
			printf("\n\nLevantamento efetuado com sucesso...\n\n");
		}else{
			printf("\n\nLevantamento n�o foi efetuado com sucesso...\n\n");
		}
		
		system(pause);
		menuCli(cl);
	}
	else if(opc == 3){
		consultar(cl);
		system(pause);
		menuCli(cl);
	}
	else if(opc == 2){
		printf("\n\nIntroduza o valor a depositar: ");fflush(stdin);
		fgets(valStr, 14, stdin);
		valStr[strcspn(valStr, "\n")] = '\0';
		
		while(!isFloat(valStr)){
			printf("\n\nIntroduza o valor a depositar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
		}
		
		val = atof(valStr);
		
		while(val < 1){
			printf("\n\nIntroduza o valor a depositar: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor a depositar: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
		}
		
		if(depositar(cl, val)){
			printf("\n\nDep�sito efetuado com sucesso...\n\n");
		}else{
			printf("\n\nDep�sito n�o foi efetuado com sucesso...\n\n");
		}
		
		system(pause);
		menuCli(cl);
	}
	else if(opc == 1){
		printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
		fgets(n_conta, 15, stdin);
		n_conta[strcspn(n_conta, "\n")] = '\0';
		while(n_conta[0] != 'B'){
			printf("Conta inv�lida!");
			printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
			fgets(n_conta, 15, stdin);
			n_conta[strcspn(n_conta, "\n")] = '\0';
		}
		
		if(is_CLI_in(n_conta)){
			printf("\n\nIntroduza o valor a transferir: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor a transferir: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			val = atof(valStr);
			
			while(val < 1){
				printf("\n\nIntroduza o valor a transferir: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
				
				while(!isFloat(valStr)){
					printf("\n\nIntroduza o valor a transferir: ");
					fflush(stdin);
					fgets(valStr, 14, stdin);
					valStr[strcspn(valStr, "\n")] = '\0';
				}
				
				val = atof(valStr);
			}
			
			if(transferir(cl, val, n_conta)){
				printf("\nTransfer�ncia efetuada com sucesso...\n\n");
				system(pause);
				menuCli(cl);
			}else{
				printf("\nTransfer�ncia n�o foi efetuada com sucesso...\n\n");
				system(pause);
				menuCli(cl);
			}
		}else{
			printf("\nN� de conta n�o est� associado a nenhuma conta.\n\n");
			system(pause);
			menuCli(cl);
		}
	}
	else{
		menu();
	}
}

void menuSys(void){
	unsigned short int opc = 0, n, x=0, y=0;
	char str[15], vStr[15];
	double v;
	DATA d, d2;
	
	system(limpa);
	printf("=====================BANCO BANO (Sistema)=====================");
	printf("\n\t1- Registar Cliente.\n");
	printf("\t2- Ver a quantidade de Contas existentes.\n");
	printf("\t3- Ver a quantidade de contas kids existentes.\n");
	printf("\t4- Listar os clientes com mais de n contas kids.\n");
	printf("\t5- Lista um ranking dos clientes mais activos no banco.\n");
	printf("\t6- Listar as informa��es dos Clientes.\n");
	printf("\t7- Listar a informa��o de um determinado Cliente.\n");
	printf("\t8- Listar o hist�rico e os dados de um determinado Cliente.\n");
	printf("\t9- Listar todos os clientes que criaram contas numa data.\n");
	printf("\t10- Listar todos os clientes com idades entre x-y.\n");
	printf("\t11- Debitar 1.5%% do valor de todas as contas.\n");
	printf("\t12- Desativar conta de um cliente.\n");
	printf("\t13- Verificar se existe conta com saldo menor que n.\n");
	printf("\t14- Listar os Clientes em ordem alfab�tica.\n");
	printf("\t15- Listar as informa��es dos Clientes Kid.\n");
	printf("\t16- Voltar\n");
	printf("=============================================================\n");
	
	while(opc<1 || opc>16){
		printf("\nEscolha uma op��o: ");
		fflush(stdin);
		scanf("%hu", &opc);
	}
	
	if(opc == 1){
		abreConta();
	}
	else if(opc == 2){
		printf("\nExistem %d %s.\n", tam(), tam()<2?"conta":"contas");
		putchar('\n');
		system(pause);
		menuSys();
	}
	else if(opc == 3){
		printf("\nExistem %d %s.\n", tam_KID(), tam_KID()<2?"conta":"contas");
		putchar('\n');
		system(pause);
		menuSys();
	}
	else if(opc == 4){
		if(vazia_KID()){
			printf("\nN�o existem contas kids registadas no sistema.\n");
			system(pause);
			menuSys();
		}
		
		if(vazia()){
			printf("\nN�o existem clientes registados no sistema.\n");
			system(pause);
			menuSys();
		}
		
		printf("\nIntroduza o n: ");
		scanf("%hu", &n);
		while(n > MAX-1 || n < 1){
			printf("\nValor de n � inv�lido!\n");
			printf("\nIntroduza o n: ");
			scanf("%hu", &n);
		}
		cli_n_KID(n);
		system(pause);
		menuSys();
	}
	else if(opc == 5){
		rank_mais_act();
	}
	else if(opc == 6){
		system(limpa);
		mostraCLI();
	}
	else if(opc == 7){
		printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
		fgets(str, 15, stdin);
		str[strcspn(str, "\n")] = '\0';
		while(str[0] != 'B'){
			printf("Conta inv�lida!");
			printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
			fgets(str, 15, stdin);
			str[strcspn(str, "\n")] = '\0';
		}
		
		if(is_CLI_in(str)){
			_mostraCLI(getCLI(str));
			system(pause);
			menuSys();
		}else{
			printf("\nN� de conta n�o est� associado a nenhuma conta.\n\n");
			system(pause);
			menuSys();
		}
	}
	else if(opc == 8){
		printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
		fgets(str, 15, stdin);
		str[strcspn(str, "\n")] = '\0';
		while(str[0] != 'B'){
			printf("Conta inv�lida!");
			printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
			fgets(str, 15, stdin);
			str[strcspn(str, "\n")] = '\0';
		}
		
		if(is_CLI_in(str)){
			mostraHIST_by_CLI(str);
		}else{
			printf("\nN� de conta n�o est� associado a nenhuma conta.\n\n");
			system(pause);
			menuSys();
		}
	}
	else if(opc == 9){
		d2 = criaData();
		printf("\nIntroduza a data de cria��o da conta: ");fflush(stdin);
		fgets(str, 11, stdin);d = strToData(str);
		str[strcspn(str, "\n")] = '\0';
		
		while(d.a > d2.a){
			printf("\nIntroduza a data de cria��o da conta: ");fflush(stdin);
			fgets(str, 11, stdin);d = strToData(str);
			str[strcspn(str, "\n")] = '\0';
		}
		
		mostraCLI_by_DATA(d);
		system(pause);
		menuSys();
	}
	else if(opc == 10){
		system(limpa);
		while(x<12 && y<12 && x >= y){
			printf("\nIntroduza o 1� intervalo: ");
			fflush(stdin);
			scanf("%hu", &x);
			printf("\nIntroduza o 2� intervalo: ");
			fflush(stdin);
			scanf("%hu", &y);
		}
		
		mostraCLI_idade(x, y);
		system(pause);
		menuSys();
	}
	else if(opc == 11){
		debitar_ALL();
	}
	else if(opc == 12){
		system(limpa);
		printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
		fgets(str, 15, stdin);
		str[strcspn(str, "\n")] = '\0';
		while(str[0] != 'B'){
			printf("Conta inv�lida!");
			printf("\nIntroduza o n�mero da conta: ");fflush(stdin);
			fgets(str, 15, stdin);
			str[strcspn(str, "\n")] = '\0';
		}
		
		if(is_CLI_in(str)){
			printf("\n\nA conta %s ser� eliminada!\n\n", str);
			system(pause);
			if(qtKID(getCLI(str)) > 0){
				rmKID(str);
			}
			if(removeK(str)){
				printf("\n\nConta removida com sucesso.\n\n");
			}else{
				printf("\nOcorreu um erro inesperado.\n\n");
			}
			system(pause);
			menuSys();
		}else{
			printf("\nN� de conta n�o est� associado a nenhuma conta.\n\n");
			system(pause);
			menuSys();
		}
	}
	else if(opc == 13){
		if(*LCL == NULL){
			printf("\n\nN�o existem contas no sistema.\n\n");
			system(pause);
			menuSys();
		}
		
		printf("\n\nIntroduza o valor: ");fflush(stdin);
		fgets(vStr, 14, stdin);
		vStr[strcspn(vStr, "\n")] = '\0';
		
		while(!isFloat(vStr)){
			printf("\n\nIntroduza o valor: ");fflush(stdin);
			fgets(vStr, 14, stdin);
			vStr[strcspn(vStr, "\n")] = '\0';
		}
		
		v = atof(vStr);
		
		while(v < 0){
			printf("\n\nIntroduza o valor: ");fflush(stdin);
			fgets(vStr, 14, stdin);
			vStr[strcspn(vStr, "\n")] = '\0';
			
			while(!isFloat(vStr)){
				printf("\n\nIntroduza o valor: ");fflush(stdin);
				fgets(vStr, 14, stdin);
				vStr[strcspn(vStr, "\n")] = '\0';
			}
			
			v = atof(vStr);
		}
		
		if(valor_menor_n(v) > 0){
			printf("\nExistem %d contas.\n\n", valor_menor_n(v));
			system(pause);
			menuSys();
		}else{
			printf("\nN�o existem contas com menos de %.2lf kz.\n\n", v);
			system(pause);
			menuSys();
		}
	}
	else if(opc == 14){
		mostraCLI_alf();
	}
	else if(opc == 15){
		system(limpa);
		mostraKID();
	}
	else{
		menu();
	}
}

void menuHist(CLI *cl){
	unsigned short int opc;
	char str[11];
	DATA d;
	
	system(limpa);
	printf("====================BANCO BANO (Hist�rico)====================");
	printf("\n\t1- Quantidade de processos.");
	printf("\n\t2- Relat�rio de opera��es em um dada data.");
	printf("\n\t3- Hist�rico por tipo de opera��o.");
	printf("\n\t4- Voltar.");
	printf("\n========================================================\n");
	
	while(opc<1 || opc>4){
		printf("\nEscolha uma op��o: ");
		fflush(stdin);
		scanf("%hu", &opc);
	}
	
	if(opc == 1){
		printf("\nExistem %d %s na conta.\n", qtHIST(cl),
		 qtHIST(cl)==1 ? "processo" : "processos");
		 
		 system(pause);
		 menuHist(cl);
	}
	else if(opc == 2){
		printf("\nIntroduza a data: ");fflush(stdin);
		fgets(str, 11, stdin);d = strToData(str);
		str[strcspn(str, "\n")] = '\0';
		
		while(!isData(d)){
			printf("\nIntroduza a data: ");fflush(stdin);
			fgets(str, 11, stdin);d = strToData(str);
			str[strcspn(str, "\n")] = '\0';
		}
		
		mostraHIST_by_DATA(d, cl);
	}
	else if(opc == 3){
		mostraHIST_by_OP(cl);
	}else{
		system(pause);
		menuCli(cl);
	}
}

void abreConta(void){
	char nome[31], data[11], valStr[15], telStr[11];
	DATA dat_nasc, dat_atual=criaData();
	long int tel=0;
	double valor=6894.0;
	int idade;
	char gen;
	char n_conta[15], n_bi[16];
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=======================Abertura De Conta=======================");
	
	printf("\nIntroduza o seu nome: ");fflush(stdin);
	fgets(nome, 80, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	while(!isNome(nome)){
		printf("\nIntroduza o seu nome: ");fflush(stdin);
		fgets(nome, 80, stdin);
		nome[strcspn(nome, "\n")] = '\0';
	}
	
	printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
	fgets(data, 11, stdin);dat_nasc = strToData(data);
	data[strcspn(data, "\n")] = '\0';
	idade = dat_atual.a - dat_nasc.a;
	
	while(idade < 12){
		printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
		fgets(data, 11, stdin);dat_nasc = strToData(data);
		data[strcspn(data, "\n")] = '\0';
		idade = dat_atual.a - dat_nasc.a;
	}
	
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu g�nero(M/F): ");fflush(stdin);
		gen = getchar();
	}
	
	printf("\nIntroduza o seu n�mero de tel.: ");fflush(stdin);
	fgets(telStr, 10, stdin);
	
	while(!isTel(telStr)){
		printf("\nIntroduza o seu n�mero de tel.: ");fflush(stdin);
		fgets(telStr, 10, stdin);
	}
	
	tel = atoi(telStr);
	
	printf("\nIntroduza o n�mero do B.I: ");fflush(stdin);
	fgets(n_bi, 15, stdin);
	
	while(!isBI(n_bi)){
		printf("\nIntroduza o n�mero do B.I: ");fflush(stdin);
		fgets(n_bi, 15, stdin);
	}
	
	if(idade > 11 && idade < 21){
		while(valor < 6895.0){
			printf("\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}
	else if(idade > 20 && idade < 35){
		while(valor < 10000.0){
			printf("\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}else{
		while(valor < 15000.0){
			printf("\n\nIntroduza o valor: ");fflush(stdin);
			fgets(valStr, 14, stdin);
			valStr[strcspn(valStr, "\n")] = '\0';
			
			while(!isFloat(valStr)){
				printf("\n\nIntroduza o valor: ");fflush(stdin);
				fgets(valStr, 14, stdin);
				valStr[strcspn(valStr, "\n")] = '\0';
			}
			
			valor = atof(valStr);
		}
	}
	
	sprintf(n_conta, "%s+%d", BANO, tel);
	
	if(is_CLI_in(n_conta) || is_CLI_in3(n_bi)){
		printf("\n\nA conta %s j� foi criada ou o cliente %s j� existe!\n\n",
		n_conta, n_bi);
		system(pause);
		menuSys();
	}
	
	inserirF(iniCli(nome, dat_nasc, tel, valor, n_bi, n_conta, gen,
	criaData()));
	printf("\n\nAbertura de conta efetuada com sucesso...\n\n");
	system(pause);
	menuSys();
}

void abreContaKid(CLI *cl){
	char nome[80];
	unsigned short int i;
	DATA d_nasc;
	char ced[11];
	char gen;
	long int tel;
	double val;
	char n_conta[15], data[11];
	DATA d=criaData();
	
	setlocale(LC_ALL, "Portuguese");
	system(limpa);
	printf("=====================Abertura De Conta Kid=====================");
	
	printf("\nIntroduza o seu nome: ");fflush(stdin);
	fgets(nome, 80, stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	while(!isNome(nome)){
		printf("\nIntroduza o seu nome: ");fflush(stdin);
		fgets(nome, 80, stdin);
		nome[strcspn(nome, "\n")] = '\0';
	}
	
	printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
	fgets(data, 11, stdin);d_nasc = strToData(data);
	data[strcspn(data, "\n")] = '\0';
	i = d.a - d_nasc.a;
	
	while(i > 11){
		printf("\nIntroduza a sua data de nasc.(01/01/1970): ");fflush(stdin);
		fgets(data, 11, stdin);d_nasc = strToData(data);
		data[strcspn(data, "\n")] = '\0';
		i = d.a - d_nasc.a;
	}
	
	while(!(gen == 'M' || gen == 'F')){
		printf("\nQual o seu g�nero(M/F): ");fflush(stdin);
		gen = getchar();
	}
	
	tel = cl->tel;
	val = 20000.0;
	cl->valor -= 20000.0;
	
	printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
	fgets(ced, 10, stdin);
	ced[strcspn(ced, "\n")] = '\0';
	
	while(!isCED(ced)){
		printf("\nIntroduza o n�mero da c�dula: ");fflush(stdin);
		fgets(ced, 10, stdin);
		ced[strcspn(ced, "\n")] = '\0';
	}
	
	if(is_KID_in(ced)){
		printf("\n\nO n�mero da c�dula j� est� registado.\n\n");
		system(pause);
		menuCli(cl);
	}
	
	strcpy(n_conta, cl->n_conta);
	
	inserirF_KID(iniKID(nome, ced, gen, tel, val, n_conta, d_nasc, d, i));
	printf("\n\nAbertura de conta efetuada com sucesso...\n\n");
	system(pause);
	menuCli(cl);
}

int strcountc(char *s, char c){
	int i, qt=0;
	for(i=0; s[i]!='\0'; i++){
		if(s[i] == c) qt++;
	}
	
	return qt;
}

int isFloat(char *s){
	int i, qt=0;
	
	if(!strlen(s)) return 0;
	if(!isdigit(s[0]) && !isdigit(s[strlen(s)-1])) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(isdigit(s[i])) qt++;
	}
	
	if(qt != strlen(s)){
		if(strcountc(s, ',') == 0 && strcountc(s, '.') == 0) return 0;
	}
	
	if(strcountc(s, '.')){
		s[strcspn(s, ".")] = ',';
	}
	
	return qt >= strlen(s)-1;
}

int isNome(char *s){
	int i, qt=0;
	
	if(strlen(s) < 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(isdigit(s[i])) return 0;
		if(isalpha(s[i]) || isspace(s[i])) qt++;
	}
	
	return qt == strlen(s);
}

int isTel(char *s){
	int i;
	
	if(strlen(s) != 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(!isdigit(s[i])) return 0;
	}
	
	if(atoi(s) < 920000000 || atoi(s) > 999999999) return 0;
	
	return 1;
}

int isBI(char *s){
	int i;
	
	if(strlen(s) != 14) return 0;
	if(!isalpha(s[10]) || !isalpha(s[9])) return 0;
	if(!isupper(s[10]) || !isupper(s[9])) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(ispunct(s[i])) return 0;
		if(i == 9 || i == 10) continue;
		if(!isdigit(s[i])) return 0;
	}
	
	return 1;
}

int isCED(char *s){
	int i;
	
	if(strlen(s) != 9) return 0;
	
	for(i=0; s[i]!='\0'; i++){
		if(!isdigit(s[i])) return 0;
	}
	
	return 1;
}
/*Fim de Outras Fun��es*/

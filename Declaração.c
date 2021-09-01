#include "Declaração.h"

/*Funções de Data*/
int bissexto(int ano){
	return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
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
		case 3: printf("\n%d de Março de %d\n", d.d, d.a); return 1;
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

DATA criaData(){
	DATA d;
	char s[12], dia[]="01", mes[]="Jan", ano[]="2021";
	int i, d_, m, a;
	
	strcpy(s, __DATE__);
	for(i=d_=m=a=0; s[i]!='\0'; i++){
		if(s[i] == ' ') continue;
		
		if(i < 3 && s[i]!=' '){
			mes[m++] = s[i];
		}
		
		if(i > 3 && i < 6 && s[i]!=' '){
			dia[d_++] = s[i];
		}
		
		if(i > 6 && s[i]!=' '){
			ano[a++] = s[i];
		}
	}
	mes[m] = '\0';
	dia[d_] = '\0';
	ano[a] = '\0';
	
	d.d = atoi(dia);
	d.a = atoi(ano);
	
	switch(mes[0]){
		case 'J':
			if(mes[1] == 'a'){
				d.m=1;
				break;
			}
			if(mes[2] == 'n'){
				d.m=6;
				break;
			}
			d.m=7; break;
		
		case 'F': d.m=2; break;
		
		case 'M':
			if(mes[2] == 'r'){
				d.m=3;
				break;
			}
			d.m=3; break;
		
		case 'A':
			if(mes[1] == 'p'){
				d.m=4;
				break;
			}
			d.m=8; break;
		
		case 'S': d.m=9; break;
		
		case 'O': d.m=10; break;
		
		case 'N': d.m=11; break;
		
		case 'D': d.m=12; break;
	}
	
	return d;
}
/*Fim de Funções de Data*/

/*Funções de Cliente*/
CLI *iniCli(char *nome, DATA nasc, int tel, int val, int bi, int gen){
	CLI *cliente = (CLI *) malloc(sizeof(CLI));
	
	if(cliente != NULL){
		strcpy(cliente->nome, nome);
		cliente->dat_nasc = nasc;
		cliente->tel = tel;
		cliente->valor = val;
		cliente->n_bi = bi;
		cliente->gen = gen;
	}
	
	return cliente;
}
/*Fim de Funções de Cliente*/

/*Funções de Conta*/
CONTA *iniConta(CLI *cliente){
	CONTA *c = (CONTA *) malloc(sizeof(CONTA));
	
	if(c != NULL){
		c->cliente = cliente;
		c->n_conta = c->cliente->tel + BANO;
		c->data_cri = criaData();
	}
	
	return c;
}

void criaConta(){
	int bi, tel, valor, dia, mes, ano;
	char nome[50], gen;
	DATA nasc;
	
	printf("Introduza o seu nome: ");fflush(stdin);
	fgets(nome, 49, stdin);
	
	printf("Gênero(M/F): ");scanf(" %c", &gen);
	
	printf("Introduza o seu número de tel.: ");
	scanf("%9d", &tel);fflush(stdin);
	
	printf("Introduza o dia");
}
/*Fim de Funções de Conta*/

/*Outras Funções*/
void menu(){
	system(limpa);
	printf("==============")
	printf("\t1- Cliente\n\t2- Sistema\n\t3- Sair\n");
}
/*Fim de Outras Funções*/

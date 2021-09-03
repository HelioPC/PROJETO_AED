/*ESCREVA AQUI AS INSTRUÇÕES DE PRÉ-PROCESSAMENTO (INCLUDES E DEFINES)*/

#ifndef __DEC_H__
	#include <stdio.h>
	#include <stdlib.h>
	#define __DEC_H__
	#define MAX 150
	#define BANO "BANO"
	
	#ifdef __unix__
		#define limpa "clear"
		#define _pause() getchar()
	#else
		#include <windows.h>
		#define limpa "cls"
		#define _pause() system("pause")
	#endif
	
	/*ESCREVA AQUI OS TIPOS, ESTRUTURAS, VARIÁVEIS GLOBAIS*/
	
	/*Definição De Tipos*/
	#ifdef __ALL_TYPES__
		typedef struct{
			int d, m, a;
		}DATA;
		
		typedef struct{
			char nome[80];
			DATA dat_nasc, d;
			long int tel;
			double valor;
			char gen;
			char n_conta[15], n_bi[16];
		}CLI;
		
		typedef struct noC{
			CLI cliente;
			struct noC *prox;
		}NOCli;
		
		typedef NOCli *LISTACLI;
		
		typedef struct{
			char n_conta[15];
			char tipo[MAX*2];
			DATA data;
		}HIST;
		
		typedef struct noH{
			HIST h;
			struct noH *prox;
			struct noH *ant;
		}NOHIST;
		
		typedef NOHIST *LISTAHIST;
		
		typedef struct{
			char nome[80];
			DATA dat_nasc;
			unsigned short int idade;
			char gen;
			long int tel;
			double valor;
			char n_conta[15], n_ced[11];
			DATA d;
		}CONTA_KID;
		
		typedef struct{
			CONTA_KID kid[MAX];
			int qt;
		}LISTA_KID;
	#endif
	/*Fim De Definição De Tipos*/
	
	/*Definição De Protótipos*/
	
	/*Protótipos Das Listas Ligadas (e duplamente e seus nós)*/
	#ifdef __INI_FUNC__
		void iniLCLI();
		void iniLHIST();
		void iniLKID();
	#endif

	#ifdef __LL_FUNC__
		int tam();
		int vazia();
		int inserirK(CLI cli);
		int inserirI2(LISTACLI *lc, CLI cli);
		int removeK(char *n_conta);
		int getCLI_pos(CLI cl);
		int is_CLI_in(char *n_conta);
		int is_CLI_in2(LISTACLI *lc, CLI cli);
		int is_CLI_in3(char *n_bi);
	#endif

	#ifdef __LDL_FUNC__
		int tamLH();
		int vaziaLH();
		int inserirF_LH(HIST h);
		int qtHIST(CLI *cl);
	#endif
	/*Fim De Protótipos Das Listas (e duplamente) Ligadas (e seus nós)*/
	
	/*Protótipos Das Listas Sequenciais*/
	#ifdef __LS_FUNC__
		int tam_KID();
		int vazia_KID();
		int cheio_KID();
		int inserirI_KID(CONTA_KID ck);
		int inserirF_KID(CONTA_KID ck);
		int inserirK_KID(CONTA_KID ck, int k);
		int removeI_KID();
		int removeF_KID();
		int removeK_KID(int k);
		int rmKID(char *n_conta);
		int is_KID_in(char *ced);
	#endif
	/*Fim De Protótipos Das Listas Sequenciais*/
	
	/*Protótipos De Data*/
	#ifdef __DT_FUNC__
		DATA criaData();
		DATA strToData(char *s);
		int bissexto(int ano);
		int isData(DATA d);
		int equalsDATA(DATA d1, DATA d2);
		int mostraData(DATA d);
	#endif
	/*Fim De Protótipos De Data*/
	
	/*Protótipos De Cliente*/
	#ifdef __CLI_FUNC__
		CLI iniCli(char *nome, DATA nasc, long int tel, double val, char *bi,
		char *n_cont, char gen, DATA d);
		CLI *getCLI(char *n_conta);
		void mostraCLI();
		void _mostraCLI(CLI *cl);
		void mostraCLI_by_DATA(DATA d);
		void mostraCLI_idade(unsigned short int x, unsigned short int y);
		int transferir(CLI *cl, double val, char *n_conta);
		int depositar(CLI *cl, double val);
		void consultar(CLI *cl);
		int levantar(CLI *cl, double val);
		int depositarKID(CLI *cl, char *ced, double val);
		void hist(CLI *cl);
		int temKID(CLI *cl);
		int qtKID(CLI *cl);
		void cli_n_KID(unsigned short int n);
		void rank_mais_act();
		int valor_menor_n(double v);
		void mostraCLI_alf();
		void abreConta();
		void abreContaKid(CLI *cl);
		void debitar_ALL();
	#endif
	/*Fim De Protótipos De Cliente*/
	
	/*Protótipos de Conta Kid*/
	#ifdef __CLIK_FUNC__
		CONTA_KID iniKID(char nome[80], char *n_ced, char gen, long int tel,
		double val, char *n_conta, DATA dat_n, DATA d, unsigned short int i);
		CONTA_KID *getKID(char *ced);
		void mostraKID();
	#endif
	/*Fim de Protótipos de Conta Kid*/
	
	/*Protótipos De Histórico*/
	#ifdef __HST_FUNC__
		void mostraHIST_by_DATA(DATA d, CLI *cl);
		void mostraHIST_by_OP(CLI *cl);
		void mostraHIST_by_CLI(char *n_conta);
	#endif
	/*Fim De Protótipos De Histórico*/
	
	/*Outros Protótipos*/
	#ifdef __MN_FUNC__
		void menu();
		void menuSys();
		void menuCli(CLI *cl);
		void menuHist(CLI *cl);
	#endif

	#ifdef __AUX_FUNC__
		int strcountc(char *s, char c);
		int isFloat(char *s);
		int isNome(char *s);
		int isTel(char *s);
		int isBI(char *s);
		int isCED(char *s);
	#endif
	/*Fim De Outros Protótipos*/
	
	/*Fim De Definição De Protótipos*/

#endif

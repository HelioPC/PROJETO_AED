#include <locale.h>
#define __ALL_TYPES__
#include "Declaração.h"

LISTACLI *LCL;
LISTAHIST *LHS;
LISTA_KID *LKD;

int main(){
	setlocale(LC_ALL, "Portuguese");

	iniLCLI();
	iniLHIST();
	iniLKID();

	menu();
	
	return 1;
}

#include <locale.h>
#define __ALL_TYPES__
#define __INI_FUNC__
#define __MN_FUNC__
#include "Declaração.h"

int loaded;
LISTACLI *LCL;
LISTAHIST *LHS;
LISTA_KID *LKD;

int main(){
	loaded = 0;
	setlocale(LC_ALL, "Portuguese");

	iniLCLI();
	iniLHIST();
	iniLKID();

	menu();
	
	return 1;
}

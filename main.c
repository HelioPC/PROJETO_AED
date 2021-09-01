#include "Método.h"

int main(){
	#ifndef __unix__
		unsigned int cp = 1252;
		unsigned int cpin = GetConsoleCP();
		unsigned int cpout = GetConsoleOutputCP();
		system("color 0A");
		SetConsoleCP(cp);
		SetConsoleOutputCP(cp);
		printf("%d %d", cpin, cpout);
	#endif
	setlocale(LC_ALL, "Portuguese");
	
	
	iniLCLI();
	iniLHIST();
	iniLKID();
	
	menu();
	
	return 1;
}

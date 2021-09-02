#include <time.h>
#define __ALL_TYPES__
#define __DT_FUNC__
#include "Declaração.h"

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

/*DATA criaData(){
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
}*/

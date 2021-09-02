#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
#include <stdio.h>
#ifdef __unix__
    #define __COLORS__
#endif
#include "Declaração.h"

void goodbye(){
    system(limpa);

    #ifdef __unix__
        printf("%s", RED_A);
    #endif

    printf(
    "\t\t         ____________"
    "\n\t\t        /            \\"
    "\n\t\t       /              \\"
    "\n\t\t    /\\/	               \\/\\"
    "\n\t\t    \\ |   ****   ****  | /"
    "\n\t\t     \\|   ****   ****  |/"
    "\n\t\t      |   ***     ***  |"
    "\n\t\t      |                |"
    "\n\t\t      \\_      ***     _/"
    "\n\t\t        |\\    ***   /|"
    "\n\t\t        | |        | |"
    "\n\t\t        | IIIIIIIIII |"
    "\n\t\t        | IIIIIIIIII |"
    "\n\t\t        \\_          _/"
    "\n\t\t          \\_      _/"
    "\n\t\t            \\___/\n\n"
    );

    #ifdef __unix__
        printf("%s", GREEN_A);
    #endif
    printf("\t\t\tSee you next time.\n");
    printf("\n\t\tBANCO BANO COPYRIGHT 2021-2022");
    #ifdef __unix__
        printf("%s", NORM);
    #endif
}

void opsucess(){
    printf("\n\nOperação feita com sucesso...");
}

void getaccountnumber(){
    printf("\nIntroduza o número da conta: ");
}
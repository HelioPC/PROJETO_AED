#include <stdio.h>
#define __COLORS__
#include "Declaração.h"

void goodbye(){
    system(limpa);

    printf("%s", RED_A);

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
    "\n\t\t            \\____/\n\n"
    );

    printf("%s", GREEN_A);
    printf("\t\t\tSee you next time.\n");
    printf("\n\t\tBANCO BANO COPYRIGHT 2021-2022");
    printf("%s", NORM);
}

void opsucess(){
    printf("\n\nOperação feita com sucesso...");
}

void getaccountnumber(){
    printf("\nIntroduza o número da conta: ");
}

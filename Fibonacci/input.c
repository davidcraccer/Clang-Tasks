#include <stdio.h>
#include <stdlib.h>
#include "input.h" 

int lese_int(){
    int nummer = 0;
    int ret = 0;
    char c;
    prinf("bitte geben Sie eine Nummer ein: ");
    while (ret==0){
        ret = scanf("%d%c", &nummer, &c);
        while (c != '\n' && getchar() != '\n');
        if (ret == 0)
        printf("\nDas was keine Nummer. Versuchen Sie erneuet: ");

    }
    return nummer;
}
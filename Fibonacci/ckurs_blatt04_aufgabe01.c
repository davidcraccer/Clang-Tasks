#include <stdio.h>
#include <stdlib.h>
#include "input.h" 

int fibonacci1 (int zahl){
    int result = 1;
    for (int i =2; i <= zahl; i++){
        result = result + i;
    }
    return result;
}

int fibonacci2 (int zahl){
    
    if (zahl == 1){
        return 1;
    }
    if (zahl == 2){
        return 1;
    }
    int result = fibonacci2(zahl-2) + fibonacci2(zahl-1);
    return result;
}

int main(){
    int n = lese_int() ;
    int f = fibonacci2(n);
    printf("Fib(%d) = %d\n" , n, f);
    return 0;
}







 
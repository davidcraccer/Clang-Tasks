#include <stdio.h>
#include <stdlib.h>
#include "input2.h"
#include <math.h>

int main()
{
    int n = lese_int(); //Hier Nummer eingeben
    int limit = sqrt(n);  //optimizing the code
    int laenge = n-1;


    int num[n], i, j;

    for (i = 0; i < n; i++) //i ist die Nummer
        num[i] = i + 1;

    for (i = 1; i < limit; i++)
    {
        if (num[i] != 0)
        {
            for (j = pow(num[i], 2); j <= n; j = j + num[i]) //striking numbers that arent Primzahle (zb 2*2=4, 4<=n, j=4+2)
            {
                num[j - 1] = 0;//assign die nicht Primzahle als 0
            }
        }
    }

    for (i = 1; i < n; i++)
    {
        if (num[i] != 0)
            printf("%d\t", num[i]);
    }
    printf("\n");
    return 0;
}

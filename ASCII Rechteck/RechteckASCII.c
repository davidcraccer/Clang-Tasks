#include <stdio.h>
#include <stdlib.h>

int main()
{
    int breite = 6;
    int hoehe = 3;

    for (int i = 0; i < hoehe; i++)
    {
        for (int j = 0; j < breite; j++)
        {
            if (i == 0 || i == hoehe - 1 || j == 0 || j == breite - 1)
            {
                printf("A");
            }
            else
            {
                printf("B");
            }
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int len)
{
    printf("Array: ");
    for (int i = 0; i < len; i++)
    {
        if (i < len - 1)
        {
            printf("%d, ", array[i]);
        }
        else
        {
            printf("%d\n", array[i]);
        }
    }
}




int main()
{
    int array[] = {9, 4, 7, 8, 10, 5, 1, 6, 3, 2};
    int len = 10;
    int sum = 0;
    
    print_array(array, len);
// Minimum
    int min = array[0];
    for (int i = 0; i < len; i++)
    {

        if (array[i] < min)
            min = array[i];
    }
    printf("Minimum: %d\n", min);
// Maximum
    int max = array[0];

    for (int i = 0; i < len; i++)
    {

        if (array[i] > max)
            max = array[i];
    }
    printf("Maximum: %d\n", max);
//Sum
for (int i = 0; i < len; i++) {   
       sum = sum + array[i];  
    }    
    printf("Summe: %d\n", sum);  
   
  

    return 0;
}









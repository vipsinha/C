#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	
    int num1, num2;
    float flt1, flt2;
    
    scanf("%d %d", &num1, &num2);
    scanf("%f %f", &flt1, &flt2);
    
    printf("%d %d", (num1+num2), (num1-num2));
    printf("\n");
    printf("%0.1f %0.1f", (flt1+flt2), (flt1-flt2));
    
    return 0;
}
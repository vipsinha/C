#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char ch;
    char charstring[MAX_LEN];
    char sen[MAX_LEN];
    
    scanf("%c", &ch);
    scanf("%s\n", charstring);
    scanf("%[^\n]%*c", sen);
    
    printf("%c\n", ch);
    printf("%s\n", charstring);
    printf("%s", sen);
    
    return 0;
}
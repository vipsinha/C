// Date: 2020-12-06
// Function pointer

#include <stdio.h>
#define SIZE 3


int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main(){

    int choice = 0;
    int num1 = 0, num2 = 0;
    int (*funcptr[3])(int, int) = {add, sub, mul};

    printf("Enter the choice\n");
    printf("1-Addition\n");
    printf("2-Substraction\n");
    printf("3-Multiplication\n");

    scanf("%d", &choice);

    if ((choice > 3) || (choice < 1))
        return 0;

    choice -= 1;
    printf("Enter two numbers\n");
    scanf("%d%d", &num1, &num2);
    
    printf("The result is = %d\n",(*funcptr[choice])(num1, num2));

    return 0;
}

int add(int a, int b){
    return(a+b);
}

int sub(int a, int b){
    return(a-b);
}

int mul(int a, int b){
    return(a*b);
}
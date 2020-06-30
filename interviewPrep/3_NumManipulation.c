//
//  main.c
//  3_NumManipulation
//
//  Created by Vipul Sinha on 27/05/17.
//  Copyright © 2017 Vipul Sinha. All rights reserved.
//

#include <stdio.h>

#define INT_SIZE (8)

#define SET_RESET_BIT(Num,BitPos,SetReset)   ((SetReset == 1)? (Num = Num | (1 << BitPos)) : (Num = Num & (~( 1 << BitPos))))

void MirrorNumber(int *Num);
void SizeofCheck(int *Num);
void ReverseNumber(int *Num);
void NumberofOnes(int *Num);
void SetResetNum(int *Num);


int main(int argc, const char * argv[]) {
    
    int Number = 0;
    // insert code here...
    printf("Number Manipulation!\n");
    
    printf("Enter the number\n");
    scanf("%d", &Number);
    
    //MirrorNumber(&Number);
    //SizeofCheck(&Number);
    //ReverseNumber(&Number);
    //NumberofOnes(&Number);
    SetResetNum(&Number);

    return 0;
}

void MirrorNumber(int *Num)
{
    int arr[INT_SIZE] = {0};
    int count = 0;
    
    while (*Num != 0) {
        arr[count] = *Num % 10;
        *Num = *Num/10;
        count++;
    }
    for(count = 0;count < INT_SIZE; count++)
    {
        printf("Reverse Arr[%d] = %d\n", count, arr[count]);
    }
}

void SizeofCheck(int *Num)
{
    char *ch = (char *)'a';
    int *in = (int *)1;
    float *fl = (float *)81;
    
    
    printf("size of char = %ld\n", sizeof(*ch));
    printf("size of char_ptr = %ld\n", sizeof(ch));
    
    printf("size of int = %d\n", (int)sizeof(*in));
    printf("size of int_ptr = %d\n", (int)sizeof(in));
    
    printf("size of float = %d\n", (int)sizeof(*fl));
    printf("size of float_ptr = %d\n", (int)sizeof(fl));
    
    printf("size of Argument = %ld\n", sizeof(*Num));
    printf("size of Argument_ptr = %ld\n", sizeof(Num));
    
    printf("size of TypeCastArgument = %ld\n", sizeof((char)*Num));
    printf("size of TypeCastArgument_ptr = %ld\n", sizeof((char)Num));
}

void ReverseNumber(int *Num)
{
    int RevNumber = 0;
    int temp = 0;
    
    while(*Num != 0)
    {
        temp = *Num % 10;
        *Num = *Num / 10;
        RevNumber = RevNumber * 10 + temp;
    }
    printf("Reverse Number  = %d\n", RevNumber);
}

void NumberofOnes(int *Num)
{
    int CheckNumber = 0;
    int OneCount = 0;
    
    CheckNumber = *Num & 0xFF;
    while(CheckNumber != 0)
    {
        if((CheckNumber & 0x01) == 0x01)
        {
            OneCount++;
        }
        CheckNumber = CheckNumber >> 1;
        //printf("%x\n", CheckNumber);
    }
    printf("One count in Number  = %d\n", OneCount);

}

void SetResetNum(int *Num)
{
    int BitPosition = 0;
    int SetReset = 0;
    int UpdatedNumber = 0;
    
    printf("Enter the bit position and\n1-Set\n0-Reset\n");
    scanf("%d%d",&BitPosition,&SetReset);
    
    UpdatedNumber = SET_RESET_BIT(*Num, BitPosition, SetReset);
    
    printf("Updated number is = %d\n",UpdatedNumber);

}

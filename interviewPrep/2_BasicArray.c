//
//  main.c
//  2_BasicArray
//
//  Created by Vipul Sinha on 21/05/17.
//  Copyright © 2017 Vipul Sinha. All rights reserved.
//

#include <stdio.h>

#define ARR_SIZE (10)

typedef struct
{
    int min;
    int max;
}ST_MIN_MAX;

int UpdateArray(int *Arr);
void PrintArray(int *Arr, int size);
void SortArray(int *Arr, int size);
void PrimeNumberInArray(int *Arr, int size);
ST_MIN_MAX MinMaxArray(int *Arr, int size);

int Index = 0;

int main(int argc, const char * argv[]) {
    int Array[ARR_SIZE] = {0};
    int size = 0;
    ST_MIN_MAX st_MinMax = {0};
    
    // insert code here...
    printf("Basic array!\n");
    
    size = UpdateArray(&Array[0]);
    PrintArray(&Array[0],size);
    SortArray(&Array[0],size);
    PrintArray(&Array[0],size);
    PrimeNumberInArray(&Array[0], size);
    st_MinMax = MinMaxArray(&Array[0], size);
    
    printf("Max Element of array = %d\n",st_MinMax.max);
    printf("Min Element of array = %d\n",st_MinMax.min);
    return 0;
}

int UpdateArray(int *Arr)
{
    int size = 0;
    printf("Enter the size less than 10\n");
    scanf("%d", &size);
    
    for (Index = 0; Index < size; Index++) {
        printf("Enter the element %d\n", Index+1);
        scanf("%d", &Arr[Index]);
    }
    return (size);
}

void PrintArray(int *Arr, int size)
{
    printf("Array is\n");
    for (Index = 0; Index < size; Index++) {
        printf("Arr[%d] = %d\n",Index, Arr[Index]);
    }
}

void SortArray(int *Arr,int size)
{
    int IndexCompare = 0;
    int SwapTemp = 0;
    printf("Sorted Array is = \n");
    
    for (Index = 0; Index < size-1; Index++) {
        for (IndexCompare = Index+1; IndexCompare < size; IndexCompare++) {
            if (Arr[Index] > Arr[IndexCompare]) {
                SwapTemp = Arr[Index];
                Arr[Index] = Arr[IndexCompare];
                Arr[IndexCompare] = SwapTemp;
            } else {
                
            }
        }
    }
    
}

void PrimeNumberInArray(int *Arr, int size)
{
    int IndexPrime = 0;
    int PrimeCount = 0;
    
    for (Index = 0; Index < size; Index++) {
 
        PrimeCount = 0;
        for (IndexPrime = 1; IndexPrime < 100; IndexPrime++) {
            if((Arr[Index] % IndexPrime) == 0)
            {
                PrimeCount++;
            }
        }
        
        if (PrimeCount <= 2) {
            printf("Prime Number is = %d\n", Arr[Index]);
        }
        
    }
    
}

ST_MIN_MAX MinMaxArray(int *Arr, int size)
{
    ST_MIN_MAX st_MinMax = {0};
    
    st_MinMax.max = Arr[0];
    st_MinMax.min = Arr[0];
    
    for (Index = 0; Index < size; Index++) {
            if (Arr[Index] > st_MinMax.max) {
                st_MinMax.max = Arr[Index];
            }
            if (Arr[Index] < st_MinMax.min) {
                st_MinMax.min = Arr[Index];
            }
    }
    return (st_MinMax);
}

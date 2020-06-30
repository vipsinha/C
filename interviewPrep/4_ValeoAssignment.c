//
//  main.c
//  4_ValeoAssignment
//
//  Created by Vipul Sinha on 27/05/17.
//  Copyright © 2017 Vipul Sinha. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

void ReadTheData(datatype *ArrSize, datatype *FilterData);

int main(int argc, const char * argv[]) {
    
    datatype FilterNumber = 0;
    datatype size = 0;
    //int x = 0;
    
    // insert code here...
    printf("Valeo Assignment\n");
    
    printf("Enter the Filter Number\n");
    scanf("%d",&FilterNumber);
    printf("Enter the size\n");
    scanf("%d",&size);
    
    ReadTheData(&size, &FilterNumber);
    
    /*x = 1 << (FilterNumber-1);
     printf("The range is %d to %d",(int)x,(int)(x-1));
     */
    return 0;
}

void ReadTheData(datatype *ArrSize, datatype *FilterData)
{
    datatype index = 0;
    datatype *arr;
    datatype CalcFilter = 0;
    datatype ArrSum = 0;
    
    CalcFilter = 1 << *FilterData;

    arr = (datatype *)malloc(*ArrSize);
    
    for (index = 0; index < *ArrSize; index++) {
        printf("Enter the element %d\n", index);
        scanf("%d",&arr[index]);
        
        if(arr[index] > CalcFilter)
        {
            ArrSum = ArrSum + arr[index];
        }
    }
    printf("The array sum = %d\n", ArrSum);
    
    free(arr);
}

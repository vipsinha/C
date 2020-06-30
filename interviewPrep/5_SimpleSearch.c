//
//  main.c
//  5_SimpleSearch
//
//  Created by Vipul Sinha on 10/05/17.
//  Copyright © 2017 Vipul Sinha. All rights reserved.
//

#include <stdio.h>
#include <string.h>


#define HAYSTACK_SIZE 6
#define NEEDLE_SIZE 4
#define NULL_PTR ((void*)0)

static char HayStack[HAYSTACK_SIZE][NEEDLE_SIZE]={"Jan","Feb","Mar","Apr","May"};


static int AddNeedle(int Length);
static int DeleteNeedle(int Length);
static void ShowHayStack(int Length);
static int SearchNeedle(int Length);


int main(int argc, const char * argv[]) {
    // insert code here...
    int option = 0;
    static int HayStack_CurrLen = 0;
    int NeedleIndex = 0;
    
    printf("HayStack search!\n");
    
    printf("Choose!\n");
    printf("1-AddNeedle\n");
    printf("2-DeleteNeedle\n");
    printf("3-ShowHayStack\n");
    printf("4-Search&Return\n");
    printf("5-ExitProgram\n");
    
    do
    {
        printf("------Enter the option-------\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                HayStack_CurrLen = AddNeedle(HayStack_CurrLen);
                break;
            case 2:
                HayStack_CurrLen = DeleteNeedle(HayStack_CurrLen);
                break;
            case 3:
                ShowHayStack(HayStack_CurrLen);
                break;
            case 4:
                NeedleIndex = SearchNeedle(HayStack_CurrLen);
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Wrong Option\n");
                break;
        }
        
        printf("Current Length = %d\n",HayStack_CurrLen);
    }while(option != 5);
    
   // SearchNeedle();
    return 0;
}

static int AddNeedle(int Length)
{
    char needle[] = "---";
    int NeedleIndex = 0;
    int NeedleSize = 0;
    
    printf("Enter the needle and needle length should be 3\n");
    scanf("%s", needle);
    
    if(Length == HAYSTACK_SIZE)
    {
        printf("Hay Stack is full\n");
    }
    else
    {
        for(NeedleIndex=0;needle[NeedleIndex]!='\0';++NeedleIndex)
        {
            HayStack[Length][NeedleIndex] = needle[NeedleIndex];
        }
        Length++;
    }
    
    return(Length);
}

static int DeleteNeedle(int Length)
{
    int ArrIndex = 0;
    int NeedleIndex = 0;
    int retLength = 0;
    int HayIndex = 0;

    HayIndex = SearchNeedle(Length);
    
    //if needle is not at the last update the array
    if(HayIndex != (HAYSTACK_SIZE-1))
    {
        for(ArrIndex=HayIndex;ArrIndex<(HAYSTACK_SIZE-1);ArrIndex++)
        {
            for(NeedleIndex=0;HayStack[ArrIndex][NeedleIndex]!='\0';++NeedleIndex)
            {
                HayStack[ArrIndex][NeedleIndex] = HayStack[ArrIndex+1][NeedleIndex];
            }
        }
        retLength = Length-1;
    }
    else
    {
        retLength = Length;
    }
    return(retLength);
}

static void ShowHayStack(int Length)
{
    int Index = 0;
    int NeedleIndex = 0;
    
    printf("HayStack\n");
    for(Index=0;Index<Length;Index++)
    {
        printf("%s\n",HayStack[Index]);
    }
    printf("\n");
}

static int SearchNeedle(int Length)
{
    int Index = 0;
    int NeedleIndex = 0;
    char SearchNeedle[] = "Search Needle";
    int *NeedleAdd = NULL_PTR;
    int NeedleFound = 0;

    printf("Enter the needle to be searched\n");
    scanf("%s",SearchNeedle);
    
    while(Index<Length)
    {
        //Needle is found
        if(SearchNeedle[0] == HayStack[Index][0])
        {
            for(NeedleIndex=0;SearchNeedle[NeedleIndex]!='\0';NeedleIndex++)
            {
                if(SearchNeedle[NeedleIndex] == HayStack[Index][NeedleIndex])
                {
                    NeedleFound = 1;
                    NeedleAdd = (int*)HayStack[Index];
                }
                else
                {
                    NeedleFound = 0;
                    NeedleAdd = (int *)NULL_PTR;
                    break;
                }
            }
            break;
        }
        else
        {
            NeedleFound = 0;
            Index++;
        }
    }
    
    printf("Needle Status = %d\n",NeedleFound);
    printf("Needle Index = %d\n",Index);
    if(NeedleFound != 0)
    {
        printf("Needle Address = %d\n",*NeedleAdd);
    }
    else
    {
        printf("Needle is not found");
    }
    
    return(Index);
}

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float n;
    int remainQ = 0;
    int remainD = 0;
    int remainN = 0;
    int remainP = 0;
    
    
    do
    {
        
        n = get_float("loose change: "); //input from user 
    
    }
    while (n < 0);
    
    {
        int cents = round(n * 100); //rounding 
        //printf("ok %d \n", cents);
        while (cents >= 25) //loop checking if 25c can be used
        {
            cents = cents - 25;
            remainQ++;
        }
        
        while (cents >= 10) //loop checking if 10c can be used
        {
            cents = cents - 10;
            remainD++;
        }
        
        while (cents >= 5)  //loop checking if 5c can be used
        {
            cents = cents - 5; 
            remainN++;
        }
        
        while (cents >= 1)  //loop checking if 1c can be used
        {
            cents = cents - 1; 
            remainP++;
        }
        
        
        int remain = remainQ + remainD + remainN + remainP; //calculation of least coins needed to change 
        
        printf("number of coins returned %d\n", remain);  //print number of coins
    }








}
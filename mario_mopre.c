#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
 
    do

    {
        n = get_int("give me Height: "); //get input from user
    }
    while (n < 1 || n > 8); //loop, if less than 1 than run again
    {
        for (int i = 1; i <= n; ++i) // loop for vertical adding
        {
            for (int k = n ; k > i; --k)
            {
                printf(" ");
            }
            for (int j = 1; j <= i; ++j) // loop for horizontal adding
            {
                printf("#");
            }
            printf("  ");
            for (int l = 1; l <= i; ++l) // loop for horizontal adding
            { 
                printf("#");
            }
            printf("\n");
        }
    
    }
}
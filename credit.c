#include <stdio.h>
#include <cs50.h>


int main(void)
{
    long n;
    int remain = 0;
    int count = 0;
    int suma1 = 0;
    int suma2 = 0;
    int mod1 = 0;
    int mod2 = 0;


    n = get_long("Credit Card Number Check: ");

    long cred = n;
    while (cred > 0) //loop checking lenght of card number
    {
        cred = cred / 10;
        remain++;
    }

    if (remain == 13 || remain == 15 || remain == 16) //check if card number is valid
    {
        printf("valid card number\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    long i = n;         
    do                  // looping thru card to find digits for checksun
    {
        mod1 = i % 10;
        i = i / 10;
        suma1 = suma1 + mod1;

        mod2 = (i % 10) * 2;
        i = i / 10;
        if (mod2 > 9)
        {
            mod2 = mod2 - 9;
           
        }
        suma2 = suma2 + mod2;

    
    }
    while (i > 0);


    int total = suma1 + suma2;
    if (total % 10 != 0) //checksum of card
    {
        printf("INVALID\n");
        return 0;
    }
    
    long check = n;
    
    while (check > 100)
    {
        check = check / 10;
    }
    //checks card issuer
    if ((check / 10 == 5) && (0 < check % 10 && check % 10 < 6)) 
    {
        printf("MASTERCARD\n");
    }
    
    else if ((check / 10 == 3) && (check % 10 == 4 || check % 10 == 7))
    {
        printf("AMEX\n");
    }
    
    else if (check / 10 == 4)
    {
        printf("VISA\n");
    }
    
    else 
    {
        printf("INVALID\n");
    }
    


}
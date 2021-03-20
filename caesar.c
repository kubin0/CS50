#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, string argv[])
{
    int sum;

    if (argc == 2)
    {
        // Iterates on the key in command line and ensures it is a positive integer
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            // Returns error message if key includes anything other than digits
            if (isdigit(argv[1][j]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        string plain = get_string("planitext: ");

        int d = atoi(argv[1]);
        int cipher;

        printf("ciphertext: ");
        for (int i = 0; i < strlen(plain); ++i)
        {
            if (isalpha(plain[i]) != 0)
            {
                if (isupper(plain[i]) != 0)
                {
                    sum = (int)plain[i];
                    cipher = (sum + d - 65) % 26 + 65;
                    char s = cipher;
                    printf("%c", cipher);
                }
                else
                {
                    sum = (int)plain[i];
                    cipher = (sum + d - 97) % 26 + 97;
                    char s = cipher;
                    printf("%c", cipher);
                }

            }
            else
            {
                printf("%c", plain[i]);
            }
        }
        printf("\n");






    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
}



















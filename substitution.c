#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, string argv[])
{
    int sum;
    int same[26] = {0};

    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    int inputlenght = strlen(argv[1]);

    for (int i = 0; argv[1][i] != '\0'; ++i)
    {

        if (islower(argv[1][i]))
        {
            same[argv[1][i] - 97]++;    //if is the same value (in ascii) then it will write +1 to i
        }
        else if (isupper(argv[1][i]))
        {
            same[argv[1][i] - 65]++;
        }
    }

    for (int i = 0; i < inputlenght; ++i)
    {
        if (inputlenght != 26 || !(isalpha(argv[1][i])) || same[i] != 1)
        {
            printf("Invalid key\n");
            return 1;
        }

    }

    string plain = get_string("plaintext: ");
    int plainlenght = strlen(plain);
    printf("ciphertext: ");
    for (int i = 0; i < plainlenght; ++i)
    {
        if (islower(plain[i]))
        {
            plain[i] = tolower(argv[1][plain[i] - 97]);
        }
        else if (isupper(plain[i]))
        {
            plain[i] = toupper(argv[1][plain[i] - 65]);
        }
        else
        {
            continue;
        }
    }
    printf("%s", plain);
    printf("\n");


    return 0;
}


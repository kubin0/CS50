#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>



int main(void)
{
    string text = get_string("Text: ");
    int word = 0;
    int letter = 0;
    int sentence = 0;

    for (int k = 0; text[k] != '\0'; ++k)
    {
        if (isalpha(text[k])) //check if a letter, if yes count +1
        {
            ++letter;
        }
    }
//printf ("letters: %d\n", letter);

    for (int i = 0; text[i] != '\0'; ++i)
    {
        if (text[i] == ' ' && text[i + 1] != ' ') // number of words in string
        {
            ++word;
        }
    }
    word = word + 1;

//printf ("words: %d\n", word);

    for (int j = 0; text[j] != '\0'; ++j)
    {
        if (text[j] == '.' || text[j] == '!' || text[j] == '?') // number of sentences in string
        {
            ++sentence;
        }
    }
//printf ("sentences: %d\n", sentence);

    float L, S;
//calculating L and S
    L = (float)letter / word * 100; 
    S = (float)sentence / word * 100;

//printf ("l and S: %f %f\n", L, S);
//calculates CL index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %d\n", grade);

    }
}
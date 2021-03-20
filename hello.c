#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("tell me your name\n"); //get input from user
    printf("hello %s\n", name); //print hello + user input
}
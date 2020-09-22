// Libraries
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name?\n"); //Variable name = Prompt
    printf("Hello, %s\n", name); //Output
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;
    do
    {
        size = get_int("Height: \n"); //Prompt
    }
    while (size < 1 || size > 8); //Repeat Prompt if size its wrong
    
    for (int j = 0; j < size; j++) 
    {
        for (int c = j + 1; c < size; c++) //Condition for space 
        {
            printf(" ");
        }
        for (int i = size - j; i <= size; i++) //Condition for #
        {
            printf("#");
        }
        printf("\n"); // Jump
    }
}

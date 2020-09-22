#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool keyValue(string text);

int main(int argc, string argv[])
{
    if (argc != 2 || !keyValue(argv[1]))
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    else
    {
        // String to int
        int num = atoi(argv[1]);
        //Prompt
        string promptText = get_string("plaintext: ");
        //Output
        printf("ciphertext: ");
        //Caesar
        for (int i = 0, lenght = strlen(promptText); i < lenght; i++)
        {
            // c = Character from Prompt
            char c = promptText[i];
            if (isalpha(c))
            {
                // Char
                char mod = 'A';
                if (islower(c))
                {
                    mod = 'a';
                }
                printf("%c", (c - mod + num) % 26 + mod);
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }
}

//Function to validate key
bool keyValue(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)

        if (!isdigit(text[i]))
        {
            return false;
        }
    return true;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Prompt
    string text = get_string("Text: ");
    //Total:
    int letter = 0;
    int word = 1;
    int sentence = 0;


    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            //Count Letter
            letter++;
        }
        if (text[i] == ' ')
        {
            //Count Word
            word++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            //Count Sentence
            sentence++;
        }
    }
    // The Coleman-Liau 
    float grade = 0.0588 * (100 * (float) letter / (float) word) - 0.296 * (100 * (float) sentence / (float) word) - 15.8;

    //Return
    if (grade > 16)
    {
        printf("Grade 16+\n");
    } 
    
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else 
    {
        printf("Grade %0.f\n", round(grade)); 
    }
}
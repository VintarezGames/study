#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

string text;
int count_letters(string ctext);
int count_words(string etext);
int count_sentences(string stext);

int main(void)
{
    text = get_string("Text: ");
    float letters = count_letters(text);

    float words = count_words(text);

    float sentences = count_sentences(text);

    //index formula here
    float L = letters/words * 100;
    float S = sentences/words * 100;
    float index = (0.0588 * L - 0.296 * S - 15.8);
    int final = round(index);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", final);
    }
}

//number of letters in input
int count_letters(string ctext)
{
    int count = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

//number of words in input
int count_words(string etext)
{
    int count = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentences(string stext)
{
    int count = 0;
    for (int i = 0; i <= strlen(text); i++)
    {
        if (ispunct(text[i]))
        {
            if (text[i] == 46)
            {
                count++;
            }
            else if (text[i] == 33)
            {
                count++;
            }
            else if (text[i] == 63)
            {
                count++;
            }
        }
    }
    return count;
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int index(string t);
void grade(int a);

int main(void)
{ // to upper the compiler input
    string text = get_string("Text: ");
    for (int i = 0, n = strlen(text); i < n; i++)
        {
            text[i] = toupper(text[i]);
        }
    int score = index(text);
    grade(score);
}

int index(string t)
{
    int letters = 0;
    int space = 0;
    int period = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
        if (t[i] >= 65 && t[i] <= 90)
        {
            letters += 1;
        }
        else if (t[i] == 32)
        {
            space += 1;
        }
        else if (t[i] == 46 || t[i] == 33 || t[i] == 63)
        {
            period += 1;
        }
    float words = space + 1;
    float L = letters * 100/words;
    float S = period * 100/words;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    //printf("%f\n", index);
    int indexint = (int) round(index);
    return indexint;
}

void grade(int a)
{   if (a < 2)
        {
            printf("Before Grade 1\n");
        }
    else if (a <= 16)
        {
            printf("Grade %i\n", a);
        }
    else
        {
            printf("Grade 16+\n");
        }
}


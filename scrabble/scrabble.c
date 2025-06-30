#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int value(string q);

int main(void)
{ // to upper the compiler input
    string s = get_string("Player 1: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
    }

    string t = get_string("Player 2: ");
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        t[i] = toupper(t[i]);
    }

    // set conditions: if score(x) >/</= score(y) print"a/b/c/":
    if (value(s) > value(t))
    {
        printf("Player 1 wins!\n");
    }
    else if (value(s) < value(t))
    {
        printf("Player 2 wins!\n");
    }
    else if (value(s) == value(t))
    {
        printf("Tie!\n");
    }
    // printf("Player 1 score: %i\n", value(s));
    // printf("Player 2 score: %i\n", value(t));
}

int value(string q)
{
    int score = 0;
    for (int i = 0, n = strlen(q); i < n; i++)
        if (strchr("AEIOULNRST", q[i]))
        {
            score += 1;
        }
        else if (strchr("DG", q[i]))
        {
            score += 2;
        }
        else if (strchr("BCMP", q[i]))
        {
            score += 3;
        }
        else if (strchr("FHVWY", q[i]))
        {
            score += 4;
        }
        else if (strchr("K", q[i]))
        {
            score += 5;
        }
        else if (strchr("JX", q[i]))
        {
            score += 8;
        }
        else if (strchr("QZ", q[i]))
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
    // printf("Score: %i\n", score);
    return score;
}

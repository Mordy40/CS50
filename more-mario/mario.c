#include <stdio.h>
#include <cs50.h>

const int GAP = 2;

void space(int n, int i);
void pound(int i);
void gap(int GAP);

int main(void)
{

    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        space(n, i);
        pound(i);
        gap(GAP);
        pound(i);
        space(n,i);
        printf("\n");
    }

}

void space(int n, int i)
{
    for (int s = 0; s < n - i - 1; s++)
    {
        printf(" ");
    }
}

void gap(int gap_size)
{
    for (int h = 0; h < gap_size; h++)
    {
        printf(" ");
    }
}

void pound(int i)
{
    for (int p = 0; p < i + 1; p++)
    {
        printf("#");
    }
}


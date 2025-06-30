#include <stdio.h>
#include <cs50.h>

// void loop(int n);
void space(int n);

int main(void)
{

    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);

    // for (int i = 0; i < n; i++)
    // {
       space(n);
    // }
    // printf("-\n");

}

void space(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf(".");
    }
}

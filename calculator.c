#include <cs50.h>
#include <stdio.h>
int add(int a, int b);
int main(void)
{
    int x = get_int("x?\n");
    int y = get_int("y?\n");

    //printf("%i\n", x + y);
    //int z = x + y;
    printf("%i\n", add(x,y));
}

int add(int a, int b)
{
    //int c = a + b;
    return a + b;
}

#include <stdio.h>
#include <cs50.h>

int main(void)
{
     // Prompt the user for change owed, in cents

    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // Calculate how many quarters you should give customer
    //define variable q as cents/25 rounded to the lowest whole number.

        int q = cents / 25;
        cents -= q * 25;
        //printf("r:%i\n", cents);

        int d = cents / 10;
        cents -= d * 10;
       // printf("r:%i\n", cents);

        int n = cents / 5;
        cents -= n * 5;
        //printf("r:%i\n", cents);

        int p = cents / 1;
        cents -= p * 1;
        printf("Quarters: %i, Dimes: %i, Nickels: %i, Pennies: %i\n", q, d, n, p);
}


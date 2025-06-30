#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


int twos(string num);
int ones(string num);


int main(void)
{
     // Prompt the user for credit card number with string >> 15 numbers

    string creditSt;
    do
    {
        creditSt = get_string("Card number: ");
    }
    while (strlen(creditSt) < 13 && strlen(creditSt) > 16);
    //double every-other number starting at second-to-last, and add all single integer values together
    int doubles = twos(creditSt);
    //sum every-other integer from last position
    int singles = ones(creditSt);

    //sum twos and ones
    int sum = doubles + singles;

    //modulo 10 to check for validity & add commpany specific conditions for printing
    if (sum % 10 == 0 && (strlen(creditSt)==13 || strlen(creditSt)==16) && creditSt[0]=='4')
    {
        printf("VISA\n");
    }
    else if (sum % 10 == 0 && strlen(creditSt)==15 && creditSt[0]=='3' && (creditSt[1]=='4'|| creditSt[1]=='7'))
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && strlen(creditSt)==16 && creditSt[0]=='5' && creditSt[1] >= '1' && creditSt[1] <= '5')
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

 //function iterates through the string starting at the -2 position
int twos(string num)
{
    int addintwos = 0;

    for (int i = strlen(num)-2; i >=0; i-=2)
    {
        if (num[i]<48||num[i]>57)
        {
            break;
        }

    //create a variable for doubling integer characters
    //here we turn a string into an integer by subtracting the ACSII value of '0'
        int number = 2*(num[i] - '0');

        //add up all of the individual integers from the doubled values
        if (number > 9)
        {
            addintwos+= (number / 10) + (number % 10);
        }
        else
        {
            addintwos += number;
        }
    }
return addintwos;
}

//function will interate through the string from the -1 position and add those caracters to the sum
int ones(string num)
{   int addintones = 0;
    for (int x = strlen(num)-1; x >=0; x-=2)
    {
        if (num[x]<48||num[x]>57)
        {
            //printf("dude, it needs to be a 13 - 16 digit number, you cheater!!!!\n");
            break;
        }
        addintones += num[x]-'0';
    }
    return addintones;
}



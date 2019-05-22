#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
float input;
int numCoins = 0;
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

// Require user to input a non-negative integer
    do
    {
        input = get_float("Change owed: ");
    }
    while (input < 0);

// Round input to the nearest penny
int convertedInput = round(input * 100);

// Count quarters we can give them and update total
while (convertedInput % quarter != 0)
{
    numCoins++;
    convertedInput = convertedInput - quarter;
}

// Count dimes we can give them and update total
while (convertedInput / dime != 0)
{
    numCoins++;
    convertedInput = convertedInput - dime;
}

// Count nickels we can give them and update total
while (convertedInput / nickel != 0)
{
    numCoins++;
    convertedInput = convertedInput - nickel;
}

// Count pennies we can give them and update total
while (convertedInput / penny != 0)
{
    numCoins++;
    convertedInput = convertedInput - penny;
}

printf("%d\n", numCoins);
}

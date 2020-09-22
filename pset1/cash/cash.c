#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float money;
    do
    {
        // Prompt
        money = get_float("How much change is owed?\n");
    }
    while (money <= 0);
    // Float to Int
    int cents = round(money * 100);
    int mon;
    int coins = 0;
    // Resto = Total coins
    int resto = 0;
    
    // If money >= 0.25 
    if (cents >= 25)
    {
        mon = cents / 25;
        coins = floor(mon);
        cents = cents - 25 * coins;
        resto = coins;
    }
    // If money >= 0.10
    if (cents >= 10)
    {
        mon = cents / 10;
        coins = floor(mon);
        cents = cents - 10 * coins;
        resto = resto + coins;
    }
    // If money >= 0.05
    if (cents >= 5)
    {
        mon = cents / 5;
        coins = floor(mon);
        cents = cents - 5 * coins;
        resto = resto + coins;
    }
    // If money >= 0.01
    if (cents >= 1)
    {
        mon = cents / 1;
        coins = floor(mon);
        cents = cents - 1 * coins;
        resto = resto + coins;
    }
    // Print total 
    printf("%i Coins\n", resto);
}
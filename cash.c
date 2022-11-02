#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_coins(int cents, int value);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
//prompts the user for the change owed in a do-while until it is a valid response
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change Owed: ");
    }
    while (cents < 0);
    return cents;
}
//returns the number of coins are quarters
int calculate_quarters(int cents)
{
    return calculate_coins(cents, 25);
}
//returns the number of coins are dimes
int calculate_dimes(int cents)
{
    return calculate_coins(cents, 10);
}
//returns the number of coins are nickels
int calculate_nickels(int cents)
{
    return calculate_coins(cents, 5);
}
//returns the number of coins are pennies
int calculate_pennies(int cents)
{
    return calculate_coins(cents, 1);
}

//method that handles the algorithm for getting the number of a type of coin needed
int calculate_coins(int cents, int value)
{
    int num = 0;
    while (cents >= value)
    {
        cents -= value;
        num++;
    }
    return num;
}
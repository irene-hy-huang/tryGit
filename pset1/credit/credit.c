#include <stdio.h>
#include <cs50.h>


int main(void)
{
    // ask for credit card number (use get_long)
    long creditNumber = get_long("Number: ");
    printf("Number: %li\n", creditNumber);

    // check the number valid or not (Luhn’s Algorithm)
    int digitCount = 0;
    int sum = 0;
    long Number = creditNumber;

    for (; Number > 0;)
    {
        // get each digit
        int digit = Number % 10;

        // get second-to-last digit and so on,
        if (digitCount % 2 != 0)
        {
            // multiply every other digit by 2
            digit = digit * 2;

            // deal with situation that single digit multiplied by 2 >= 10
            if (digit >= 10)
            {
                digit = digit / 10 + digit % 10;
            }
        }

        // sum up each digit
        sum = sum + digit;

        printf("digit: %i\n", digit);


        // shortening the number after get each digit (get rid of the already counted digit)
        Number = Number / 10;
        // increse digitCount by 1 for selecting digit place
        digitCount = digitCount + 1;

    }

    printf("sum: %i\n", sum);
    printf("creditNumber: %li\n", creditNumber);

    // American Express numbers start with 34 or 37; 15-digit numbers;
    int Amex = creditNumber / 10000000000000;
    // MasterCard numbers start with 51, 52, 53, 54, or 55; 16-digit numbers,
    int Master = creditNumber / 100000000000000;
    // Visa numbers start with 4; 13- and 16-digit numbers.
    int Visa13 = creditNumber / 1000000000000;
    int Visa16 = creditNumber / 1000000000000000;

    printf("Amex: %i\n", Amex);
    printf("Master: %i\n", Master);
    printf("Visa13: %i\n", Visa13);
    printf("Visa16: %i\n", Visa16);

    // output the which kind of card
    if (sum % 10 == 0)
    {
        if (Amex == 34 || Amex == 37)
        {
            printf("AMEX\n");
        }

        else if (Master >= 51 && Master <= 55)
        {
            printf("MASTERCARD\n");
        }

        else if (Visa13 == 4)
        {
            printf("VISA\n");
        }

        else if (Visa16 == 4)
        {
            printf("VISA\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
        
    }

    else
    {
        printf("INVALID\n");
    }
    

}


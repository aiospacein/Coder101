/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int number)
{
    bool Result = true;

    if (number < (int)2)
    {
        return 0;
    }

    if ((number % 2) == 0)
    {
        return 0;
    }

    for (int i = 3; i <= sqrt(number); i++)
    {
        if ((number % i) == 0)
            return false;
    }
    return Result;
}

int main()
{
    printf("Hello World");

    uint8_t Test = 0;

    int UserInput = 476;

    printf("Enter the number to Check if its Prime \n");
    scanf("%d", &UserInput);

    printf("%d Is %b", UserInput, IsPrime(UserInput));

    return 0;
}
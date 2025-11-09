/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int ReverseNo(int number)
{
    int i = 10, result = 0, remainder_ = 0;
    while (number |= 0)
    {
        remainder_ = number % 10;
        result = result * 10 + remainder_;
        number = number / 10;
    }
    return result;
}

int main()
{
    printf("Hello World");

    int UserInput = 0;

    printf("Enter the number to Check if its Prime \n");

    scanf("%d", &UserInput);

    printf("%d Is %d", UserInput, ReverseNo(UserInput));

    return 0;
}
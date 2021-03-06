/*Mini Project 1 submitted by
SANJEEB KUMAR RAI
Scholar id-2012052
CSE(Section A)
*/

#include <stdio.h>
#define MAX 4500

char arr1[MAX], arr2[MAX], result[MAX];

void fib(void)
{
    int i, temp;
    for (i = 0; i < MAX; i++)
        result[i] = arr1[i] + arr2[i];

    for (i = MAX - 1; i > 0; i--)
    {
        // Performing basic addition operation on each digit
        if (result[i] > 9)
        {
            temp = result[i];
            result[i] %= 10;
            result[i - 1] += (temp / 10);
        }
    }
}

int main()
{
    int num;
    printf("Enter n to calculate nth fibonacci number: ");
    scanf("%d", &num);
    int i, j, tag = 0;
    for (i = 0; i < MAX; i++)
        arr1[i] = arr2[i] = result[i] = 0; // Initialising all elements with zero

    arr2[MAX - 1] = 1;

    for (i = 0; i <= num; i++)
    {
        fib(); // function call

        if (i == num - 2)
            break;

        for (j = 0; j < MAX; j++)
            arr1[j] = arr2[j]; // copy arr2 on arr1

        for (j = 0; j < MAX; j++)
            arr2[j] = result[j]; // copy result on arr2
    }

    for (i = 0; i < MAX; i++)
    {
        if (tag || result[i])
        {
            tag = 1;
            printf("%d", result[i]);
        }
    }

    return 1;
}

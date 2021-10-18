#include <stdio.h>
#include <string.h>

void convertToRoman(int num)
{
    int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0;
    while (num)
    {

        if (num / (decimal[i]) != 0)
        {
            int quotient = num / (decimal[i]);
            int remainder = num % (decimal[i]);
            if (quotient > 0)
            {
                for (int j = quotient; j > 0; j--)
                {
                    printf("%s", roman[i]);
                }
                if (remainder == 0)
                {
                    return;
                }
                else
                {
                    num = remainder;
                }
            }
        }
        i++;
    }
}

void convertTobinnary(unsigned long num)
{

    // Iterative solution (Not for very large value)
    // int result = 0;
    // int base = 1;
    // while (num != 0)
    // {
    //     int remainder = num % 2;
    //     result = result + remainder * base;
    //     base = base * 10;
    //     num = num / 2;
    // }

    if (num > 1)
    {
        convertTobinnary(num / 2); // Not a tail head recursive function
    }
    printf("%ld", num % 2);
}

int main()
{
    int n;

    printf("Enter Your choice :\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Exit\n");
    scanf("%d", &n);

    printf("Enter two numbers :\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    switch (n)
    {
    case 1:
    {
        int sum = num1 + num2;
        printf("Your result in Roman : ");
        convertToRoman(sum);
        printf("\nYour Result in Binary: ");
        convertTobinnary(sum);

        break;
    }

    case 2:
    {
        int result = num1 - num2;
        convertToRoman(result);
        printf("\nYour Result in Binary: ");
        convertTobinnary(result);
        break;
    }
    case 3:
    {
        int result = num1 * num2;
        convertToRoman(result);
        printf("\nYour Result in Binary: ");
        convertTobinnary(result);
        break;
    }

    case 4:
    {
        printf("Exiting Program\n");
        break;
    }
    }

    return 0;
}

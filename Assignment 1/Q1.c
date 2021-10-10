#include <stdio.h>
#include <string.h>

int main()
{
    char num[1000];
    int flag = 0, length;
    printf("Enter the value\n");
    scanf("%s", num);
    length = strlen(num);
    int i = 0;
    while (num[i++] != '\0')
    { // A number is floating point only if there is anumber after .
        if (num[i] == '.')
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("Valid Floating point No");
    }
    else
    {
        printf("Invalid Floating point No");
    }
}

// Convert to roman number

#include <stdio.h>

char RomanNum[256];
int i = 0;

void previousDigit(char n1, char n2)
{
    RomanNum[i] = n1;
    i = i + 1;

    RomanNum[i] = n2;
    i = i + 1;
}

void nextDigit(char c, int n)
{
    int j = 0;
    for (; j < n; j++, i++) {
        RomanNum[i] = c;
    }
}

int main()
{
    int num = 0;
    int j = 0;

    printf("Enter the decimal number: ");
    scanf("%d", &num);

    while (num != 0) {
        if (num >= 1000) {
            nextDigit('M', num / 1000);
            num = num - (num / 1000) * 1000;
        }
        else if (num >= 500) {
            if (num < (500 + 4 * 100)) {
                nextDigit('D', num / 500);
                num = num - (num / 500) * 500;
            }
            else {
                previousDigit('C', 'M');
                num = num - (1000 - 100);
            }
        }
        else if (num >= 100) {
            if (num < (100 + 3 * 100)) {
                nextDigit('C', num / 100);
                num = num - (num / 100) * 100;
            }
            else {
                previousDigit('L', 'D');
                num = num - (500 - 100);
            }
        }
        else if (num >= 50) {
            if (num < (50 + 4 * 10)) {
                nextDigit('L', num / 50);
                num = num - (num / 50) * 50;
            }
            else {
                previousDigit('X', 'C');
                num = num - (100 - 10);
            }
        }
        else if (num >= 10) {
            if (num < (10 + 3 * 10)) {
                nextDigit('X', num / 10);
                num = num - (num / 10) * 10;
            }
            else {
                previousDigit('X', 'L');
                num = num - (50 - 10);
            }
        }
        else if (num >= 5) {
            if (num < (5 + 4 * 1)) {
                nextDigit('V', num / 5);
                num = num - (num / 5) * 5;
            }
            else {
                previousDigit('I', 'X');
                num = num - (10 - 1);
            }
        }
        else if (num >= 1) {
            if (num < 4) {
                nextDigit('I', num / 1);
                num = num - (num / 1) * 1;
            }
            else {
                previousDigit('I', 'V');
                num = num - (5 - 1);
            }
        }
    }
    printf("Roman number is: ");
    for (j = 0; j < i; j++)
        printf("%c", RomanNum[j]);

    return 0;
}

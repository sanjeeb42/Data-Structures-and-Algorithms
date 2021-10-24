#include <stdio.h>
#define MAXIMUM 200

long long int Calculate_Hash(char input[MAXIMUM])
{
    long long int hash = 0;
    for (int i = 0; i < MAXIMUM && input[i] != '\0'; i++)
    {
        hash += (i + 1) * input[i];
    }
    return hash;
}

int main()
{
    char str[MAXIMUM] = {0};
    scanf("%[^\n]", str);
    printf("%lld\n", Calculate_Hash(str));
    return 0;
}

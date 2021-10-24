#include <stdio.h>
#include <limits.h>

#define MAX (INT_MAX / 4)

char isPrime[MAX + 1] = {0}; // Initialising all with 0

void Seive(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == 0)
        {
            for (int j = 2; j * i <= n; j++)
            {
                isPrime[i * j] = 1; // Marking Prime numbers here
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == 0)
        {
            printf("%d\t", i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Seive(n);

    return 0;
}

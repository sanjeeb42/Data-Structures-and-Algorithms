#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Logic for selection sort

void selectionsort(long long int a[], long long int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }

    //Printing sorted array
    printf("Selection Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return;
}

//Logic for buuble sort

void bubblesort(long long int a[], long long int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    //printing sorted array
    printf("Bubble Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return;
}
int main()
{
    printf("Enter the number of elements:\n");
    long long int n;
    scanf("%d", &n);
    long long int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    clock_t start, end;
    long int t;
    start = clock();
    selectionsort(a, n);
    end = clock();
    t = end - start;
    printf("Total time elapsed for selection sort: %f\n", (double)t / (double)CLOCKS_PER_SEC);
    clock_t start2, end2;
    long int t2;
    start2 = clock();
    bubblesort(a, n);
    end2 = clock();
    t2 = end2 - start2;
    printf("Total time elapsed for bubble sort: %f\n", (double)t2 / (double)CLOCKS_PER_SEC);
}

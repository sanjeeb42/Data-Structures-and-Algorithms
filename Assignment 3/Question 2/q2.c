#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX (int)1e4

void Average_Case_Time(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = rand() % MAX;
}

void Best_Case_Time(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = i;
}

void Worst_Case_Time(int n, int input[])
{
    for (int i = 0; i < n; i++)
        input[i] = n - i - 1;
}

void insertionSort(int n, int arr[])
{
   
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    srand(time(0));

    int n;
    printf("Enter the size : ");
    scanf("%d", &n);

    int arr[n];

    int input;
    printf("Select a type out of these\n");
    printf("1. Average Case\n");
    printf("2. Best Case\n");
    printf("3. Worst Case\n");
   
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        Average_Case_Time(n,arr);
        break;

    case 2:
        Best_Case_Time(n,arr);
        break;

    case 3:
        Worst_Case_Time(n,arr);
        break;

    default:
        printf("You have selected an Invalid option\n");
        return 0;
        break;
    }

    clock_t start = clock();

    insertionSort(n,arr);

    clock_t end = clock();
    printf("Total elapsed time for the selected Operation : %f\n", (double)(end - start) / (double)CLOCKS_PER_SEC);

    return 0;
}

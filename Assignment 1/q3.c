#include <stdio.h>

void convert_1D_to_2D(int arr[], int rows, int columns)
{
    int m = rows, n = columns;
    int arr2[m][n];
    int k = 0;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = arr[k];
            k++;
        }
    }
    printf("Printing 2D array :\n");
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            printf("%d \t", arr2[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[100], n;
    printf("Enter the size of 1D array :\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int rows, columns;
    printf("Enter the no of rows and columns\n");
    scanf("%d %d", &rows, &columns);
    printf("Printing Elements of 1D array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
    if (rows* columns != n)// Checking if no of elements of both array are same or not
    {
        printf("2D array cannot be formed\n");
    }
    convert_1D_to_2D(arr, rows, columns);

    return 0;
}


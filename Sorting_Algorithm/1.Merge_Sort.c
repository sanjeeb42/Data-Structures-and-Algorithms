#include <stdio.h>


int max(int a, int b)
{
    return a > b ? a : b;
}

void merge(int arr[], int start, int end)
{
    int mid=(start+end)/2;
    int temp[100];
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }

        else
        {
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    for(int i=start; i<=end; i++){
        arr[i]=temp[i];
    }
}

void mergesort(int arr[],int start,int end){
    if(start>=end){
        return ;
    }

    // Divide 
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+ 1, end);

    // Conquer -- Merge
    merge(arr,start,end);
}


int main()
{
    int n;
    n=6;
   
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for(int i=n-1; i>=0; i--){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    


    return 0;
}

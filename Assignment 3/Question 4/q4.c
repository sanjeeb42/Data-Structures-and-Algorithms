#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX (int)1e9+7

//Solution to part a
void InsertItemAtLast(int A[], int n, int key) {
  A = (int*) realloc(A, n+1);
  A[n] = key;
}

//Solution to part b 
void InsertItemAtFirst(int A[], int n, int key) {
  A = (int*) realloc(A, n+1);

  for(int i = n; i>0; i--)
    A[i] = A[i-1];
  A[0] = key;
}

//Solution to part c
void InsertItemAtIndex(int A[], int n, int i, int key) {
  A = (int*) realloc(A, n+1);

  for(int j = n; j>i; j--)
    A[j] = A[j-1];
  A[i] = key;
}

//Solution to part d
void DeleteItemFromLast(int A[], int n) {
  A = (int*) realloc(A, n-1);
}

//Solution to part e
void DeleteItemFromFirst(int A[], int n) {
  
  for(int i = 0; i<n-1; i++)
    A[i] = A[i+1];

  A = (int*) realloc(A, n-1);
}

//Solution to part f
void DeleteItemFromIndex(int A[], int n, int i) {
  for(int j = i; j<n-1; j++)
    A[j] = A[j+1];
  A = (int*) realloc(A, n-1);
}

//Solution to part g
int FindItemUnsorted(int A[], int n, int key) {
  for(int i = 0; i<n; i++) {
    if(A[i] == key)
      return i;
  }
  return -1;
}

//Solution to part h
int binarySearch(int A[], int n, int key, int low, int high) {
  int mid = (low + high) / 2;

  if(low > high)
    return -1;
  else if(A[mid] == key)
    return mid;
  else if (A[mid] > key)
    return binarySearch(A, n, key, 0, mid-1);
  else
    return binarySearch(A, n, key, mid+1, n-1);
}

int FindItemSorted(int A[], int n, int key) {
  return binarySearch(A, n, key, 0, n-1);
}

//Solution to part i
void SortArray(int A[], int n) {
  int key, j;
  for (int i = 1; i < n; i++) {
    key = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j = j - 1;
    }
    A[j + 1] = key;
  }
}

//Solution to part j
int *ExtractSubest(int A[], int n, int i, int j) {

  int size = j-i+1;
  int *subset = (int*) malloc(size * sizeof(int));

  for(int k = 0; k<size; k++)
    subset[k] = A[i+k];

  return subset;
}

//Solution to part k
int DeleteSubset(int A[], int n, int i, int j) {
  int size = (n -j) + (i-1);

  for(int k = j+1; k<n; k++)
    A[(k-j) + (i-1)] = A[k];
  A = (int*) realloc(A, size);
}

//Solution to part l
void SplitIntoTwoArray(int A[], int n, int *splitArray1, int *splitArray2) {  
  
  //Assuming split is from middle
  int mid = n/2;
  for(int i = 0; i<=mid; i++)
    splitArray1[i] = A[i];

  for(int i = mid+1; i<n; i++)
    splitArray2[i - (mid + 1)] = A[i];
}

//Solution to part m
void CloneArray(int A[], int n, int B[]) {
  for(int i = 0; i<n; i++)
    B[i] = A[i];
}

//Solution to part n
void ShiftLeftArray(int A[], int n, int r) {
  for(int i = 0; i<n-r; i++)
    A[i] = A[i+r];

  A = (int*) realloc(A, n-1);
}

//Solution to part o
void ShiftRightArray(int A[], int n, int r) {
  A = (int *) realloc(A, n-r);
}

//Solution to part p
void RotateArrayClockwise(int A[], int n, int r) {
  int temp[r];

  for(int i = 0; i<n; i++) {
    if (i<r)
      temp[i] = A[i]; //copying to temp
    else {
      A[i-r] = A[i]; //shifting
      
      if (i>=n-r)
        A[i] = temp[i - (n-r)]; //Placing rotated elements
    }
  }
}

//Solution to part q
void RotateArrayAntiClockwise(int A[], int n, int r) {
  int temp[r];

  for(int i = n-r; i<n; i++)
    temp[i - (n-r)] = A[i];

  for(int i = n-r-1; i>=0; i--)
    A[i+r] = A[i];

  for(int i = r-1; i>=0; i--)
    A[i] = temp[i];
}

//Solution to part r
int FindMin(int A[], int n) {
  int min = 0;
  for(int i = 0; i<n; i++) {
    if(A[min] > A[i])
      min = i;
  }
  return min;
}

//Solution to part s
int FindMax(int A[], int n) {
  int max = 0;
  for(int i = 0; i<n; i++) {
    if(A[max] < A[i])
      max = i;
  }
  return max;
}

//Solution to part t
void FillArrayPseudoRandom(int A[], int n) {
  
  srand(time(0));

  for(int i = 0; i<n; i++)
    A[i] = rand();
}

//Solution to part u
void FillArrayTrueRandom(int A[], int n) {
  
  int mods[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
  srand(time(0));

  for(int i = 0; i<n; i++)
    A[i] = rand() % mods[rand() % 10];
}

//Solution to part v
int *IncreaseArraySize(int A[], int n, int m) {
  return (int*)realloc(A, m);
}

//Solution to part w
void SetArrayToZero(int A[], int n) {
  for(int i = 0; i<n; i++)
    A[i] = 0;
}

//Solution to part x
void DeleteAllItemOfArray(int A[], int n) {
  for(int i = 0; i<n; i++)
    A[i] = 0;
}

//Solution to part y
void DeleteArray(int A[]) {
  free(A);
}

//Solution to part z
int* AllocateArray(int n, int *B) {
  int *A = (int*) malloc(n*sizeof(int));
  return A;
}

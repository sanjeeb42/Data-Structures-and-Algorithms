#include <bits/stdc++.h>
using namespace std;

int result = -1;

int LSearch(int *arr, int start, int end, int key)
{
    if (arr[start] == key)
    {

        return max(result, start+1); // return i+1
        
    }
    if (start > end)
    {

        return result   ;
    }

    return LSearch(arr, start + 1, end, key);
}

int main()
{
    int n, key;
    cout << "Enter the size and Key to Search" << endl;
    cin >> n >> key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = LSearch(arr, 0, n - 1, key);
    
    cout << ans << endl;

    return 0;
}

//Recursive Approach

//Q. Is there a subset in array which sum will be equal to sum variable (11)
#include <iostream>
#include <bits/stdc++.h>
#define _n 5
#define _sum 11
using namespace std;
//with memoization
//array will be of sum and n
//int subset_matrix[6][12];
int subset_matrix[_n+1][_sum+1];

int subset_memoization(int* arr, int sum, int n)
{

    if (subset_matrix[n][sum] != -1)
        return subset_matrix[n][sum];

    if (sum == 0)
    {
        // cout << 1 <<endl;
        return 1;
    }
    if (n == 0 && sum != 0)
    {
        // cout << 0 << endl ;
        return 0;
    }
    if (arr[n] > sum)
    {
        subset_matrix[n][sum] = subset_memoization(arr, sum, n - 1);
        return subset_matrix[n][sum] ;
    }
    subset_matrix[n][sum] = max(subset_memoization(arr, sum - arr[n], n - 1), subset_memoization(arr, sum, n - 1));
    return subset_matrix[n][sum] ;
}
int subset(int *arr, int sum, int n)
{
    if (sum == 0)
    {
        // cout << 1 <<endl;
        return 1;
    }
    if (n == 0 && sum != 0)
    {
        // cout << 0 << endl ;
        return 0;
    }

    if (arr[n] > sum)
        return subset(arr, sum, n - 1);

    return max(subset(arr, sum - arr[n], n - 1), subset(arr, sum, n - 1));
}
int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = 5;
    //cout << subset(arr, sum, n);
    memset(subset_matrix, -1, sizeof(subset_matrix));
    cout << subset_memoization(arr, sum, n);
}
#include<iostream>
#define _n 4 
#define _sum 6 

//Problem Statement 
//Count of subsets with sum equal to X
using namespace std ;

int t[_n+1][_sum+1] ;
int countSubsetSum(int* arr, int sum, int n ){
    for(int i=0 ; i<=_sum ;i++){
        t[0][i] = 0 ;
    }
    for(int i=0 ; i<=_n ;i++){
        t[i][0] = 1 ;
    }
    for(int i=1 ; i<=_n ;i++){
        for(int j=1; j<=_sum ;j++){
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];
            else{
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                 
            }
        }
    }
    return t[_n][_sum];
}
int main(){
    int arr[] = {1,2,3,3};
    int sum = 6 ; 
    int n = 4 ;
    int result  = countSubsetSum(arr,sum ,n);
    cout << result ;
}

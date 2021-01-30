#include<iostream>
#define _n 5
#define _sum 11
using namespace std ; 

//SubSet Sum 
//Top Down Approach 
bool t[_n+1][_sum+1] ;

bool subsetSum(int* arr,int sum , int n ){
    for(int i=0 ; i<=_sum ; i++){
        t[0][i] = false ;
    }
    for(int i=0 ; i<=_n ; i++){
        t[i][0] = true ;
    }

    for(int i=1; i<=_n ; i++){
        for(int j=1 ; j<=_sum ;j++){
         if(j < arr[i-1]){
             t[i][j] = t[i-1][j];
             continue;
         }else{
             t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j] ;
         }

        }
    }
    return t[_n][_sum] ;
    
}
int main(){

    int arr[] = {2, 3, 7, 8, 10};
    int sum =11;
    int n = 5;
    bool result = subsetSum(arr,sum,n);
    cout << result ;
    /* for(int i=0 ; i<=_n ; i++){

        for(int j=0 ; j<=_sum ; j++){
            cout <<t[i][j] << " " ;
        }
        cout << endl ;
    }*/
    



}
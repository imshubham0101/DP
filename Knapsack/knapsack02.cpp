#include<iostream>
#include <bits/stdc++.h>
//knapsack top down approach
using namespace std ;
int main(){

     int value[] ={60,50,70,30};
     int weight[] ={5,3,4,2};
     int capacity = 5 ;
     int n = 4 ;
    int t[n+1][capacity+1] ;
   
    for(int i = 0 ; i<n+1 ; i++){
        for (int j = 0; j < capacity+1; j++)
        {
            if(i == 0 || j == 0){
                t[i][j] = 0 ;
                continue;
            }
           if(weight[i] > j)
                t[i][j] = t[i-1][j] ;

            else{
                t[i][j] = max(value[i]+t[i-1][j-weight[i]],t[i-1][j]);


            }

        }
        
    }
    cout <<"Maximum Profit is "<<t[n][capacity]<<endl;
    int w  = capacity ;
    while(n!=0 || w != 0){
       // cout << n <<endl;
    if(t[n][w] - value[n] == t[n-1][w-weight[n]]){
        cout<< n << endl ;
        w = w-weight[n];
        n=n-1 ;
    }else if(t[n][w] != t[n-1][w]){
        cout << n <<endl ; 
    } 
    else {
        n = n-1 ;
    }
    }


    return 0 ; 
   
}


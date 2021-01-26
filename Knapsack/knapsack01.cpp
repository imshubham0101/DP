#include<iostream>
#include <bits/stdc++.h>

using namespace std ;
int t[51][4];   

//Using memoization 
int knapsack(int v[],int weight[],int w,int n){
        if(n == 0 || w == 0)
            return 0 ;
        if(t[w][n] != -1)
            return t[w][n];
        if(weight[n-1] <= w)
        {
            t[w][n] = max(v[n-1]+knapsack(v,weight,w-weight[n-1],n-1),knapsack(v,weight,w,n-1));
            return t[w][n] ;
        }
        else{
            t[w][n] =  knapsack(v,weight,w,n-1);
            return t[w][n];
        }
}

int main(){ 
    int value[] ={60,100,120};
    int weight[] = {10,20,30};
    memset(t,-1,sizeof(t));
    int w = 50 ;      //knapsack weight
    int max_profit = knapsack(value,weight,w,3);
    cout << max_profit <<endl;
}

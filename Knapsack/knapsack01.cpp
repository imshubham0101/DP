#include<iostream>

using namespace std ;

int knapsack(int v[],int weight[],int w,int n){

        if(n == 0 || w == 0)
            return 0 ;
        
        if(weight[n-1] <= w)
        {
            return max(v[n-1]+knapsack(v,weight,w-weight[n-1],n-1),knapsack(v,weight,w,n-1));
        }
        else{
            return knapsack(v,weight,w,n-1);
        }
}

int main(){ //hi 
    int value[] ={60,100,120};
    int weight[] = {10,20,30};
    int w = 50 ;      //knapsack weight
    int max_profit = knapsack(value,weight,w,3);
    cout << max_profit <<endl;



}

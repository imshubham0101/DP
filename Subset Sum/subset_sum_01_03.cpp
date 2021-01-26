//Recursive Approach 

//Q. Is there a subset in array which sum will be equal to sum variable (11)
#include<iostream>

using namespace std ;

int subset(int* arr , int sum, int n ){
    if(sum == 0 ) {
       // cout << 1 <<endl;
        return 1 ;
    }
    if(n == 0 && sum != 0){
       // cout << 0 << endl ;
        return 0;
    }
        
    if(arr[n] > sum)
        return subset(arr,sum,n-1);
    
    return max(subset(arr,sum-arr[n],n-1),subset(arr,sum,n-1));
    
    
}
int main(){
    int arr[] = {2,3,7,8,10} ;
    int sum = 11 ;
    int n = 5 ;
    cout << subset(arr,sum,n);



}
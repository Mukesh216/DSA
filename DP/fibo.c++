
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//recursion 
//  tc - O(2^n)  sc - O(n);


int fibo(int n){
    
    if(n==0)return 0;
    if(n==1)return 1;
    
    return fibo(n-1) + fibo(n-2);
}



//  DP
//  Memoization 

int fibo(int n , vector<int> &dp){
    
    if(n==0 || n==1)return n;
    
    if(dp[n] != -1)return dp[n];
    
    dp[n] = fibo(n-1 , dp) + fibo(n-2 , dp);
    
    return dp[n];
}

int fiboFind(int n){
    
    vector<int> dp(n+1 , -1);
    
    return fibo(n , dp);
}



//  DP
//  Tabulation

int fiboFind(int n){
    vector<int> dp(n+1  , -1);
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2 ; i<=n ; ++i){
        dp[i] = dp[i-1] + dp[i-2];
        
    }
    return dp[n];
}




//  Space optimised solution from dp

int fiboFind(int n){
    
    int pre2=0;
    int pre=1;
    
    for(int i=2 ; i<=n ; i++){
        int current = pre + pre2;
        pre2= pre;
        pre = current;
    }
    
    return pre;
}


int main()
{
    
    int n;
    cin>>n;
    
    cout<<fiboFind(n);
    
    return 0;
}
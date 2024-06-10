  
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// frog stair case problem
// initially at 0th stair and you need to reach nth stair (by one or two steps at a time)
//there is energy loss at each jump as given in array

//ex:if n=3 ( (1,1,1) ( 1,2 ) ( 2,1) ) + energy losses
// TO CALCULATE THE MIN ENERGY 


// It is a 1D dp problem


int frog(int n , int energy[]){
    
    if( n == 0 ) return 0;
    
    int left , right = INT_MAX;
    
    left = frog(n-1 , energy) + abs(energy[n] - energy[n-1]);
    
    if(n>1) right = frog(n-2 , energy) + abs(energy[n] - energy[n-2]);
    
    
    return min (left, right);  //this MIN indicates the counting of all possible ways prop of recursion and selecting MIN
    
    
}


// Memoization



int frog(int n , int energy[]  , vector<int> &dp){
    
    if( n == 0 ) return 0;
    
    
    if(dp[n] != -1) return dp[n];
    
    int left , right = INT_MAX;
    
    left = frog(n-1 , energy , dp) + abs(energy[n] - energy[n-1]);
    
    if(n>1) right = frog(n-2 , energy , dp) + abs(energy[n] - energy[n-2]);
    
    
    return dp[n] = min (left, right);  //this MIN indicates the counting of all possible ways prop of recursion and selecting MIN
    
    
}


int frogSteps(int n , int energy[]){
    
    vector<int> dp(n , -1);
    
    return frog(n-1 , energy , dp);
    
    
}



// TABLULATION

    

int frog(int n , int energy[]){
    
    
    vector<int> dp(n , -1);
    
    dp[0] = 0;
    
    for(int i=1 ; i<n ; i++){
        
        int firstStep , secondStep = INT_MAX;
        
        firstStep = dp[i-1] + abs(energy[i]  - energy[i-1]);
        
        if(i>1)secondStep = dp[i-2] + abs(energy[i] - energy[i-2]);
        
        dp[i] = mins(firstStep , secondStep);
    }
    
    return dp[n-1];
    
    
}



// SPACE OPTIMIZATION 





int main()
{
    
    int n;
    cin>>n;
    int energy[4] = {10,20,12,24};
    
    cout<<frog(n , energy);
    
    return 0;
}

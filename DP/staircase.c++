
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// stair case problem
// initially at 0th stair and you need to reach nth stair (by one or two steps at a time)


//ex:if n=3 ( (1,1,1) ( 1,2 ) ( 2,1) )

// It is a 1D dp problem


int noOfSteps(int n){
    
    if( n==0 || n==1 ) return 1;
    if(n<0)return 0;
    
    int left = noOfSteps(n-2);
    
    int right = noOfSteps(n-1);
    
    return left+right;  //this sum indicates the counting of all possible ways prop of recursion
    
}


// Memoization


int noOfSteps(int n){
    
    //similar to fibo question
}





int main()
{
    
    int n;
    cin>>n;
    
    cout<<noOfSteps(n);
    
    return 0;
}

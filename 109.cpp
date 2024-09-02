#include <bits/stdc++.h> 
#define mod 1000000007
int add(int a, int b){
    return (a%mod + b%mod)%mod;
}
int multi(int a,int b){
    return ( (a%mod)* 1LL*(b%mod) )%mod;
}
int solve1(vector<int>&dp,int n, int k){
    if(n == 1){
        return k;
    }
    if(n ==2){
        return add(k,multi(k,k-1) );
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = add( multi(solve1(dp,n-2, k), k-1) , multi(solve1(dp,n-1, k), k-1) );
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int>dp(n+1, -1);
    return solve1(dp,n, k);
}
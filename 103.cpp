#include<bits/stdc++.h>

int f(int i,int j,int** arr,vector<vector<int>> &dp){

    if(i==0 && j==0) return arr[0][0];

    if(i<0 || j<0) return 1e9;

    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j] = arr[i][j] + min(f(i-1,j,arr,dp),min(f(i,j-1,arr,dp),f(i-1,j-1,arr,dp)));

} 

int minCostPath(int** cost, int n, int m, int x, int y)

{

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    return f(x-1,y-1,cost,dp);

}
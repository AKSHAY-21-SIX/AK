#include <vector>
int solve1(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
   
    if(index >= n){
        return 0;
    }
    if(dp[index] != INT_MAX){
        return dp[index];
    }
    int oneDay = solve1(n,days,cost,index+1,dp) +cost[0];
    
    int i;
    for(i=index; i<n && days[i]<days[index]+7; i++);
    int oneWeeks = solve1(n, days, cost, i,dp) + cost[1];

    for(i=index; i<n && days[i]<days[index]+30; i++);
    int oneMonth = solve1(n, days, cost, i,dp) +cost[2];
    
    dp[index]= min(oneDay, min(oneWeeks, oneMonth) );
    return dp[index];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    
    vector<int>dp(n+1,INT_MAX);
    return solve1(n,days,cost,0,dp);
}
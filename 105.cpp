#include <bits/stdc++.h> 

int solve(int i, vector<int>&arr, vector<int>&dp)
{
    if(i < 0)
    {
        return 0;
    }
    if(i == 0)
    {
        return arr[0];
    }
    if(dp[i] != -1)
    {
        return dp[i];
    }
    return dp[i] = max((arr[i] + solve(i - 2, arr,dp)), (solve(i - 1,arr,dp)));
}

int solveTab(int i, vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n, 0);
    dp[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        int incl = arr[i];
        if(i > 1)
        {
            incl += dp[i - 2];
        }
        int excl = dp[i - 1];
        dp[i] = max(incl,excl);
    }
    return dp[n - 1];
}

int spaceOpti(int i, vector<int>&arr)
{
    int n = arr.size();
    vector<int>dp(n, 0);
    int p2 = 0;
    int p1 = arr[0];
    for(int i = 1; i < n; i++)
    {
        int incl = arr[i];
        if(i > 1)
        {
            incl += p2;
        }
        int excl = p1;
        int cur = max(incl,excl);
        p2 = p1;
        p1 = cur;
    }
    return p1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    return spaceOpti(nums.size() - 1, nums);
}
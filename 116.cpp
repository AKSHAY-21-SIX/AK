class Solution {

public:

int fun(int i,int j,vector<int>& arr, vector<vector<int>> &dp){

        if(i==j) return 0;

    int mini=1e9;

    if(dp[i][j]!=-1) return dp[i][j];

    for(int k=i;k<j;k++){

    int steps=arr[i-1]*arr[k]*arr[j]+fun(i,k,arr,dp)+fun(k+1,j,arr,dp);

        mini=min(mini,steps);

    }
    return dp[i][j]=mini;
}

    int minScoreTriangulation(vector<int>& arr) {
        
        int n=arr.size();


             vector<vector<int>> dp(n,vector<int>(n,-1));
   return fun(1,n-1,arr,dp);

    }
};
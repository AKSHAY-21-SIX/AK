class Solution {
public:
    
    int solve(vector<int>&v, int ind, int k, vector<vector<int>>&dp){
       
        int n=v.size();
       
        if(ind>=n){
       
            return 0;
       
        }
        if(dp[ind][k]!=-1){
       
            return dp[ind][k];
        }
        
        long long ans=0;
        
        long long take=0;
        
        long long ntake=0;
        
        take=solve(v, ind+1, k+1, dp)+v[ind]*k;
        
        ntake=solve(v, ind+1, k, dp);
        
        ans=max(take, ntake);
        
        return dp[ind][k]=ans;

    }
    int maxSatisfaction(vector<int>& satisfaction) {
         
         sort(satisfaction.begin(), satisfaction.end());
         
         int n=satisfaction.size();
         
         long long ans=0;
         
         vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
             
         ans=solve(satisfaction, 0, 1, dp);
    
         return ans;
    }

};
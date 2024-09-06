long long solve(int faces, int dices , int target,vector<vector<long long>> dp) {
        if(target < 0) {
            return 0;
        }
        if((dices != 0 && target == 0) || (dices==0 && target!=0) ) {
            return 0;
        }
        if(dices==0 && target ==0) {
            return 1;
        }
        if(dp[dices][target] != -1)  {
            return dp[dices][target];
        }
        
        long long ans = 0;
        for(int i=1;i<=faces;i++) {
            ans += solve(faces,dices-1,target-i,dp);
        }
        return dp[dices][target] = ans;
    }
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        return solve(M,N,X,dp);
    }
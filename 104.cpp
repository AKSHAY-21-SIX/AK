int solveRecMem(vector<int> &num, int targetSum, int index, vector<vector<int>>& dp)
{
    if(index >= num.size()){
        return 1e9;
    }

    if(targetSum < 0){
        return 1e9;
    }

    if(targetSum == 0){
        return 0;
    }
    if(dp[index][targetSum] != -1){
        return dp[index][targetSum];
    }
    int include = 1 + solveRecMem(num, targetSum - num[index], index, dp);
    int exclude = solveRecMem(num, targetSum, index+1, dp);
    return dp[index][targetSum] = min(include, exclude);
}

int minimumElements(vector<int> &num, int x)
{

    vector<vector<int>> dp(num.size()+1, vector<int>(x+1, -1));
    int ans = solveRecMem(num, x, 0, dp);

    if (ans == 1e9)  return -1;
    
    return ans; 
}

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0]=mat[i][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        int maxm=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxm=max(maxm,dp[i][j]);
            }
            
        }
        
        return maxm;
    }
};
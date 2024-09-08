class Solution {
private:
    int solveMem(string &text1,string &text2,int i,int j,vector<vector<int>>  &dp)
    {
        if(i==text1.length() || j==text2.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;

        if(text1[i]==text2[j]) 
        {
            ans=1+solveMem(text1,text2,i+1,j+1,dp);
        }else
        {
            ans=max(solveMem(text1,text2,i+1,j,dp),solveMem(text1,text2,i,j+1,dp));
        }

        return dp[i][j]=ans;
    }    


public:
    int longestCommonSubsequence(string text1, string text2) {

         int n=text1.length();
         int m=text2.length();

         vector<vector<int>>  dp(n,vector<int>(m,-1));
         return solveMem(text1,text2,0,0,dp);
    }
};
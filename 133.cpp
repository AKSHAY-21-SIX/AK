class Solution {
private:
    int solveTab(string text1,string text2)
    {
        int n=text1.length();


        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
               int ans=0;

               if(text1[i]==text2[j]) 
               {
                 ans=1+dp[i+1][j+1];
                }else
                {
                 ans=max(dp[i+1][j],dp[i][j+1]);
                }

                dp[i][j]=ans;            
            }
        }
        return dp[0][0];
    }

public:
    int longestPalindromeSubseq(string s) {

        string revstr=s;
        reverse(revstr.begin(),revstr.end());
        return solveTab(s,revstr);

    }
};
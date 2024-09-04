int solve(int index,int n,int a[],int prev,vector<vector<int> > &dp)
    {
     
       if(index==n) return 0;
     
       if(dp[index][prev+1] !=-1) return dp[index][prev+1] ;
     
       int len =0 ;
     
       len = solve(1 + index,n,a,prev,dp);
     
       if(a[index] > a[prev] || prev == -1)
     
       {
     
           len =max(len, 1 + solve(index +1 ,n,a,index,dp) );
     
       }

       return dp[index][prev+1]  = len;
    }

    int maxLength(string s)
    
    {

        int n = s.size();
    
        int a[n];
    
        for(int i = 0;i<n;i++)
    
        {
    
           a[i] = s[i] -'a';    
    
        }

        vector<vector<int> > dp(n,vector<int> (n+1,-1));
    
        return solve(0,n,a,-1,dp);
    
    }
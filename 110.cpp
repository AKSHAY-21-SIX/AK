int solveMem(vector<int>&weight , vector<int>&value ,int ind , int capacity, vector<vector<int>>&dp)

{

    if(ind==0)

    {

        if(weight[ind]<=capacity)

        return value[ind];

        else

        return 0;

    }

    if(dp[ind][capacity]!=-1)

    return dp[ind][capacity];

  
    
   int inclu=0;
    if(weight[ind]<=capacity)

    inclu=value[ind]+solveMem(weight,value,ind-1,capacity-weight[ind],dp);

	int exclu=0+solveMem(weight,value,ind-1,capacity,dp);


    return dp[ind][capacity]=max(inclu,exclu);

}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 

{

 

    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));

    return solveMem(weight,value,n-1,maxWeight,dp);

}
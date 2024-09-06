class Solution{
public:
    
    int solver(int x,int ind,int arr[],vector<vector<int>> &dp){
        
        if(x==0){
            return 1;
        }
        
        if(x<0){
            return 0;
        }
        
        if(dp[x][ind]!=-1){
            return dp[x][ind];
        }
        int take = 0;
        int nottake = 0;
        
        if(ind-1>=0){
          take = solver(x-arr[ind],ind-1,arr,dp);
        }
        if(ind-1>=0){
          nottake = solver(x,ind-1,arr,dp);
        }
        
        return dp[x][ind] = take || nottake;
        
    }
    

    
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
    
        if (sum % 2 != 0) {
            return 0; 
    
        vector<vector<int>> dp((sum / 2) + 1, vector<int>(N + 1, -1));
    
        return solver(sum / 2, N, arr, dp) ? 1 : 0;
    }

};
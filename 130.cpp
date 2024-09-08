class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
        int ans = 0;
    
        int mini = prices[0];
    
        for (int i : prices) {
    
    
            mini = min(mini, i);
    
            int profit = i - mini;
    
            ans = max(ans, profit);
    
        }
    
    
        return ans;
    
    }
};
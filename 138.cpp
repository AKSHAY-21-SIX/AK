class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int n  = prices.size();
        int cur_min = prices[0];
        int max_profit = INT_MIN;
        for(int i=1; i<n; i++){
            max_profit = max(max_profit, prices[i]-cur_min);
            cur_min = min(prices[i], cur_min); 
        }
        return max_profit<0 ? 0 : max_profit;
    }
};

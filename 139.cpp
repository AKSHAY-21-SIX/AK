class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c=0;
        
        int ans=0;
        
        int ans1=INT_MAX;
        
        for(int i=0;i+1<prices.size();i++){
        
            if(prices[i+1]<prices[i]){
        
                c++;
        
            }
        
            else{
        
               ans1=min(ans1,prices[i]);
        
                ans=max(ans,(prices[i+1]-ans1));
        
            }
        }
        if(c==prices.size()-1){
            return 0;
        }
        else{
           return ans;
        }
    }
};

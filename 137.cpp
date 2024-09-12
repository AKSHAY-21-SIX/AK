class Solution {
public:
    int maxpro(vector<int>& prices, int * arr){
   
        int min = prices[0];
   
        for(int i=1; i<prices.size(); i++){
   
            arr[i]=max(arr[i-1], prices[i]-min);
   
            if(prices[i]<min)min=prices[i];
   
        }
   
        return arr[prices.size()-1];
   
    }
   
    int maxProfit(vector<int>& prices) {
   
       int * arr = new int[prices.size()];
   
       arr[0]=0;
   
       return maxpro(prices,arr); 
    }
};
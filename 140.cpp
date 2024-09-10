class Solution {
  public:
    
    bool static comp(pair<int, int> m1, pair<int, int> m2){
        
        return m1.second < m2.second;
    }
    
  
    int maxMeetings(int n, int start[], int end[]) {
       
        pair<int, int> meetings[n]; 
        
        for(int i=0; i<n; i++){
            meetings[i] = {start[i], end[i]};
        }
        
       
        sort(meetings, meetings + n, comp);
        
       
        int totalMeets = 1;
       
        int lastMeet = 0;
        for(int i = 1; i<n; i++){
            if(meetings[i].first > meetings[lastMeet].second){
                totalMeets++;
                lastMeet = i;
            }
        }
        
        return totalMeets;
    }
};
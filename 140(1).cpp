  int maxMeetings(int n, int start[], int end[]) {
    
        vector<pair<int,int>>v; 
        
        
        for(int i = 0 ; i < n ; i++){
            v.push_back({start[i],end[i]}); 
        }
        
        
        int ans = 0;
        
        
        sort(v.begin(),v.end()); 
        
        int first = -1, second = -1; 
        
        
        for(int i = 0 ; i < n ; i++){
            if(v[i].first <= second){
                if(v[i].second <= second){
                    first = v[i].first; 
                    second = v[i].second; 
                }
            }
            else{
                ans++; 
                first = v[i].first; 
                second = v[i].second; 
            }
        }
        
        return ans; 
    }
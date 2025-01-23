class Solution {
public:
    map<int,vector<int>> mp ;
    int total_sum=0 ; 
    
    Solution(vector<vector<int>>& rects) {
   
        for(auto rect:rects){
                 
            int area=(rect[3]-rect[1]+1)*(rect[2]-rect[0]+1);
            total_sum+=area; 
            mp[total_sum]=rect ;
        }
    }
    
    vector<int> pick() {
        int r=rand()%total_sum ;
        auto temp = mp.upper_bound(r);
        vector z = temp->second;
        int x = z[0]+rand()%(z[2]-z[0]+1);
        int y = z[1]+rand()%(z[3]-z[1]+1);
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
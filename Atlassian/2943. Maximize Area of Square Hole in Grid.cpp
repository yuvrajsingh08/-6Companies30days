class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        n = n+2; // hbar
        m = m+2; // vbar
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        // exclude 1 and n or m
        int maxHrange = 0;
        if(hBars.size() > 2) maxHrange = 1;
        else if(hBars.size() == 2) {
            if(hBars[0] == 1 && hBars[1] == n) maxHrange = 0;
            else maxHrange = 1;
        } else {
            if(hBars[0] == 1 || hBars[0] == n) maxHrange = 0;
            else maxHrange = 1;
        }
        int tempRange = 0;
        for(int i=1; i<hBars.size(); i++) {
            if(hBars[i] == n) continue;
            if(hBars[i] == hBars[i-1]+1 && hBars[i-1] != 1) {
                tempRange +=1;
                maxHrange = max(maxHrange,tempRange+1);
            } else tempRange = 0;
            // cout<<"temp-> i "<<tempRange<<" curr"<<i<<" val "<<hBars[i]<<endl;
        }

        int maxVrange = 0;
        if(vBars.size() > 2) maxVrange = 1;
        else if(vBars.size() == 2) {
            if(vBars[0] == 1 && vBars[1] == n) maxVrange = 0;
            else maxVrange = 1;
        } else {
            if(hBars[0] == 1 || hBars[0] == n) maxVrange = 0;
            else maxVrange = 1;
        }
         tempRange = 0;
        for(int i=1; i<vBars.size(); i++) {
            if(vBars[i] == m) continue;
            if(vBars[i] == vBars[i-1]+1 && vBars[i-1] != 1) {
                tempRange +=1;
                maxVrange = max(maxVrange,tempRange+1);
            } else tempRange = 0;
        }
        int curr = min(maxHrange, maxVrange) + 1;
        // cout<<maxHrange<<" "<<maxVrange<<endl;
        return curr*curr;

    }
};
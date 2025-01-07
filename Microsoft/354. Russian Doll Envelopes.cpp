class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
            /// yeh isliye kyoki agar width same h toh waise bgi nhi aaeyga 
            // aur next element ke liya hright badi hogi toh sahi rahegs 
            // kyoki binary search height  pr lagaenge width toh sorted h
            // aur agar chhoti height pehle aaigi toh woh dono ko le lega


            // simple saa h agar same with means ek hi select ho aur hum bs width pe 
            // toh laga nhi rahe toh ek hi select krna hoga na inme se
            // aur agar badi height pahle aa jaegi toh chhot select hi nhi hogi 
            // toh ek hi select hoga
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if(size == 0)
          return 0;

        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1; i<size; i++){
            if(envelopes[i][1] > dp.back()) {
                dp.push_back(envelopes[i][1]);
            }
            else {
                int it = lower_bound(dp.begin(), dp.end(),envelopes[i][1]) - dp.begin();
              dp[it] = envelopes[i][1];
            }
        }
        return dp.size();
    
    }
};
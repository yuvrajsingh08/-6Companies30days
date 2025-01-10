class Solution {
public:
    map<vector<int>, int> dp;
    bool isValid(int i, vector<vector<int>>& special, vector<int>& need) {
        for(int j=0; j<need.size(); j++) {
            if(need[j] - special[i][j] < 0) return false;
        }
        return true;
    }
    int solve(vector<int>& prices, vector<vector<int>>& special, vector<int> need) {
        if(dp.find(need) != dp.end()) return dp[need];
        int price = 0;
        for(int i=0; i<need.size(); i++) {
            price += prices[i]*need[i];
        }
        if(price == 0) return 0;
        // first special offers
        for(int i=0; i<special.size(); i++) {
            if(isValid(i, special, need)) {
                vector<int> a(need.size(),0);
                for(int j=0; j<need.size(); j++) {
                    a[j] = need[j] - special[i][j];
                }
                price = min(price, special[i][need.size()] + solve(prices,special, a));
            }
           
        }
        dp[need] = price;
        return price;
        
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int value = 0;
        return solve(price, special, needs);
    }
};
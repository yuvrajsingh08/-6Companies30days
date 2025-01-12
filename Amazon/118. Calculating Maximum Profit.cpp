class Solution {
public:
    //  buy -> 0 means you can buy 
    int solve(int k, vector<int>& prices, int ind, int buy) {
        if(ind >= prices.size()) return 0;
        vector<vector<vector<int> >> dp(prices.size()+1, vector<vector<int>>(2,vector<int>(k+1,0)));

        
        for(int i = prices.size()-1; i>=0; i--) {
            for(int isbuy = 1; isbuy >= 0; isbuy--) {
                for(int kth = 1; kth <= k; kth++) {
                    // op1 means eat five star & do nothing 
                    // int op1 = dp[i+1][isbuy][kth];

                    int profit = 0;
                    if(isbuy == 0) {
                        profit = max(dp[i+1][1][kth] - prices[i], dp[i+1][0][kth]);
                    }
                    else{
                        // means you can sell
                        profit = max(dp[i+1][0][kth-1] + prices[i], dp[i+1][1][kth]);
                    }
                    dp[i][isbuy][kth] = profit;
                }
            }
        }
        return dp[0][0][k];


// dekho k ko tum tabh change karoge jab poora kaam ho jaye means sell bhi ho jaeyga woh shi h naaki jab khareeda tab
// bada do wo dikkhat dega

        // op1 means eat five star & do nothing 
        // int op1 = solve(k,prices, ind+1, buy);

        // int op2 = 0;
        // if(k > 0 && buy == 0) {
        //     op2 = solve(k, prices, ind+1, 1) - prices[ind];
        // }
        // if(buy) // means you can sell
        //    op2 = solve(k-1, prices, ind+1, 0) + prices[ind];
        // return max(op1,op2);
    }
    int solveSO(vector<int>& Arr, int n, int k) {
    // Create two arrays, 'ahead' and 'cur', to track the maximum profit at each step
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap],
                                       -Arr[ind] + ahead[1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap],
                                       Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        // Update the 'ahead' array with the current values
        ahead = cur;
    }

    return ahead[0][k];
}
    int maxProfit(int k, vector<int>& prices) {
        // return solve(k,prices,0,0);
        return solveSO(prices,prices.size(),k);
    }
};
class Solution {
public:
    int solve(int k, int curr, int isBack, int jump, int back, vector<vector<vector<long long>>>& dp) {
        // base case
        if(curr > k+1) return 0;
        if(dp[back][isBack][jump] != -1) return dp[back][isBack][jump];
        int ans = 0;
        if(curr == k) ans = 1;
        int newCurr = curr + pow(2,jump);
        if(newCurr <= k+1)
            ans += solve(k,newCurr,1, jump+1,back, dp);
        if(isBack) ans += solve(k,curr-1,0,jump, back+1, dp);
        dp[back][isBack][jump] = ans;
        return ans;
    }
    int waysToReachStair(int k) {
        vector<vector<vector<long long>>> dp(50, vector<vector<long long>>(2,vector<long long>(50,-1)));
        // jump and back parameter will not exceed 40 as max value of k is 10^9( 2^40 >>> 10^9)
        // here why we don't use k in dp as k in too large so we use no. of time it gets back as k can be determine from jummp & back
        return solve(k,1,1,0,0, dp);
    }
};
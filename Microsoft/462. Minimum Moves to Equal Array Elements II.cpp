class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // why median but not mean ??? 
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int val = nums[n/2];
        if(n%2 == 0) {
            val = (nums[n/2] + nums[n/2-1])/2;
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += abs(val - nums[i]);
        }
        return ans;
    }
};
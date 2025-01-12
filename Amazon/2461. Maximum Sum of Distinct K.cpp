class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n) {
            mp[nums[j]]++;
            sum += nums[j];
            while(j-i+1 > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            //window size equal to k
            if(j-i+1 == k && mp.size() == k) {
                ans = max(ans, sum);
            }
            j++;
            
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if( num%2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }
        unordered_map<int,int>sumSeen;
        int sumOfSubarray = 0;
        int count = 0;
        sumSeen[0] = 1;

        for(int num : nums){
            sumOfSubarray += num;

            if(sumSeen.find(sumOfSubarray - k) != sumSeen.end()){
                /// sumofSubarray-k == ex excluded wala h means currsumofSubarray - ex == k
                count += sumSeen[sumOfSubarray - k];
            }

            sumSeen[sumOfSubarray]++;
        }

        return count;
    }
};
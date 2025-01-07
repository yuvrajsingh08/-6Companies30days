class Solution {
public:
    bool isOk(vector<int>& nums, int i, int j) {
        int prev = -1;
        int ind = -1;
        if(i > 0) {
            prev = nums[0];
            ind = 1;
        }
        while(ind != -1 && ind < i) {
            if(prev >= nums[ind]) return false;
            prev = nums[ind];
            ind++;
        }
        ind = j+1;
        if(prev == -1 && j < nums.size()-1){ // means i at zero then
            prev = nums[j+1];
            ind = j+2;
        }

        while(ind < nums.size() && ind > j) {
            if(prev >= nums[ind]) return false;
            prev = nums[ind];
            ind++;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                if(isOk(nums,i,j)) {
                    cout<<"i  -> "<<i<<" j-> "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};
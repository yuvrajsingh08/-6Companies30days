class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth = 0;
    int ans = -1;
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        if(nums.size() >= k) {
            for(int i=0; i<k; i++) {
                pq.push(nums[i]);
            }
            for(int i=k; i<nums.size(); i++) {
                if(nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        } else {
                for(int i=0; i<nums.size(); i++) {
                    pq.push(nums[i]);
                }
        }
    }

    int add(int val) {
        // it is gaurentee that there will be at least k elements in the array when you search for the kth element.
        if(pq.size() < kth) pq.push(val);
        else if(val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    int getMiddle(vector<int>& nums, int l, int r) {
        int i = l;
        for (int j = l + 1; j <= r; j++) {
            if (nums[j] < nums[l]) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[l], nums[i]);
        return i;
    }
    int kthSmallestNumber(vector<int>& arr, int K) {
        
        // Create a max heap (priority queue)
        priority_queue<int> pq;

        // Iterate through the array elements
        for (int i = 0; i < arr.size(); i++) {
        // Push the current element onto the max heap
            pq.push(arr[i]);

        // If the size of the max heap exceeds K, remove the largest element
            if (pq.size() > K)
                pq.pop();
        }

        // Return the Kth smallest element (top of the max heap)
        return pq.top();
    }



    void wiggleSort(vector<int>& nums) {
     int n = nums.size();
        int m = (n + 1) / 2;
        vector<int> copy(nums);
        int median = kthSmallestNumber(nums, m);
        
        // Partition the array into three parts: less than, equal to, and greater than median
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (copy[j] < median) {
                swap(copy[i++], copy[j++]);
            } else if (copy[j] > median) {
                swap(copy[j], copy[k--]);
            } else {
                j++;
            }
        }

        // Reorder elements into the wiggle sort format
        for (int i = m - 1, j = 0; i >= 0; i--, j += 2) nums[j] = copy[i];
        for (int i = n - 1, j = 1; i >= m; i--, j += 2) nums[j] = copy[i];
    }
};
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k; i++) {
            pq.push({arr[i],i});
        }
        vector<int> ans;
        ans.push_back(pq.top().first);
        for(int i=k; i<arr.size(); i++) {
            pq.push({arr[i],i});
            while(!pq.empty() && pq.top().second < i-k+1) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
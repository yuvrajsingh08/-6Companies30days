class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k ==  1 || n == 1) return n;
        k = k-1;
        if(n == 2) {
            if(k%(n) == 0) return 2;
            else return 1;
        }

        int curr = k%(n); // this will leave the table
        unordered_map<int,int> mp;
        for(int i=1; i<n; i++) {
            mp[i] = (curr+1)%(n);
            curr++;
        }
        int winner = findTheWinner(n-1,k+1);
        return mp[winner]+1;
    }
};
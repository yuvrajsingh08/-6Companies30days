class Solution {
public:
    int solveUsingTabulationSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, 0));
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);

        for(int j_index=b.length()-1; j_index>=0; j_index--) {
            for(int i_index=a.length()-1; i_index>=0; i_index--) {
            
                int ans = 0;
                if(a[i_index] == b[j_index]) {
                    ans = 1 + next[i_index+1];
                }
                else {
                    ans = 0 + max(next[i_index],curr[i_index+1]);         
                }
                curr[i_index] = ans;
            }
            //shifting
            next= curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(a.begin(), a.end());
        int ans = solveUsingTabulationSO(a,s);
        return ans;
    }
    int solve(string &s, string a, string b, int ind) {
        // base case
        if(ind == s.size()) {
            // yahan se khel shuru
            return longestPalindromeSubseq(a)*longestPalindromeSubseq(b);
        }
        //  either a
        int op1 = solve(s,a+s[ind], b, ind+1);
        // or b
        int op2 = solve(s, a, b+s[ind], ind+1);
        return max(op1,op2);

    }
    int maxProduct(string s) {
        string a = "";
        string b = "";
        return solve(s, a, b, 0);
    }
};
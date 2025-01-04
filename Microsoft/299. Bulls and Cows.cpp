class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mp;
        for(auto c: secret) {
            mp[c]++;
        }

        int total = 0;
        for(auto c: guess) {
            if(mp[c] > 0) {
                total++;
                mp[c]--;
            }
        }
        int i=0;
        int bulls = 0;
        while(i<secret.size() && i<guess.size()) {
            if(secret[i] == guess[i]) bulls++;
            i++;
        }
        string s = to_string(bulls);
        string t = to_string(total - bulls);
        return s+"A"+t+"B";
    }
};
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.saize() <= 10) return {};
        unordered_map<string,int> mp;
        for(int i=0; i<= s.size()-10; i++) {
            mp[s.substr(i,10)]++;
        }
        vector<string> ans;
        for(auto c: mp) {
            if(c.second > 1) ans.push_back(c.first);
        }
        return ans;
    }
};
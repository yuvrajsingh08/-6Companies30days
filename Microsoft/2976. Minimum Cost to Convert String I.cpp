class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, list<pair<char,int>> > adj;
        for(int i=0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i],cost[i]});
        }
        int n = adj.size();
        vector<vector<int>> dis(26, vector<int>(26,1e9));
        for(int i=0; i<26; i++) {
            dis[i][i] = 0;
        }

        for(auto a:adj) {
            for(auto b: a.second) {
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                dis[u-'a'][v-'a'] = min(dis[u-'a'][v-'a'],wt); /// important h !!!!!
            }
        }

         for(int helper=0; helper<26; helper++) {
            for(int src=0; src<26; src++) {
                if(dis[src][helper] < 1e9) {
                    for(int dist=0; dist<26; dist++) {
                        if(dis[helper][dist] < 1e9)
                            dis[src][dist] = min(dis[src][dist], dis[src][helper] + dis[helper][dist]);
                    }
                }
            }
        }

        long long count = 0;
        for(int i=0; i<source.size(); i++) {
            if(dis[source[i]-'a'][target[i]-'a'] == 1e9) return -1;
            count += dis[source[i]-'a'][target[i]-'a'];
        }
        return count;
    }
};
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, list<pair<int,int>> > adj;
        for(auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<vector<int>> dis(n, vector<int>(n,1e9));
        // diagonal pr zero
        for(int i=0; i<n; i++) {
            dis[i][i] = 0;
        }
        // update the array
        for(auto a:adj) {
            for(auto b: a.second) {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dis[u][v] = wt;
            }
        }
        // main concept
        for(int helper=0; helper<n; helper++) {
            for(int src=0; src<n; src++) {
                for(int dist=0; dist<n; dist++) {
                    dis[src][dist] = min(dis[src][dist], dis[src][helper] + dis[helper][dist]);
                }
            }
        }
        pair<int,int> ans = {n-1,n-1};  // no. of city reaches , city
        for(int city = 0; city<n; city++) {
            int count = 0;
            for(int other=0; other<n; other++) {
                if(city != other && dis[city][other] <= distanceThreshold){
                    count++;
                }
            }
            
            if(count <= ans.first) {
                ans = {count,city};
            }
        }
        return ans.second;
    }
};
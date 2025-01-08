class Solution {
public:
    bool isSafe(int i, int j, vector<vector<int>> &grid, map<pair<int, int>, bool> &vis){
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !vis[{i, j}])
            return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        map<pair<int, int>, bool> vis;
        int time = -1;
       
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                
            }
        }
        q.push({-1,-1});
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            int tempX = frontNode.first;
            int tempY = frontNode.second;
            //cout<<"tempX: "<<tempX<<"tempY: "<<tempY<<endl;
            if(tempX == -1 && tempY == -1){
                time++;
                if(!q.empty()){
                    
                    q.push({-1,-1});
                }
            }
            else{
                 int dx[] = {-1, 0, 1, 0};
                 int dy[] = {0, 1, 0, -1};
                 for (int k = 0; k < 4; k++){
                     int newX = tempX + dx[k];
                     int newY = tempY + dy[k];
                 //cout<<"newX: "<<newX<<" newY: "<<newY<<endl;
                     if (isSafe(newX, newY, grid, vis)){
                         q.push({newX, newY});
                         grid[newX][newY]=2;
                         vis[{newX, newY}] = true;
                     }
                }
            }

        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
                
            }
        }
        return time;
    }
};
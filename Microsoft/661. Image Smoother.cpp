class Solution {
public:
    int solve(vector<vector<int>>& img, int x, int y) {
        int n = img.size();
        int m = img[0].size();
        int sum = 0;
        int count = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int newX = x + i;
                int newY = y + j;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    sum += img[newX][newY];
                    count++;
                }
            }
        }

        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = solve(img, i, j);
            }
        }

        return res;
    }
};
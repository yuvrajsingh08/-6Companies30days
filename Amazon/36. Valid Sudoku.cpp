class Solution {
public:
    bool isPos(vector<vector<char>>& board, int ind) {
        unordered_map<char,int> row;
        unordered_map<char,int> col;
        unordered_map<char,int> mp;
        for(int i=0; i<9; i++) {
            if(board[ind][i] != '.') {
                row[board[ind][i]]++;
                if(row[board[ind][i]] == 2) return false;
            }
            if(board[i][ind] != '.') {
                col[board[i][ind]]++;
                if(col[board[i][ind]] == 2) return false;
            }
            // cout<<"ith-> "<<ind<<" row-> "<<3 * (ind / 3) + i / 3<<" col-> "<<3 * (ind % 3) + i % 3<<endl;
            if(board[3 * (ind / 3) + i / 3][3 * (ind % 3) + i % 3] != '.') {
                mp[board[3 * (ind / 3) + i / 3][3 * (ind % 3) + i % 3]]++;
                if (mp[board[3 * (ind / 3) + i / 3][3 * (ind % 3) + i % 3]] == 2) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // first check full row & col
        for(int i=0; i<9; i++) {
            if(!isPos(board, i)) return false;
        }
        return true;
    }
};
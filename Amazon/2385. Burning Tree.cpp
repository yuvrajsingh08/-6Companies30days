/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent, int target) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tar = NULL;
        while(!q.empty()) {
            TreeNode* frontNode = q.front();
            if(frontNode->val == target) tar = frontNode;
            q.pop();
            if(frontNode->left) {
                nodeToParent[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            
            if(frontNode->right) {
                nodeToParent[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }
        return tar;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        nodeToParent[root] = NULL;
        TreeNode* st = mapping(root, nodeToParent, start);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(st);
        vis[st] = true;
        q.push(NULL);
        int ans = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            if(front == NULL) {
                if(!q.empty()) {
                    ans += 1;
                    q.push(NULL);
                }
            }
            else {
                vis[front] = true;
                if(nodeToParent[front] && !vis[nodeToParent[front]]) q.push(nodeToParent[front]);
                if(front->left && !vis[front->left]) q.push(front->left);
                if(front->right && !vis[front->right]) q.push(front->right);
            }
        }
        return ans;
    }
};
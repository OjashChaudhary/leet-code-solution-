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
    int total = 0;
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return total;
    }
    
    void dfs(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return;
        }
        
        currentSum = currentSum * 10 + node->val;
        
        if (node->left == nullptr && node->right == nullptr) {
            total += currentSum;
            return;
        }
        
        dfs(node->left, currentSum);
        dfs(node->right, currentSum);
    }
};
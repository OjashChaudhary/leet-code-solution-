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
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(NULL);
            return result;
        }

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> left = build(start, root - 1);
            vector<TreeNode*> right = build(root + 1, end);

            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }

        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};
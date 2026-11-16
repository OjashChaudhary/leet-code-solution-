/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> values;
    TreeNode* buildtree(int i, int j){
        if(j < i) return NULL;
        int mid= (i+j)/2;
        return new TreeNode(values[mid], buildtree(i, mid-1), buildtree(mid+1, j));
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr= head;
        while(curr){
            values.push_back(curr->val);
            curr= curr->next;
        }

        return buildtree(0, values.size()-1);
    }
};
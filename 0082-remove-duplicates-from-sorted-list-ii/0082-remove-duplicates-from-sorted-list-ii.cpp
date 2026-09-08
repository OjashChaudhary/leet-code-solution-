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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (current->next != nullptr && current->val == current->next->val) {
                int duplicateVal = current->val;
                while (current != nullptr && current->val == duplicateVal) {
                    current = current->next;
                }
                prev->next = current;
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        return dummy->next;
    }
};
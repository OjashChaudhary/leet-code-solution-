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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;
        
        ListNode* temp = secondHalf;
        bool result = true;
        
        while (temp != nullptr) {
            if (firstHalf->val != temp->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        
        slow->next = reverse(secondHalf);
        
        return result;
    }
    
private:
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* current = node;
        
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        
        return prev;
    }
};
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
        ListNode* fast = head;
        ListNode* slow = head;

        while( fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prev = NULL;
        while( slow ){
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        ListNode* start = head;
        ListNode* end = prev;

        while( end ){
            if( start->val != end->val ) return false;
            start = start->next;
            end = end->next;
        }

        return true;
    }
};
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

    int n = 0;
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while( curr ){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

            n++;
        }

        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {

        ListNode* newHead = reverseList(head);
        ListNode* temp = newHead;
        ListNode* curr = newHead->next;
        
        while( curr ){
            
            int currVal = curr->val;
            int topVal = newHead->val;

            if( currVal >= topVal ){
                newHead->next = curr;
                newHead = curr;
            }

            curr = curr->next;
        }
        newHead->next = NULL;
        return reverseList(temp);
    }
};
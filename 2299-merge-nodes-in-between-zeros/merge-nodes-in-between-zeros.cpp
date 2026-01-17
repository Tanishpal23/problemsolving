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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* newHead = head;
        ListNode* newCurr = head;
        ListNode* curr = head->next;

        while( curr ){
            
            int sum = 0;

            if( curr->val != 0 ){
                while(curr && curr->val!=0){
                    sum+=curr->val;
                    curr = curr->next;
                }
                curr->val = sum;
                newCurr->next = curr;
                newCurr = curr;
            }
            if(curr) curr = curr->next;
        }

        return newHead->next;
    }
};
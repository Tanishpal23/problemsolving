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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n = lists.size();

        ListNode* dummy = new ListNode(-1);
        ListNode* tmp = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cmp> minPq;

        for( int i=0; i<n; i++ ){
            if( lists[i] ) minPq.push( lists[i] );
        }

        while( !minPq.empty() ){
            ListNode* curr = minPq.top();
            minPq.pop();

            tmp->next = curr;
            if( curr->next ) minPq.push( curr->next );
            tmp = tmp->next;
        }

        return dummy->next;
    }
};
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

    ListNode* reverselist(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;

        while( curr ){
            temp = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            n++;
        }

        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* newHead = reverselist(head);
        ListNode* curr = newHead;

        vector<int> ans(n, 0);
        stack<int> st;

        st.push(curr->val);
        curr = curr->next;

        for(int i=1; i<n; i++){

            int currVal = curr->val;
            int topVal = st.empty()? 0:  st.top();

            while( !st.empty() && currVal >= st.top() ) st.pop();

            if( !st.empty() ) ans[n-i-1] = st.top();

            st.push( currVal );
            curr = curr->next;
        }

        return ans;
    }
};
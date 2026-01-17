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

// Approach
// first critical pt, last critical pt with respect to curr critical pt


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* curr_next = curr->next;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        int critical_pt1 = -1;
        int critical_pt2 = -1;
        int currInd = 1;

        vector<int> ans;

        while( curr_next ){

            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = curr_next->val;

            if((currVal>prevVal && currVal>nextVal) || (currVal<prevVal && currVal<nextVal)){
                if( critical_pt1 != -1 ){
                    mini = min( mini, currInd-critical_pt2 );
                    maxi = max( maxi, currInd-critical_pt1 );
                }else{
                     critical_pt1 = currInd;
                }

                critical_pt2 = currInd;
            }

            currInd++;

            prev = prev->next;
            curr = curr->next;
            curr_next = curr_next->next;

        }

        ans.push_back(mini);
        ans.push_back(maxi);

        if( mini == INT_MAX ) return {-1, -1};
        return ans;

        // return mini==INT_MAX? {-1, -1}: {mini, maxi};

    }
};
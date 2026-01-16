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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start1 = list1;
        ListNode* end1 = list1;
        ListNode* start2 = list2;
        ListNode* end2 = list2;

        int idx = 0;
        while (idx < a - 1) {  
            start1 = start1->next;
            idx++;
        }

        end1 = start1;
        while (idx <= b) {
            end1 = end1->next;
            idx++;
        }


        while (end2->next != NULL) {
            end2 = end2->next;
        }

        start1->next = start2;
        end2->next = end1;

        return list1;
    }
};
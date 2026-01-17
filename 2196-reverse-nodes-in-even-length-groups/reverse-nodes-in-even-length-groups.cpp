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
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        int groupLen = 1;

        while (curr) {
            ListNode* temp = curr;
            int cnt = 0;
            while (temp && cnt < groupLen) {
                temp = temp->next;
                cnt++;
            }

            if (cnt % 2 == 0) {
                ListNode* prevNode = temp;
                ListNode* node = curr;

                for (int i = 0; i < cnt; i++) {
                    ListNode* nextNode = node->next;
                    node->next = prevNode;
                    prevNode = node;
                    node = nextNode;
                }

                ListNode* newTail = curr;
                prev->next = prevNode;
                prev = newTail;
                curr = temp;
            }
            else {
                for (int i = 0; i < cnt; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            groupLen++;
        }

        return dummy.next;
    }
};

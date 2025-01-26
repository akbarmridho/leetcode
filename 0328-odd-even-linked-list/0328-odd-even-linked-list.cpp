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
    ListNode* oddEvenList(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* starteven = head->next;

        ListNode* even = head->next;

        while(true) {
            ListNode* nextodd = even->next;
            ListNode* nexteven = even->next->next;

            odd->next = nextodd;
            even->next = nexteven;

            if (nextodd == nullptr) {
                odd->next = starteven;
                break;
            } else if (nexteven == nullptr || nexteven->next == nullptr) {
                nextodd->next = starteven;
                break;
            }

            odd = nextodd;
            even = nexteven;
        }

        return head;
    }
};
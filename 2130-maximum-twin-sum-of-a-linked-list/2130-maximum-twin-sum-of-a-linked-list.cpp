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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // begin reversing linked list
        ListNode* prev = nullptr;
        ListNode* current = slow->next;

        slow->next = nullptr;

        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        ListNode* rhead = head;
        ListNode* rtail = prev;

        int sum = rhead->val + rtail->val;

        while (rhead != nullptr && rtail != nullptr) {
            int csum = rhead->val + rtail->val;

            if (csum > sum) {
                sum = csum;
            }

            rhead = rhead->next;
            rtail = rtail->next;
        }

        return sum;
    }
};
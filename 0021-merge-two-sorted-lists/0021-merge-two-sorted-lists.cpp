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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* result = nullptr;
        ListNode* currentPos = nullptr;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    if (result == nullptr) {
                        ListNode* im = new ListNode(l1->val);
                        result = im;
                        currentPos = result;
                    } else {
                        ListNode* im = new ListNode(l1->val);
                        (*currentPos).next = im;
                        currentPos = im;
                    }
                    l1 = l1->next;
                } else {
                    if (result == nullptr) {
                        ListNode* im = new ListNode(l2->val);
                        result = im;
                        currentPos = result;
                    } else {
                        ListNode* im = new ListNode(l2->val);
                        (*currentPos).next = im;
                        currentPos = im;
                    }
                    l2 = l2->next;
                }
            } else if (l1 != nullptr) {
                if (result == nullptr) {
                    ListNode* im = new ListNode(l1->val);
                    result = im;
                    currentPos = result;
                } else {
                    ListNode* im = new ListNode(l1->val);
                    (*currentPos).next = im;
                    currentPos = im;
                }
                l1 = l1->next;
            } else if (l2 != nullptr) {
                if (result == nullptr) {
                    ListNode* im = new ListNode(l2->val);
                    result = im;
                    currentPos = result;
                } else {
                    ListNode* im = new ListNode(l2->val);
                    (*currentPos).next = im;
                    currentPos = im;
                }
                l2 = l2->next;
            }
        }

        return result;
    }
};
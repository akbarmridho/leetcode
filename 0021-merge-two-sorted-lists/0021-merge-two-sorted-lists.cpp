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
                    ListNode* next = nullptr;
                    if (result == nullptr) {
                        next = l1->next;
                        l1->next = nullptr;
                        result = l1;
                        currentPos = result;
                    } else {
                        next = l1->next;
                        l1->next = nullptr;
                        (*currentPos).next = l1;
                        currentPos = l1;
                    }
                    l1 = next;
                } else {
                    ListNode* next = nullptr;
                    if (result == nullptr) {
                        next = l2->next;
                        l2->next = nullptr;
                        result = l2;
                        currentPos = result;
                    } else {
                        next = l2->next;
                        l2->next = nullptr;
                        (*currentPos).next = l2;
                        currentPos = l2;
                    }
                    l2 = next;
                }
            } else if (l1 != nullptr) {
                ListNode* next = nullptr;
                    if (result == nullptr) {
                        next = l1->next;
                        l1->next = nullptr;
                        result = l1;
                        currentPos = result;
                    } else {
                        next = l1->next;
                        l1->next = nullptr;
                        (*currentPos).next = l1;
                        currentPos = l1;
                    }
                    l1 = next;
            } else if (l2 != nullptr) {
                ListNode* next = nullptr;
                    if (result == nullptr) {
                        next = l2->next;
                        l2->next = nullptr;
                        result = l2;
                        currentPos = result;
                    } else {
                        next = l2->next;
                        l2->next = nullptr;
                        (*currentPos).next = l2;
                        currentPos = l2;
                    }
                    l2 = next;
            }
        }

        return result;
    }
};

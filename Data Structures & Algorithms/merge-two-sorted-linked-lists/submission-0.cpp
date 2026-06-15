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
        // 1. Create a dummy node on the heap (make sur to delete it later)
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        // 2. Traverse ONLY while both lists have elements to compare
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            // Move our tail pointer forward so we can attach the next node
            curr = curr->next; 
        }

        // 3. One list is empty. Staple the remaining list to the end.
        // We don't need a loop for this! Just connect the pointers.
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }

        // 4. Return the actual start of the list (skipping the fake dummy node)
        ListNode* head = dummy->next;
        delete dummy;
        return head;

    }
};

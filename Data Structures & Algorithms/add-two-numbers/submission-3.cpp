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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Our trusty Stack Dummy Node to anchor the new list!
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        // 2. Loop as long as l1 has nodes, OR l2 has nodes, OR we have a leftover carry.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            int sum = carry; // Start with whatever carried over
            
            // If l1 is still alive, add its value and move it forward
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // If l2 is still alive, add its value and move it forward
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // 3. The Math Magic
            carry = sum / 10; // If sum is 14, carry becomes 1. If sum is 8, carry becomes 0.
            
            // Create a brand new node with just the ones-digit (14 % 10 = 4)
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        // 4. Return the new list, skipping the dummy anchor
        return dummy.next;
    }
};

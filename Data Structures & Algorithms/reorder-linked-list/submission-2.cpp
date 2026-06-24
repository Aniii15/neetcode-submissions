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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // --- STEP 1: Find the Middle ---
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // --- STEP 2: Reverse the Second Half ---
        ListNode* second = slow->next;
        slow->next = nullptr; // Sever the tie between the two halves
        ListNode* prev = nullptr;
        
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // --- STEP 3: Merge the Two Halves ---
        ListNode* first = head;
        second = prev; // 'prev' is now the head of the reversed second half
        
        while (second) {
            // Save the next nodes before we break the arrows
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            // Weave them together: first -> second -> temp1
            first->next = second;
            second->next = temp1;
            
            // Shift our pointers forward for the next iteration
            first = temp1;
            second = temp2;
        }
    }
};

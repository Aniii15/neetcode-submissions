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

        ListNode* curr = head;
        ListNode* historic_next = head->next;

        if(historic_next == nullptr || historic_next->next == nullptr) return;

        ListNode* last_prev = head;
        while(last_prev->next->next != nullptr){
            last_prev = last_prev->next;
        }

        ListNode* last = last_prev->next;

        while(curr != last && last != historic_next){
            curr->next = last;
            last->next = historic_next;
            last_prev->next = nullptr;

            curr = historic_next;
            historic_next = historic_next->next;
            last = last_prev;

            last_prev = head;
            while(last_prev->next->next != nullptr){
            last_prev = last_prev->next;
            }

        }
    }
};

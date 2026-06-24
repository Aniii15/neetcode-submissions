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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* curr = head;
        while(curr){
            total++;
            curr = curr->next;
        }

        int num = total-n;

        if(num == 0){
            head = head->next;
            return head;
        }

        ListNode* curr2 = head;
        for(int i = 0; i< num -1; i++){
            curr2 = curr2->next;
        }
        curr2->next = curr2->next->next;

        return head;
    }
};

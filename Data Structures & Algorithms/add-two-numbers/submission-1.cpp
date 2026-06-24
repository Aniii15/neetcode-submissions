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
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int size1 = 0;
        int size2 = 0;
        while (curr1) {
            size1++;
            curr1 = curr1->next;
        }
        while (curr2) {
            size2++;
            curr2 = curr2->next;
        }

        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        if (size1 >= size2) {
            int carry = 0;
            while (cur1) {
                if (cur2) {
                    if (cur1->val + cur2->val + carry < 10) {
                        cur1->val = cur1->val + cur2->val + carry;
                        carry = 0;
                    } else {
                        cur1->val = cur1->val + cur2->val - 10 + carry;
                        carry = 1;
                    }
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                } else {
                    if (cur1->val + carry < 10) {
                        cur1->val = cur1->val + carry;
                        carry = 0;
                    } else {
                        cur1->val = cur1->val + carry - 10;
                    }
                    cur1 = cur1->next;
                }
            }
            if (carry == 1) {
                ListNode* finalGuy = new ListNode(1);
                ListNode* temp = l1;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = finalGuy;
            }
            return l1;
        } else {
            int carry = 0;
            while (cur2) {
                if (cur1) {
                    if (cur1->val + cur2->val+carry < 10) {
                        cur2->val = cur1->val + cur2->val + carry;
                        carry = 0;
                    } else {
                        cur2->val = cur1->val + cur2->val - 10 + carry;
                        carry = 1;
                    }
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                else{
                    if(cur2->val + carry < 10){
                        cur2->val = cur2->val + carry;
                        carry = 0;
                    }
                    else{
                        cur2->val = cur2->val + carry - 10;
                    }
                    cur2 = cur2->next;
                }
            }
            if (carry == 1) {
                ListNode* finalGuy = new ListNode(1);
                ListNode* temp = l2;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = finalGuy;
            }
            return l2;
        }
    }
};

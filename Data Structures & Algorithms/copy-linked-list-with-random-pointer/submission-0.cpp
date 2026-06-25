/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> table;

        Node* cur = head;
        if (cur == nullptr) {
            return cur;
        }

        while (cur) {
            Node* temp = new Node(cur->val);
            table[cur] = temp;
            cur = cur->next;
        }


        Node* cur2 = head;
        Node* newHead = table[cur2];
        while(cur2){
            table[cur2]->next = table[cur2->next];
            table[cur2]->random = table[cur2->random];
            cur2 = cur2->next;
        }

        return newHead;
    }
};

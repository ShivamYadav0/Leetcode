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
         unordered_map<Node*, Node*> m;

        Node* temp = head;
        while(temp) {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        m[nullptr] = NULL;
        temp = head;
        while(temp) {
            Node* temp2 = m[temp];
            temp2->next = m[temp->next];
            temp2->random = m[temp->random];
            temp = temp->next;
        }

        return m[head];
    }
};
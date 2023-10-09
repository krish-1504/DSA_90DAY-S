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
        Node* temp = head;
        map<Node*,Node*> mp;

        while(temp!=NULL){
            Node* node = new Node(temp->val);
            mp[temp] = node;
            temp =  temp->next;
        }

        Node* t = head;
        while(t!=NULL){
            Node* node = mp[t];
            node -> next = mp[t->next];
            node -> random = mp[t->random];
            t = t->next;
        }
        return mp[head];
    }
};
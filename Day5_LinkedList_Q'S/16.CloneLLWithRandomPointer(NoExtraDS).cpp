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
        // step - 1;
        Node* temp = head;
        Node* prev = NULL;
        while(temp!=NULL){
            Node* node = new Node(temp->val);
            node -> next = temp->next;
            prev = temp;
            temp = temp->next;
            prev -> next = node;
        }

        // s-2 : random placeing
        Node* itr = head;
        while(itr != NULL){
            if(itr  -> random != NULL){
                itr -> next -> random = itr -> random -> next;
            }
            itr = itr -> next -> next;
        }

        //s-3 : make clone sepreted
        Node* dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node* fast;
        while(itr != NULL) {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    
    Node* onet = new Node(-1);
    Node* oneh = onet;
    
    Node* twot = new Node(-1);
    Node* twoh = twot;
    
    Node* zerot = new Node(-1);
    Node* zeroh = zerot;

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == 0){
            zerot->next = temp;
            zerot = zerot -> next;
        }
        else if(temp->data == 1){
            onet->next = temp;
            onet = onet -> next;
        }
        else if(temp->data == 2){
            twot->next = temp;
            twot = twot -> next;
        }
        temp = temp -> next;
    }

    zerot -> next = oneh->next;
    onet -> next = twoh->next;
    twot -> next = NULL;
    return zeroh->next;
}
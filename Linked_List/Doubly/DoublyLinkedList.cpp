#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this ->data = d;
        this ->next = NULL;
        this ->prev = NULL;
    }
};

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp ->next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail ->next = temp;
    temp ->prev = tail;
    tail = temp;
}

void insertAtPos(Node* &head,Node* &tail,int d ,int loc){
    if(loc == 0){
        insertAtHead(head,d);
    }
    else{
        Node* node = new Node(d);
        Node* temp = head;

        for(int i=0;i<loc-1;i++){
            temp = temp->next;
        }

        if(temp->next == NULL){
            insertAtTail(tail,d);
        }
        else{
            temp->next->prev = node;
            node -> next = temp->next;

            temp ->next = node;
            node -> prev = temp;
            }
    }
}

void deletion(Node* &head , int loc){
    Node* temp = head;
    if(loc == 0){
        head = head->next;
        head ->prev = NULL;
        free(temp);
    }else{
        for(int i=0;i<loc-1;i++){
            temp = temp->next;
        }
        if(temp->next->next != NULL){
            Node* node_tofree = temp->next;
            temp->next->next->prev = temp;
            temp ->next = temp->next->next;
            free(node_tofree);
        }
        else{
            Node* node_tofree = temp->next;
            temp->next->prev = NULL;
            temp->next = NULL;
            free(node_tofree);
        }
        
        
    }
}

void printIt(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head,20);
    printIt(head);
    cout<<endl;
    insertAtTail(tail,20);
    printIt(head);
    cout<<endl;
    insertAtHead(head,30);
    printIt(head);
    cout<<endl;
    insertAtTail(tail,30);
    printIt(head);
    cout<<endl;
    insertAtPos(head,tail,0,3);
    printIt(head);
    cout<<endl;
    insertAtPos(head,tail,10,6);
    printIt(head);
    cout<<endl;
    deletion(head,4);
    printIt(head);
    cout<<endl;
    deletion(head,4);
    printIt(head);
    cout<<endl;
    deletion(head,4);
    printIt(head);
    cout<<endl;
    deletion(head,0);
    printIt(head);
}
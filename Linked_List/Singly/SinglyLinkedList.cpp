#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &Head , int d){
    Node* temp = new Node(d);
    temp -> next = Head ; 
    Head = temp;

}

void insertAtTail(Node* &Tail , int d){
    Node* last = new Node(d);
    last -> next = NULL;
    Tail -> next = last;
    Tail = last;

}
void insertAtMiddel(Node* &Head , int d , int loc){
    Node* temp = Head;
    Node* insrt = new Node(d);
    for(int i=0;i<loc-1;i++){
        temp = temp->next;
    }
    insrt -> next = temp -> next;
    temp ->next = insrt;
}

void Deletion(Node* &Head , int loc){
    Node* temp = Head;
    if(loc == 0){
        Head = Head->next;
        temp -> next = NULL;
        free(temp);
    }
    else{
        for(int i=0;i<loc-1;i++){
            temp = temp->next;
        }
        Node* to_free = temp->next;
        temp ->next = temp->next->next;
        free(to_free);
    }
}

void printIt(Node* Head){
    Node* temp = Head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
};

int main(){
    Node* node1 = new Node(10);
    Node* Head = node1;
    Node* Tail = node1;

    insertAtHead(Head,20);
    insertAtTail(Tail,20);
    insertAtTail(Tail,30);
    insertAtMiddel(Head,30,2);
    insertAtMiddel(Head,40,1);
    Deletion(Head,1);
    Deletion(Head,2);
    printIt(Head);
    cout<<endl;
    Deletion(Head,0);
    printIt(Head);
    cout<<endl;
    return 0;
}

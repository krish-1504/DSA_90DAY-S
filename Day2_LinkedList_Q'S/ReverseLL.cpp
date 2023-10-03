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

void printIt(Node* Head){
    Node* temp = Head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};
//Used 3 Node Approch curr,prev,forw
void reverse(Node* &Head){
    Node* curr = Head;
    Node* prev = NULL;
    Node* forw = NULL;

    while(curr != NULL){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    Head = prev;
    cout<<"Successfull reverse"<<endl;
    cout<<endl;
    printIt(Head);
}
//recurcive solution
void rec(Node* Head,Node* curr,Node* prev){
    if(curr == NULL){
        Head = prev;
        cout<<"Successfully Reversed"<<endl;
        printIt(Head);
    }
    Node* forw = curr -> next;
    curr -> next = prev;
    rec(Head,forw,curr);
}
void reverse_rec(Node* &Head){
    Node* curr = Head;
    Node* prev = NULL;

    rec(Head,curr,prev);
}
//recursion using head
// Node* rec_head(Node* Head){
//     if(Head == NULL || Head->next == NULL){
//         return Head;
//     }
//     Head->next->next = Head;
//     Head-> next = NULL;
//     return rec_head(Head->next);

// }
int main(){
    Node* node1 = new Node(0);
    Node* Head = node1;
    Node* Tail = node1;

    insertAtHead(Head,10);
    insertAtHead(Head,20);
    insertAtHead(Head,30);
    printIt(Head);
    // rec_head(Head);
    printIt(Head);
    return 0;
}

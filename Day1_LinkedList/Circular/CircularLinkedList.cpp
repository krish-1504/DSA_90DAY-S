#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;


    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertNode(Node* &tail,int element,int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else{
        Node* temp = tail;
        while(temp->data != element){
            temp = temp->next;
        }
        Node* newNode = new Node(d);
        newNode ->next = temp ->next;
        temp ->next = newNode;
    }
}

void print(Node* tail) {

    Node* temp = tail;
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}
bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;

}

void deletion(Node* &tail , int val){
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        Node* temp = tail;
        Node* curr = temp ->next;

        while(curr->data != val){
            temp = curr;
            curr = curr->next;
        }
        temp ->next = curr ->next;

        //1 Node Linked List
        if(curr == temp) {
            tail = NULL;
        }
        //>=2 Node linked list
        else if(tail == curr ) {
            tail = temp;
        }
        
        free(curr);
    }
    
}

int main(){
    Node* tail = NULL;
    insertNode(tail,5,5);
    insertNode(tail,5,6);
    insertNode(tail,5,7);
    insertNode(tail,6,8);
    print(tail);
    deletion(tail,7);
    print(tail);
}
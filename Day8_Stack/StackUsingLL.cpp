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

class Stack{
    public:
    Node* top;
    int size;
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp -> next = top;
        top = temp;
        size++;
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top = top -> next;
            size--;
        }
        
    }

    int Stacksize(){
        return size;
    }

    bool isEmpty(){
        return top == NULL;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }
        else{
            return top -> data;
        }
    }

    void printit(){
        Node* temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp-> next;
        }
    }

};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    if(s.isEmpty()){
        cout<<"Stack Is Empty"<<endl;
    }
    else{
        cout<<"Stack IS Not A Empty"<<endl;
    }
    return 0;

}
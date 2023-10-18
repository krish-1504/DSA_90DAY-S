#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};
class queue{
    public:
    node* qfront;
    node* rear;
    int size;

    queue(){
        qfront = rear = NULL;
        size = 0;
    }

    void enqueue(int data){
        node* temp = new node(data);
        if(rear == NULL){
            qfront = rear = temp;
            size = 1;
        }
        else{
            rear -> next = temp;
            rear = rear -> next;
            size++;
        } 
    }

    void dequeue(){
        if(qfront == NULL){
            size = 0;
            return ;
        }
        node* temp = qfront;
        qfront = qfront-> next;
        size--;
        if(qfront == NULL){
            rear = NULL;
        }
        delete(temp);
    }
    int qsize(){
        return size;
    }
    int front(){
        if(qfront == NULL){
            cout<<"empty";
            return -1;
        }
        return qfront->data;
    }

};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(10);
    cout<<q.front();
    q.dequeue();
    cout<<q.front();
    cout<<q.qsize();

}



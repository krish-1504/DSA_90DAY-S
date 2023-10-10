#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int s){
        this -> size = s;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack Overflow" <<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout << "Stack Is Underflow" << endl;
        }
    }
    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack Is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

    if(s.isEmpty()){
        cout<<"Stack is Empty"<<endl;

    }
    else{
        cout<<" Stack Is Not A Empty"<<endl;
    }
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(11);
    cout<<"Front :"<<q.front()<<endl;
    q.push(12);
    cout<<"Front :"<<q.front()<<endl;
    q.push(13);
    cout<<"Front :"<<q.front()<<endl;


    cout<<"size :"<<q.size()<<endl;


    q.pop();
    cout<<"Front :"<<q.front()<<endl;
    q.pop();
    cout<<"Front :"<<q.front()<<endl;
    q.pop();
    cout<<"Front :"<<q.front()<<endl;// 0

    if(q.empty()){

        cout<<"queue is empty"<<endl;
    }

}
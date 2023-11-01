#include<iostream>
#include<deque>

using namespace std;


int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.push_front(20);
    dq.pop_back();
    dq.pop_front();
    cout<<dq.size()<<endl;
    if(dq.empty()){
        cout<<"deque is empty";
    }
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}

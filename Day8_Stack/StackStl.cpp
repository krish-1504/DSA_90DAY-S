#include<iostream>
# include<stack>

using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    cout<<s.top()<<endl;
    s.push(2);
    s.pop();
    cout<<s.top()<<endl;
    if(s.empty()){
        cout<<"Stack Is Empty"<<endl;
    }
    else{
        cout<<"Stack Is Not Empty"<<endl;
    }
    cout<<s.size()<<endl;

}
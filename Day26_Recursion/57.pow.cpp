#include <iostream>
using namespace std;

int powe(int a ,int b){
    if(b==0) {
        cout<<1<<" ";
        return 1;
    }

    int res = powe(a,b/2);
    if(b%2){
        cout<<res*res*a<<" ";
        return res*res*a;
    }
    else{
        cout<< res*res<<" ";
        return res*res;
    }
}

int main()
{
    cout<<powe(2,13);
}
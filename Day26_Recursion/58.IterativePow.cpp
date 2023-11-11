#include<bits/stdc++.h>
using namespace std;
long long sol(int a, int c){
    long long res = 1;
    while(c){
        if(c & 1) res = res * a;
        a = a * a;
        c /= 2;
    }
    return res;
}

string solve(int a, int b, int c){
    if(sol(a, c) > sol(b, c)) return ">";
    else if(sol(a, c) < sol(b, c)) return "<";
    return "=";
}
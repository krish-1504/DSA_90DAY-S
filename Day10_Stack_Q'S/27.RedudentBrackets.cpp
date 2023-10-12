#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> t;
    char prevtop;
    for(int i=0;i<s.length();i++){
        if(t.empty()){
            t.push(s[i]);
        }
        else if(s[i]==')'){
            if(t.top()=='+'||t.top()=='-'||t.top()=='*'||t.top()=='/'){
                while(t.top()!='('){
                t.pop();
                }
                t.pop();
            }
            else{
                return true;
            }
            
        }
        else if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            t.push(s[i]);
        }
        
    }
    return false;
}

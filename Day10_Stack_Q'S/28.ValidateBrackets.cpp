#include <bits/stdc++.h> 
int findMinimumCost(string t) {
  // Write your code here
  stack<char> s;
  int cnt =0;
  for(int i=0;i<t.length();i++){
    if(s.empty()){
      s.push(t[i]);
    }
    else if(s.top()=='{' && t[i]=='}'){
      s.pop();
    }
    else{
      s.push(t[i]);
    }
  }
  if(s.size()!=0){
      if(s.top()=='{'){
      s.pop();
      if(s.top()=='}'){
        s.push('{');
        return (s.size()/2)+1;
      }
      else{
        s.push('{');
      }
    }
  }
  
  if(s.size()==0){
    return 0;
  }
  else if(s.size()/2 > 0){
    return s.size()/2;
  }
  else{
    return -1;
  }
}
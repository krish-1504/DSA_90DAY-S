#include <bits/stdc++.h> 
void solve(stack<int>&st, int cnt , int N){
   if((N/2)==cnt) {
      st.pop();
      return ;
   }
   int num = st.top();
   st.pop();
   solve(st,cnt+1,N);
   st.push(num);
}
void deleteMiddle(stack<int>&st, int N){
	int cnt = 0;
   solve(st,cnt,N);
   // Write your code here
   
}
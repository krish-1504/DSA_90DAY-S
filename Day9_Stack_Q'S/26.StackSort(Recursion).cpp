#include <bits/stdc++.h> 
void sortit(stack<int> &st ,int num){
	if(st.empty() || num > st.top()){
		st.push(num);
		return;
	}
	int x = st.top();
	st.pop();
	sortit(st,num);
	st.push(x);
}
void solve(stack<int> &st){
	if(st.empty()){
		return ;
	}
	int y = st.top();
	st.pop();
	solve(st);
	sortit(st,y);

}
void sortStack(stack<int> &st)
{
	solve(st);
}

c
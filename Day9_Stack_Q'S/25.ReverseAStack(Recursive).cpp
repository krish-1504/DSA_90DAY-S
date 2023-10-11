void botm(stack<int> &st,int n){
    if(st.empty()){
        st.push(n);
        return;
    }
    int num = st.top();
    st.pop();
    botm(st,n);
    st.push(num);
}
void solve(stack<int> &st){
    if(st.empty()){
        return ;
    }
    int num = st.top();
    st.pop();
    solve(st);
    botm(st,num);
    
    
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    solve(stack);
}


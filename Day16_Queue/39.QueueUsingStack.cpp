class MyQueue {
    stack<int> st,st1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int s = st.size();
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }

        st.push(x);

        while(!st1.empty()){
            st.push(st1.top());
            st1.pop();
        }

    }
    
    int pop() {
        int ans = st.top();
        st.pop();
        return ans;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
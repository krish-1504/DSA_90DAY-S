class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();

        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
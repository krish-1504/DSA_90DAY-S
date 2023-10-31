class DinnerPlates {
    stack<int> s;
    map<int,stack<int>> mp;
    int cap;
    int curr = 0;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        bool f = false;
        for(int i = 0;i<=curr;i++){
            if(mp[i].size() < cap){
                mp[i].push(val);
                cout<<mp[i].top()<<endl;
                f = true;
                break;
            }
        }
        if(mp[curr].size() == cap && f == false){
            curr++;
            mp[curr].push(val);
        }
        
    }
    
    int pop() {
        while(mp[curr].empty() && curr != 0){
            curr--;
        }
        if(mp[curr].empty() && curr == 0){
            return -1;
        }
        int ans = mp[curr].top();
        mp[curr].pop();
        return ans;
    }
    
    int popAtStack(int index) {
        if(mp[index].empty()){
            return -1;
        }
        int ans = mp[index].top();
        mp[index].pop();
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
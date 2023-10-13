class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int re = 1;

        while(!st.empty() && st.top().first <= price){
            re = re + st.top().second;
            st.pop();
        }
        st.emplace(price,re);
        return re;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
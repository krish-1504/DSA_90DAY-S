class Solution {
public:
    vector<int> nextsmall(vector<int>& h){
        stack<int> s;
        s.push(-1);
        vector<int> ans(h.size());
        for(int i = h.size()-1;i>=0;i--){
            while(s.top()!=-1 && h[i]<=h[s.top()]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevsmall(vector<int>& h){
        stack<int> s;
        s.push(-1);
        vector<int> ans(h.size());
        for(int i=0;i<h.size();i++){
            while(s.top()!=-1 && h[i]<=h[s.top()]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {
        vector<int> next = nextsmall(h);
        vector<int> prev = prevsmall(h);


        int maxi = INT_MIN;
        for(int i=0;i<h.size();i++){
            if(next[i]==-1){
                next[i] = h.size();
            }
            int width = (next[i]-prev[i])-1;

            maxi = max(maxi,width*h[i]);
        }

        return maxi;
    }
};
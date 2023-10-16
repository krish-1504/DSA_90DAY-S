class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;

        for(int i=0;i<a.size();i++){
            
            if(!s.empty() && (s.top()>0 && a[i]<0)){
                if(abs(a[i]) == abs(s.top())){
                    s.pop();
                }
                else if(abs(s.top())<abs(a[i])){
                    s.pop();
                    i--;
                }
            }
            else{
                s.push(a[i]);
            }
        }

        vector<int> ans(s.size());
        for(int i= s.size()-1 ; i>=0;i--){
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};
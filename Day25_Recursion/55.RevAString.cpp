class Solution {
public:
    void reverseString(vector<char>& s) {
        solve(s,0,s.size()-1);
    }
    void solve(vector<char> &s,int st,int end){
        if(st >= end){
            return;
        }
        int temp = s[st];
        s[st] = s[end];
        s[end] = temp;
        solve(s,st+1,end-1);
    }
};
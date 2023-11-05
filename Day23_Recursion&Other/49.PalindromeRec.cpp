class Solution {
public:
    bool isPalindrome(string s) {
        return solve(s,0,s.length()-1);
    }
    bool solve(string str,int s,int e){
        if(s >= e){
            return true;
        }

        if(str[s] != str[e]){
            return false;
        }

        return solve(str,s+1,e-1);
    }
};
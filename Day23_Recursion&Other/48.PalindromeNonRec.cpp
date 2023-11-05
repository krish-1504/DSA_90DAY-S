class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> v;
        if(x<0){
            return false;
        }
        while(x>0){
            cout<<x%10<<endl;
            v.push_back(x%10);
            x = x/10;
        }
        for(int i=0;i<v.size()/2;i++){
            if(v[i] != v[v.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
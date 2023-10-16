class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans;
        
        stack<int> k;
        k.push(-1);
        
        vector<int> mp;
        int p = 0;
        for(int i=0;i<words.size();i++){
            if(words[i] == "prev"){
                p++;
                if( mp.size() == 0 || p-1 > mp.size()-1){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(mp[p-1]);
                }
                
            }
            else{
                mp.insert(mp.begin(),std::stoi(words[i]));
                p = 0;
            }
        }
        return ans;
        
    }
};
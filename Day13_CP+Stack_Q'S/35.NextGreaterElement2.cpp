class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(nums.size());

        for(int i=(2*nums.size())-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i%(nums.size())]){
                s.pop();
            }
            if(i<nums.size()){
                if(s.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = s.top();
                }
            }
            s.push(nums[i%nums.size()]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2);
    }
    vector<int> solve(vector<int>& nums1, vector<int>& nums2){
        stack<int> s;
        s.push(-1);

        vector<int> ans(nums1.size());
        map<int,int> mp;

        for(int i=nums2.size()-1;i>=0;i--){
            while(s.top()!=-1 && s.top()<nums2[i]){
                s.pop();
            }

            mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;

    }
};
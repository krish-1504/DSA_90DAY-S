#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);

    vector<int> ans(arr.size());

    for(int i = arr.size()-1 ; i>=0;i--){
        while(arr[i]<=s.top()){
            s.pop();
        }

        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;
}
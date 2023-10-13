class Solution {
public:
    vector<int> prevsmall(vector<int>& row){
        stack<int> s;
        s.push(-1);
        vector<int> ans(row.size());
        for(int i=0;i<row.size();i++){
            while(s.top()!=-1 && row[s.top()]>=row[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> nextsmall(vector<int>& row){
        stack<int> s;
        s.push(-1);
        vector<int> ans(row.size());
        for(int i=row.size()-1;i>=0;i--){
            while(s.top()!=-1 && row[s.top()]>=row[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> colcombi(vector<vector<char>>& m , int n){
        vector<int> ans(m[0].size());
        for(int i =0;i<m[0].size();i++){
            int sum = 0;
            for(int j=0;j<=n;j++){
                if((int(m[j][i])-48)==0){
                    sum = 0;
                }
                else{
                    sum+=(int(m[j][i])-48);
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
    int histogram(vector<int>& row){
        vector<int> prev = prevsmall(row);
        vector<int> next = nextsmall(row);


        int maxi = INT_MIN;

        for(int i=0;i<row.size();i++){
            if(next[i]==-1){
                next[i] = row.size();
            }

            int width = (next[i]-prev[i])-1;
            maxi = max(maxi,(width*row[i]));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        for(int i=0;i<matrix.size();i++){
            vector<int> row = colcombi(matrix , i);
            cout<<"for i = "<<i<<" row = "<<" ";
            for(int j=0;j<row.size();j++){
                cout<<row[j]<<" ";
            }
            int hist = histogram(row);
            maxi = max(maxi,hist);
            cout<<"for i = "<<i<<"hist = "<<hist<<" maxi = "<<maxi<<endl;
        }
        return maxi;
    }
};
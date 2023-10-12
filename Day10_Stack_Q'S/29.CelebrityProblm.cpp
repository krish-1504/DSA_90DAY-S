class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool know(vector<vector<int>> &m,int a, int b , int n){
        if(m[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        // s-1 all value in stack
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //s-2 check with stack
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            
            if(know(m,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        
        // s-3 conform  it
        int ans = s.top();
        int zero =0;
        for(int i=0;i<n;i++){
            if(m[ans][i] == 0){
                zero++;
            }
        }
        if(zero != n){
            return -1;
        }
        
        int one = 0;
        for(int i=0;i<n;i++){
            if(m[i][ans] == 1){
                one++;
            }
        }
        if(one != (n-1)){
            return -1;
        }
        
        return ans;
    }
    
    
};
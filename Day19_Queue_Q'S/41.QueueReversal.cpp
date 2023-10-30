class Solution
{
    public:
    queue<int> rev(queue<int> &q)
    {
        
        reve(q);
        return q;
        // add code here.
    }
    void reve(queue<int> &q){
        if(q.empty()){
            return;
        }
        int num = q.front();
        q.pop();
        reve(q);
        q.push(num);
    }
};
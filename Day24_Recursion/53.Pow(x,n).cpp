class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1){
            return x;
        }
        if(n==-1){
            return 1/x;
        }
        if(n>1) return x*myPow(x,n-1);
        return 1/x*myPow(x,n+1);
    }
};
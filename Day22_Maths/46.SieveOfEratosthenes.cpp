class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        if(n<=1){
            return 0;
        }
        else{
            vector<bool> arr(n,true);
            for(int i=2;i<sqrt(n);i++){
                if(arr[i] == true){
                    for(int j = i*i ; j<n ; j+=i){
                        arr[j] = false;
                    }
                }
            }
            for(int i = 2 ;i<n;i++){
                if(arr[i] == true){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};
class Solution {
    int fb(int min,int max,int size){
        cout<<"fb"<<endl;
        int front;
        int back;
        if(min > max){
            cout<<"min>max"<<endl;
            min++;
            front = min;
            back = size - max;
            cout<<front<<" "<<back<<endl;
            return front>back?back:front;
        }
        cout<<"min<max"<<endl;
        front = max+1;
        back = size - min;
        cout<<front<<" "<<back<<endl;
        return front>back?back:front;
    }
    int oneside(int min,int max,int size){
        cout<<"oneside"<<endl;
        if(min>max){
            cout<<"min>max"<<endl;
            min = size-min;
            max = max+1;
        }else{
            cout<<"min<max"<<endl;
            max = size-max;
            min = min+1;
        }
        cout<<max<<" "<<min<<endl;
        return max+min;
    }
public:
    int minimumDeletions(vector<int>& nums) {
        int min = INT_MAX;
        int min_ind;
        int max = INT_MIN;
        int max_ind;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
                max_ind = i;
            }
            if(nums[i]<min){
                min = nums[i];
                min_ind = i;
            }
        }


        int sfrontback = fb(min_ind,max_ind,nums.size());
        int one = oneside(min_ind,max_ind,nums.size());

        

        return sfrontback>=one?one:sfrontback;


    }
};
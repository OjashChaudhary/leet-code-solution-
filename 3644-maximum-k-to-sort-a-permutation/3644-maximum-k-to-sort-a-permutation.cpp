class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int value= ~0;
        bool flag= false;
        int n= nums.size();
        for(int i =0; i<n; i++){
            if(i!= nums[i]){
                flag= true;
                value= value& i;
            }
        }
        if(flag== false) return 0;
        return value;
    }
};
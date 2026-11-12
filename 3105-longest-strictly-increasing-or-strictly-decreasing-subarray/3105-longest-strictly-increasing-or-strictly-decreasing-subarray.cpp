class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int a=1, b=1;
        int ans=1;
        int n= nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                a++;
                b=1;
                ans= max(ans,a);
            }else if(nums[i] == nums[i+1]){
               
                a=1;
                b=1;
            }else {
                 b++;
                a=1;
                ans= max(ans, b );
            }
            
        }
        return ans;
    }
};
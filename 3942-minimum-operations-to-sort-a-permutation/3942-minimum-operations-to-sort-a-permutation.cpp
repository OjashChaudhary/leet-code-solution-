class Solution {
public:
    int check(vector<int>& nums){
        int n= nums.size();
        int ans=-1;
        for(int i=0; i<2*n; i++){
            if(i== ans+n && ans!= -1) return ans;
            
            if(nums[i%n] == 0){
                ans= i;
            }
            else if(ans != -1 && nums[i%n] != nums[(i-1)%n]+1){
                
                return -1;
            }
        }
        return ans;
    }

    int checkrev(vector<int>& nums){
        int n= nums.size();
        int ans=-1;
        for(int i=0; i<2*n; i++){
            if(i == ans+n && ans!= -1) return ans;

            if(nums[i%n] == n-1){
                ans=i;
            }
            else if(ans != -1 && nums[i%n] != nums[(i-1)%n]-1){
                
                return -1;
            }
            
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int s= check(nums);
        int ans= INT_MAX;
        if(s != -1){
            ans= min(ans, min(s, n-s+2));
        }

        s= checkrev(nums);
        if(s!= -1){
            ans= min(ans, min(s+1, n-s+1));
        }
        
        return (ans==INT_MAX) ? -1 : ans;
    }
};
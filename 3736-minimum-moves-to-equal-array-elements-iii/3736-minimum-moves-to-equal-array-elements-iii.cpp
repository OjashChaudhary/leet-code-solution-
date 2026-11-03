class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int maxi=0;
        for(int i: nums){
            sum+= i;
            maxi= max(maxi, i);
        }

        return (nums.size()*maxi)-sum;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int e=1, o=0;
        int sum=0;
        int ans=0;
        const int mod= 1e9+7;
        for(int i: arr){
            sum += i;
            if(sum & 1){
                ans+= e;
                o++;
            }
            else{
                e++;
                ans+= o;
            }
            ans%=mod;
        }
        return ans;
    }
};
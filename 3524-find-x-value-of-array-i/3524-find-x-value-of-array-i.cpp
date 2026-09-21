class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<int> cnt(k, 0);
        
        for (int r = 0; r < n; r++) {
            vector<int> newCnt(k, 0);
            int mod = nums[r] % k;
            
            for (int v = 0; v < k; v++) {
                if (cnt[v] > 0) {
                    newCnt[(v * mod) % k] += cnt[v];
                }
            }
            
            newCnt[mod]++;
            
            for (int x = 0; x < k; x++) {
                ans[x] += newCnt[x];
            }
            
            cnt = newCnt;
        }
        
        return ans;
    }
};
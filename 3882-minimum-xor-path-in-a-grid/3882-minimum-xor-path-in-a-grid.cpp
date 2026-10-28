class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();

        vector<unordered_set<int>> hash(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i== 0 && j==0){
                    hash[j].insert(grid[0][0]);
                }
                else{
                    unordered_set<int> s;
                    for(int x: hash[j]){
                        s.insert(x ^ grid[i][j]);
                    }
                    hash[j]=s;

                    if(j!= 0){
                        for(int x: hash[j-1]){
                            hash[j].insert(x ^ grid[i][j]);
                        }
                    }
                }
            }
        }
        int ans= INT_MAX;
        for(int i: hash[n-1]) ans= min(ans, i);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> isl;
    int x[4]={1, -1, 0, 0};
    int y[4]={0, 0, 1, -1};
    long long sum(int i, int j){
        if(!(i>=0 && i<isl.size() && j>=0 && j<isl[0].size())) return 0;
        if(isl[i][j] ==0) return 0;

        long long res= isl[i][j];
        isl[i][j]=0;
        for(int idx=0; idx<4; idx++){
            res+= sum(i+x[idx], j+y[idx]);
        }
        return res;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m= grid.size(), n= grid[0].size();
        isl= grid;
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isl[i][j] != 0){
                    long long s= sum(i, j);
                    if(s%k == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
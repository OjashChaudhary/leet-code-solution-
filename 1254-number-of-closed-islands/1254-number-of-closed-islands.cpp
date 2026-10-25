class Solution {
public:
    vector<vector<int>> grid;
    int x[4]={1, -1, 0, 0};
    int y[4]={0, 0, 1, -1};
    bool check(int i, int j){
        if(i>=0 && j>=0 && i<grid.size() && j< grid[0].size()) return true;
        return false;
    }
    bool floodfill(int i, int j){
        if(!check(i, j)) return false;
        if(grid[i][j] == -1 || grid[i][j] == 1) return true;
        grid[i][j]= -1;
        cout<<i<<j<<endl;
        bool ans= true;
        for(int idx=0; idx<4; idx++){
            ans &= floodfill(i+x[idx], j+y[idx]);
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& gr) {
        this->grid= gr;
        int m= grid.size(), n= grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    if(floodfill(i, j)) ans++;
                }
            }
        }
        return ans;
    }
};
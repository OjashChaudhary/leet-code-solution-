class Solution {
public:
void makefalse(vector<bool>&a, int n){
    for(int i=0; i<n; i++){
        a[i]= false;
    }
}
    int countServers(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<bool> row (m, false);
        vector<bool> col (n, false);
        vector<vector<bool>> hash(m, vector<bool>(n,  false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    if(row[i] || col[j]){
                        hash[i][j] = true;
                    }
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        makefalse(row, m);
        makefalse(col, n);
        int ans=0;
        for(int i= m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){
                if(grid[i][j]==1){
                    if(row[i] || col[j]){
                        hash[i][j]=true;
                    }
                    row[i]=true;
                    col[j]=true;
                    if(hash[i][j]){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
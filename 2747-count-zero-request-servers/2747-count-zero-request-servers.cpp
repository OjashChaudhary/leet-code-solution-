class Solution {
public:
    static bool custom(vector<int>& a,  vector<int>& b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), custom);
        vector<vector<int>> q(queries.size(), vector<int>(2, 0));
        for(int i=0; i<queries.size(); i++){
            q[i]= {queries[i], i};
        }
        sort(q.begin(), q.end());
        vector<int> ans(queries.size());
        vector<int> servers(n, 0);
        int nServer=0;
        int idx=0;
        int i=0, j=0;
        while(idx < queries.size()){
            while(i<logs.size() && logs[i][1] < q[idx][0]-x){
                servers[logs[i][0]-1]--;
                if(servers[logs[i][0]-1] == 0){
                    nServer--;
                }
                i++;
            }
            while(j<logs.size() && logs[j][1] <= q[idx][0]){
                servers[logs[j][0]-1]++;
                if(servers[logs[j][0]-1] == 1){
                    nServer++;
                }
                j++;
            }
            ans[q[idx][1]]= n-nServer;
            idx++;
        }
        return ans;
    }
};
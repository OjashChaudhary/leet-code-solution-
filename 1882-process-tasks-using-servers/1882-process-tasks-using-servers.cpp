class Solution {
public:
    class custom{
        public:
        bool operator()(const pair<int, int>&a, const pair<int, int>b) const{
            if(a.first > b.first) return 1;
            if(a.first < b.first) return 0;
            return a.second > b.second;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, custom> freeServ;
        for(int i=0; i<servers.size(); i++){
            freeServ.push({servers[i], i});
        }
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> time; 
        vector<int> ans;
        int j=0; 
        while(j< tasks.size()){
            while(!time.empty() && time.top()[0] <= j){
                vector<long long> p= time.top();
                freeServ.push({p[1], p[2]});
                time.pop();
            }
            pair<int, int> p;
            if(!freeServ.empty()){
                p= freeServ.top();
                ans.push_back(p.second);
                freeServ.pop();
                time.push({j+tasks[j], servers[p.second], p.second});
            }
            else{
                vector<long long> v= time.top();
                ans.push_back(v[2]);
                v[0]+= tasks[j];
                time.pop();
                time.push(v);
            }
            j++;
        }
        return ans;
    }
};
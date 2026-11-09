class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free; 
        for(int i=0; i<k; i++) free.insert(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy; 
        vector<int> request(k, 0);
        for(int i=0; i<arrival.size(); i++){
            while(!busy.empty() && busy.top().first <= arrival[i]){
                int server= busy.top().second; busy.pop();
                free.insert(server);
            }
            if(!free.empty()){
                auto server= free.lower_bound(i % k);
                if(server == free.end()){
                    server= free.lower_bound(0);
                }
                if(server == free.end()) continue;
                request[*server]++;
                busy.push({arrival[i]+load[i], *server});
                free.erase(*server);
            }
        }
        int ans=0;
        vector<int> busiest;
        for(int i=0; i<k; i++){
            if(ans < request[i]){
                busiest.clear();
                ans= request[i];
            }
            if(ans == request[i]) busiest.push_back(i);
        }
        return busiest;
    }
};
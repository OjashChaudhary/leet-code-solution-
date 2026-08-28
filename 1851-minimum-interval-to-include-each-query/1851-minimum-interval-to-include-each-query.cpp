class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<pair<int,int>> sortedQueries(n);
        
        for (int i = 0; i < n; i++) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(n);
        int i = 0;
        
        for (auto& q : sortedQueries) {
            int query = q.first;
            int index = q.second;
            
            while (i < intervals.size() && intervals[i][0] <= query) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                pq.push({size, intervals[i][1]});
                i++;
            }
            
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            result[index] = pq.empty() ? -1 : pq.top().first;
        }
        
        return result;
    }
};
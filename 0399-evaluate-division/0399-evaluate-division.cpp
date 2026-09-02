class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            graph[a][b] = val;
            graph[b][a] = 1.0 / val;
        }
        
        vector<double> result(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];
            
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                result[i] = -1.0;
            } else {
                unordered_set<string> visited;
                result[i] = dfs(graph, start, end, visited);
            }
        }
        
        return result;
    }
    
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string current, string target, unordered_set<string>& visited) {
        if (current == target) {
            return 1.0;
        }
        
        visited.insert(current);
        
        for (auto& entry : graph[current]) {
            string neighbor = entry.first;
            double weight = entry.second;
            
            if (visited.find(neighbor) == visited.end()) {
                double res = dfs(graph, neighbor, target, visited);
                
                if (res != -1.0) {
                    return weight * res;
                }
            }
        }
        
        return -1.0;
    }
};
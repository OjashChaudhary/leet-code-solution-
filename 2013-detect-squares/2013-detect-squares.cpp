class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> pointCount;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pointCount[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        if (pointCount.find(x) == pointCount.end()) {
            return 0;
        }
        
        int total = 0;
        
        for (auto& entry : pointCount[x]) {
            int y2 = entry.first;
            int countY2 = entry.second;
            
            if (y2 == y) {
                continue;
            }
            
            int side = y2 - y;
            int x2 = x + side;
            
            if (pointCount.find(x2) != pointCount.end()) {
                int count1 = pointCount[x2].count(y) ? pointCount[x2][y] : 0;
                int count2 = pointCount[x2].count(y2) ? pointCount[x2][y2] : 0;
                total += countY2 * count1 * count2;
            }
            
            int x4 = x - side;
            
            if (pointCount.find(x4) != pointCount.end()) {
                int count1 = pointCount[x4].count(y) ? pointCount[x4][y] : 0;
                int count2 = pointCount[x4].count(y2) ? pointCount[x4][y2] : 0;
                total += countY2 * count1 * count2;
            }
        }
        
        return total;
    }
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
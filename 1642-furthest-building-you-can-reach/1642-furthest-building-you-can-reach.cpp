class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;

        for (int i = 0; i < heights.size() - 1; i++) {
            int jump = heights[i + 1] - heights[i];

            if (jump <= 0)
                continue;

            bricks -= jump;
            pq.push(jump);

            if (bricks < 0) {
                if (ladders == 0)
                    return i;

                bricks += pq.top();
                pq.pop();
                ladders--;
            }
        }

        return heights.size() - 1;
    }
};
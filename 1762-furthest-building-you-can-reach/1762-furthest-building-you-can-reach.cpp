class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        priority_queue<int> pq;

        int i = 0;
        while(i < n-1) {
            int diff = heights[i+1] - heights[i];

            if(diff <= 0) {
                i++;
                continue;
            }

            bricks -= diff;
            pq.push(diff);
            if(bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }

            if(ladders < 0) break;
            i++;
        }

        return i;
    }
};
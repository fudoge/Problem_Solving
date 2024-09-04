class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // n, w, s, e
        vector<pair<int, int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int dircode = 0; 
        pair<int, int> pos = {0, 0};
        int ans = 0;

        unordered_set<string> obstacleSet;
        for(const auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for(int command : commands) {
            if(command == -2) {
                dircode = (dircode + 1) % 4;
            } else if(command == -1) {
                dircode = (dircode + 3) % 4;
            } else {
                for(int i = 0; i < command; ++i) {
                    int nextX = pos.first + directions[dircode].first;
                    int nextY = pos.second + directions[dircode].second;
                    string nextPos = to_string(nextX) + "," + to_string(nextY);

                    if(obstacleSet.count(nextPos)) break;

                    pos.first = nextX;
                    pos.second = nextY;

                    ans = max(ans, pos.first * pos.first + pos.second * pos.second);
                }
            }
        }

        return ans;
    }
};
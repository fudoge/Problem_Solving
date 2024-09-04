#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<char> directions = {'n', 'w', 's', 'e'}; // 0: north, 1: west, 2: south, 3: east
        pair<int, int> pos;
        pos = {0, 0};
        char direction = 'n';
        int dircode = 0;
        int ans = 0;

        unordered_map<int, vector<int>> xAxisObs;
        unordered_map<int, vector<int>> yAxisObs;

        for(const auto &obstacle : obstacles) {
            int x = obstacle[0];
            int y = obstacle[1];

            xAxisObs[x].push_back(y);
            yAxisObs[y].push_back(x);
        }

        for(auto &element : xAxisObs) {
            sort(element.second.begin(), element.second.end());
        }

        for(auto &element : yAxisObs) {
            sort(element.second.begin(), element.second.end());
        }

        for(int command : commands) {
            if(command == -2) {
                direction = directions[(dircode = (dircode +1 +4) % 4)];
            } else if(command == -1) {
                direction = directions[(dircode = (dircode -1 +4) % 4)];
            } else {
                int k = command;
                bool flag = true;
                switch (direction) {
                    case 'n': {
                        int xPos = pos.first;
                        int yPos = pos.second;
                        int yGoal = yPos + k;
                        for(int candidatedObs : xAxisObs[xPos]) {
                            if(candidatedObs > yPos && candidatedObs <= yGoal) {
                                flag = false;
                                yPos = candidatedObs-1;
                                break;
                            }
                        }
                        if(flag) yPos = yGoal;
                        pos.second = yPos;
                        break;
                    }
                    case 'w': {
                        int xPos = pos.first;
                        int yPos = pos.second;
                        int xGoal = xPos - k;
                        for(int candidatedObs : yAxisObs[yPos]) {
                            if(candidatedObs < xPos && candidatedObs >= xGoal) {
                                flag = false;
                                xPos = candidatedObs+1;
                                break;
                            }
                        }
                        if(flag) xPos = xGoal;
                        pos.first = xPos;
                        break;
                    }
                    case 's': {
                        int xPos = pos.first;
                        int yPos = pos.second;
                        int yGoal = yPos - k;
                        for(int candidatedObs : xAxisObs[xPos]) {
                            if(candidatedObs < yPos && candidatedObs >= yGoal) {
                                flag = false;
                                yPos = candidatedObs+1;
                                break;
                            }
                        }
                        if(flag) yPos = yGoal;
                        pos.second = yPos;
                        break;
                    }
                    case 'e': {
                        int xPos = pos.first;
                        int yPos = pos.second;
                        int xGoal = xPos + k;
                        for(int candidatedObs : yAxisObs[yPos]) {
                            if(candidatedObs > xPos && candidatedObs <= xGoal) {
                                flag = false;
                                xPos = candidatedObs-1;
                                break;
                            }
                        }
                        if(flag) xPos = xGoal;
                        pos.first = xPos;
                        break;
                    }
                }
                ans = max(ans, pos.first*pos.first + pos.second*pos.second);
            }
        }

        return ans;
    }
};
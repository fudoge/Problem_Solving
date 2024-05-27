class Solution {
public:
    void move(char cmd, pair<int, int> &pos) {
        switch(cmd) {
            case 'N':
                pos.second++;
                return;
            case 'S':
                pos.second--;
                return;
            case 'E':
                pos.first++;
                return;
            case 'W':
                pos.first--;
                return;
        }
    }

    bool isPathCrossing(string path) {
        pair<int, int> pos = {0, 0};
        set<pair<int, int>> s;
        s.insert(pos);
        for(const auto &cmd : path) {
            move(cmd, pos);
            if(s.find(pos) != s.end()) return true;
            s.insert(pos);
        }
        return false;
    }
};
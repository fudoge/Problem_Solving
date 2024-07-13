struct Robot {
    int id;
    int position;
    int health;
    char direction;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Robot> Robots;
        for(int i = 0; i < positions.size(); i++) {
            Robots.push_back({i+1, positions[i], healths[i], directions[i]});
        }

        sort(Robots.begin(), Robots.end(), [](const auto &a, const auto &b){
            return a.position < b.position;
        });

        vector<Robot> survived;
        stack<Robot> st;
        for(int i = 0; i < Robots.size(); i++) {
            if(Robots[i].direction == 'R') {
                st.push(Robots[i]);
            } else {
                while(st.size() > 0 && Robots[i].health > 0) {
                    if(st.top().health < Robots[i].health) {
                        st.pop();
                        Robots[i].health--;
                    } else if(st.top().health == Robots[i].health) {
                        st.pop();
                        Robots[i].health = 0;
                    } else {
                        st.top().health--;
                        Robots[i].health = 0;
                    }
                }
                if(Robots[i].health > 0) survived.push_back(Robots[i]);
            }
        }

        while(!st.empty()) {
            survived.push_back(st.top());
            st.pop();
        }

        sort(survived.begin(), survived.end(), [](const auto &a, const auto &b){
            return a.id < b.id;
        });

        vector<int> ans;
        for(const auto r : survived) {
            ans.push_back(r.health);
        }

        return ans;
    }
};
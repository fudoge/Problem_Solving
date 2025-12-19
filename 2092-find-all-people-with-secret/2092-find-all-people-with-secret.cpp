class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b){
            return a[2] < b[2];
        });

        vector<bool> knows(n);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        while(i < m) {
            int time = meetings[i][2];

            unordered_map<int, int> parent;

            auto ensure = [&](int x) {
                if(!parent.count(x)) parent[x] = x;
            };

            function<int(int)> find = [&](int x) {
                if(parent[x] == x) return x;
                return parent[x] = find(parent[x]);
            };

            auto unite = [&](int x, int y) {
                x = find(x);
                y = find(y);
                if(x != y) parent[y] = x;
            };

            int j = i;
            while(j < m && meetings[j][2] == time) {
                int x = meetings[j][0];
                int y = meetings[j][1];
                ensure(x);
                ensure(y);
                unite(x, y);
                j++;
            }

            unordered_set<int> goodRoots;
            for(int k = i; k < j; k++) {
                int x = meetings[k][0];
                int y = meetings[k][1];
                if(knows[x] || knows[y]) {
                    goodRoots.insert(find(x));
                    goodRoots.insert(find(y));
                }
            }

            for(int k = i; k < j; k++) {
                int x = meetings[k][0];
                int y = meetings[k][1];
                if(goodRoots.count(find(x))) {
                    knows[x] = true;
                    knows[y] = true;
                }
            }

            i = j;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(knows[i]) ans.emplace_back(i);
        }

        return ans;
    }
};
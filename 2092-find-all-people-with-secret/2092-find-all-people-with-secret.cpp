class Solution {
public:
    int find(vector<int>& parent, int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }
    void unite(vector<int>& parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);

        if(x == y) return;
        if(x < y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const auto &a, const auto &b){
            return a[2] < b[2];
        });

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        unite(parent, 0, firstPerson);

        for(int l = 0, r = 0; l < meetings.size();) {
            for(; r < meetings.size() && meetings[l][2] == meetings[r][2]; ++r) {
                unite(parent, meetings[r][0], meetings[r][1]);
            }

            for(int s = find(parent, 0); l < r; ++l) {
                if(find(parent, meetings[l][0]) != s) parent[meetings[l][0]] = meetings[l][0];
                if(find(parent, meetings[l][1]) != s) parent[meetings[l][1]] = meetings[l][1];
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(parent[i] == 0) ans.emplace_back(i);
        }

        return ans;
    }
};
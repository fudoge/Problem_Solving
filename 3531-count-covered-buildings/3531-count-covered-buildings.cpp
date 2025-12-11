using ll = long long;
class Solution {
public:
    ll getid(vector<int>& x) {
        return (ll)x[0] * 100000 + x[1];
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        unordered_map<ll, bool> ok;
        vector<vector<int>> xAxis = buildings; 
        vector<vector<int>> yAxis = buildings; 
               
        for(auto building : buildings) {
            ok[getid(building)] = true;
        }

        sort(xAxis.begin(), xAxis.end(), [](const auto &a, const auto &b){
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }    
            return a[0] < b[0];
        });
        sort(yAxis.begin(), yAxis.end(), [](const auto &a, const auto &b){
            if(a[1] == b[1]) {
                return a[0] < b[0];
            }    
            return a[1] < b[1];
        });

        for(int i = 0; i < m; i++) {
            if(i == 0 || i == m-1 || xAxis[i-1][0] != xAxis[i][0] || xAxis[i+1][0] != xAxis[i][0]) ok[getid(xAxis[i])] = false;
            if(i == 0 || i == m-1 || yAxis[i-1][1] != yAxis[i][1] || yAxis[i+1][1] != yAxis[i][1]) ok[getid(yAxis[i])] = false;
        }

        int ans = 0;
        for(const auto &[_, v] : ok) {
            ans += v;
        }
        return ans;
    }
};
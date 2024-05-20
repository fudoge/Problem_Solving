class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees (n, 0);
        set<pair<int, int>> directConnections;

        for(auto road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
            directConnections.insert({min(road[0], road[1]), max(road[0], road[1])});
        }

        int maxRank = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int rank = degrees[i] + degrees[j];

                if(directConnections.find({i, j}) != directConnections.end()) {
                    rank--;
                } 

                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;

    }
};
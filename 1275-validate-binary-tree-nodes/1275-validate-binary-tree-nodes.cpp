class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                graph[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
            if(rightChild[i] != -1) {
                graph[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }

        queue<int> q;
        vector<int> visited(n, false);

        int startIdx = distance(indegree.begin(), min_element(indegree.begin(), indegree.end()));
        q.push(startIdx);
        visited[startIdx] = true;

        while(!q.empty()) {
            const auto curr = q.front();
            q.pop();

            for(const auto& next : graph[curr]) {
                if(visited[next]) {
                    return false;
                } else {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        bool isOnlyBinary = true;
        for(const auto& v : visited) {
            isOnlyBinary &= v;
            cout << v << endl;
        }

        return isOnlyBinary;
    }
};
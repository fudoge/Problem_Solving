#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    void insertNum(vector<int>& arr, int num) {
        if (arr.empty()) {
            arr.push_back(num);
            return;
        }
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (num == arr[mid]) return;
            else if (num > arr[mid]) left = mid + 1;
            else right = mid;
        }
        if (arr[left] == num) return;
        if (num > arr[left]) arr.insert(arr.begin() + left + 1, num);
        else arr.insert(arr.begin() + left, num);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n);
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (const auto &edge : edges) {
            int src = edge[0];
            int dst = edge[1];
            graph[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (const auto &nextNode : graph[curr]) {
                for (int ancestor : answer[curr]) {
                    insertNum(answer[nextNode], ancestor);
                }
                insertNum(answer[nextNode], curr);
                if (--indegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        return answer;
    }
};
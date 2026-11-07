class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle; // {weight, i};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> running; // {end_time, i};
        for(int i = 0; i < n; i++) {
            idle.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;
        for(int j = 0; j < m; j++) {
            time = max(time, (long long) j);

            while(!running.empty() && running.top().first <= time) {
                int i = running.top().second;
                running.pop();
                idle.push({servers[i], i});
            }

            if(idle.empty()) {
                time = running.top().first;

                while(!running.empty() && running.top().first <= time) {
                    int i = running.top().second;
                    running.pop();
                    idle.push({servers[i], i});
                }
            }

            int i = idle.top().second;
            idle.pop();

            ans[j] = i;
            running.push({time + tasks[j], i});
        }

        return ans;
    }
};
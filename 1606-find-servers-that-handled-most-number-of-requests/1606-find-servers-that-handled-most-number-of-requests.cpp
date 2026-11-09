#pragma GCC optimize("03", "unroll-loops");
static const int __ = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        // endtime, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        set<int> idle_servers;
        for(int i = 0; i < k; i++) idle_servers.insert(i);

        vector<int> req_count(k);
        for(int i = 0; i < n; i++) {
            int arr = arrival[i];
            while(!pq.empty() && pq.top().first <= arr) {
                auto t = pq.top();
                pq.pop();

                idle_servers.insert(t.second);
            }

            if(idle_servers.size() > 0) {
                int target = i%k;
                auto it = idle_servers.lower_bound(target);
                if(it == idle_servers.end()) {
                    it = idle_servers.begin();
                }
                int server_id = *it;
                idle_servers.erase(server_id);

                int endtime = arr + load[i];
                pq.push({endtime, server_id});
                req_count[server_id]++;
            }
        }

        int max_req = *max_element(req_count.begin(), req_count.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            if(req_count[i] == max_req) ans.emplace_back(i);
        }

        return ans;
    }
};
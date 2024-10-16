struct comp {
    bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq; // {char, count}
        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        string str = "";
        char last = '\0';
        int streak = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (top.second == 0) continue;
            
            if (top.first == last && streak == 2) {
                if (pq.empty()) break;

                auto secondary = pq.top();
                pq.pop();

                str += secondary.first;
                last = secondary.first;
                streak = 1;

                if (--secondary.second > 0) pq.push(secondary);
                
                pq.push(top);
            } else {
                str += top.first;
                if (top.first == last) {
                    streak++;
                } else {
                    streak = 1;
                    last = top.first;
                }
                if (--top.second > 0) pq.push(top);
            }
        }

        return str;
    }
};
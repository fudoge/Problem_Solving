class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> s;
        pq.push(1);
        while(true) {
            long long x = pq.top();
            if(--n <= 0) return x;
            pq.pop();
            s.erase(x);

            if(x*2 <= INT_MAX && s.find(x*2) == s.end()) {
                pq.push(x*2);
                s.insert(x*2);
            }
            if(x*3 <= INT_MAX && s.find(x*3) == s.end()) {
                pq.push(x*3);
                s.insert(x*3);
            }
            if(x*5 <= INT_MAX && s.find(x*5) == s.end()) {
                pq.push(x*5);
                s.insert(x*5);
            }
        }
        return -1;
    }
};
#pragma GCC optimize("O3", "unroll-loops");
static const int __ = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
using ll = long long;

struct PairHash {
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &v) const {
        auto h1 = hash<T1>{}(v.first);
        auto h2 = hash<T2>{}(v.second);
        return h1 ^ h2;
    }
};

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<pair<ll, ll>, unordered_map<ll, int>, PairHash> slopeToIntercept;
        unordered_map<pair<ll, ll>, unordered_map<pair<ll, ll>, int, PairHash>, PairHash> midToSlope;

        for(int i = 0; i < n; i++) {
            ll x1 = points[i][0];
            ll y1 = points[i][1];
            for(int j = i + 1; j < n; j++) {
                ll x2 = points[j][0];
                ll y2 = points[j][1];
                ll dx = x1 - x2;
                ll dy = y1 - y2;

                ll g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                pair<ll, ll> slope = {dy, dx};
                
                // line constant
                ll c = dy * x1 - dx * y1;
                pair<ll, ll> mid = {x1+x2, y1+y2};
                slopeToIntercept[slope][c]++;
                midToSlope[mid][slope]++;
            }
        }

        int ans = 0;
        for(auto &it : slopeToIntercept) {
            auto &inner = it.second;
            ll sum = 0;
            for(auto &kv : inner) {
                ll cnt = kv.second;
                ans += sum * cnt;
                sum += cnt;
            }
        }

        for(auto &it : midToSlope) {
            auto &inner = it.second;
            ll sum = 0;
            for(auto &kv : inner) {
                ll cnt = kv.second;
                ans -= sum * cnt;
                sum += cnt;
            }
        }

        return ans;
    }
};
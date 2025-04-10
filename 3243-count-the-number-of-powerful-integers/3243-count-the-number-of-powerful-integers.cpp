using ll = long long;
class Solution {
   public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string strt = to_string(start - 1), fin = to_string(finish);
        return calc(fin, s, limit) - calc(strt, s, limit);
    }

    ll calc(string x, string s, int limit) {
        if (x.size() < s.size()) return 0;
        if (x.size() == s.size()) return x >= s ? 1 : 0;

        string suffix = x.substr(x.size() - s.size(), s.size());
        ll count = 0;
        int prefLen = x.size() - s.size();

        for (int i = 0; i < prefLen; i++) {
            if (limit < (x[i] - '0')) {
                count += (ll)pow(limit + 1, prefLen - i);
                return count;
            }
            count += (ll)(x[i] - '0') * (ll)pow(limit + 1, prefLen - 1 - i);
        }
        if (suffix >= s) count++;

        return count;
    }
};
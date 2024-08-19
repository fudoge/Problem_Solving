class Solution {
private:
    vector<int> dp;
    set<int> primes;
public:
    set<int> get_divisors(int n) {
        set<int> res;
        for(int i = 2; i <= n/2; i++) {
            if(n % i == 0) {
                res.insert(i);
            }
        }
        return res;
    }
    int solve(int n) {
        if(n <= 1) return 0;
        if(dp[n] != -1) return dp[n];
        if(primes.find(n) != primes.end()) return dp[n] = n;

        auto divisors = get_divisors(n);
        int res = INT_MAX;
        
        for(auto &divisor : divisors) {
            res = min(res, solve(n / divisor) + divisor);
            res = min(res, solve(divisor) + n / divisor);
        }

        return dp[n] = res;
    }

    bool isPrime(int x) {
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0) return false;
        }
        return true;
    }

    int minSteps(int n) {
        for(int i = 2; i <= n; i++) {
            if(isPrime(i)) primes.insert(i);
        }
        dp.resize(n+1, -1);
        dp[0] = 0;
        dp[1] = 0;

        return solve(n);
    }
};
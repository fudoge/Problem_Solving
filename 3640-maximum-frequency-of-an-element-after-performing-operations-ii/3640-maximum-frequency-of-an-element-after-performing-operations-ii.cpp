#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}();
using ll = long long;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    ll n = nums.size();
    ll ans = 0;
    sort(nums.begin(), nums.end());

    vector<pair<int, int>> parr;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j < n && nums[j] == nums[i]) {
        j++;
      }
      int cnt = j - i;
      parr.emplace_back(nums[i], cnt);

      i = j - 1;
    }

    vector<pair<ll, ll>> prev_cand;
    for (int i = 0; i < parr.size(); i++) {
      prev_cand.emplace_back(parr[i].first, parr[i].second);
      prev_cand.emplace_back(parr[i].first + k, 0);
    }
    sort(prev_cand.begin(), prev_cand.end());
    vector<pair<ll, ll>> candidates;
    for (int i = 0; i < prev_cand.size(); i++) {
      if (i + 1 < prev_cand.size() &&
          prev_cand[i].first == prev_cand[i + 1].first) {
        candidates.emplace_back(prev_cand[i].first,
                                prev_cand[i].second + prev_cand[i + 1].second);
        i++;
      } else {
        candidates.emplace_back(prev_cand[i].first, prev_cand[i].second);
      }
    }

    for (int i = 0; i < candidates.size(); i++) {
      ll curr = candidates[i].first;
      ll cnt = candidates[i].second;
      ll l = lower_bound(nums.begin(), nums.end(), curr - k) - nums.begin();
      ll r = upper_bound(nums.begin(), nums.end(), curr + k) - nums.begin();

      ll x = min((ll)numOperations, r - l - cnt) + cnt;
      ans = max(ans, x);
    }

    return ans;
  }
};
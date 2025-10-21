#pragma GCC optimize("O3", "unroll-loops");
static const int __ = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  return 0;
}();

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    int MAX = 100001;
    int inc[MAX + 1];
    int freq[MAX + 1];
    memset(inc, 0, sizeof(inc));
    memset(freq, 0, sizeof(freq));

    int l = MAX, r = 0;
    for (int num : nums) {
      int tl = max(0, num - k);
      int tr = min(MAX, num + k + 1);
      inc[tl]++;
      inc[tr]--;
      freq[num]++;

      l = min(l, tl);
      r = max(r, tr);
    }

    int ans = 0;
    int curr = 0;
    for (int i = l; i <= r; i++) {
      curr += inc[i];
      int x = min(numOperations, curr - freq[i]) + freq[i];
      ans = max(ans, x);
    }
    return ans;
  }
};
struct FenwickTree {
    vector<int> tree;

    FenwickTree(int size) : tree(size + 1) {}

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }
};
class Solution {
   public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> pos2(n), reversed(n);
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversed[pos2[nums1[i]]] = i;
        }
        FenwickTree tree(n);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int pos = reversed[i];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n - 1 - pos) - (i - left);

            ans += 1LL * left * right;
        }

        return ans;
    }
};
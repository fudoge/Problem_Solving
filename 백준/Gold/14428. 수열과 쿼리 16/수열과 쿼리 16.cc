#include <bits/stdc++.h>

#include <ios>

using namespace std;

int arr[100001];
int seg[400004];

void init(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = l;
        return;
    }

    int mid = (l + r) >> 1;

    init(idx * 2 + 1, l, mid);
    init(idx * 2 + 2, mid + 1, r);
    seg[idx] = arr[seg[idx * 2 + 1]] <= arr[seg[idx * 2 + 2]]
                   ? seg[idx * 2 + 1]
                   : seg[idx * 2 + 2];
}

void update(int idx, int l, int r, int updatedIdx) {
    if (l > r) return;
    if (updatedIdx < l || updatedIdx > r) return;
    if (l == r) {
        seg[idx] = l;
        return;
    }

    int mid = (l + r) >> 1;
    update(idx * 2 + 1, l, mid, updatedIdx);
    update(idx * 2 + 2, mid + 1, r, updatedIdx);
    seg[idx] = arr[seg[idx * 2 + 1]] <= arr[seg[idx * 2 + 2]]
                   ? seg[idx * 2 + 1]
                   : seg[idx * 2 + 2];
}

int query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return -1;
    if (ql <= l && r <= qr) return seg[idx];

    int mid = (l + r) >> 1;
    int lres = query(idx * 2 + 1, l, mid, ql, qr);
    int rres = query(idx * 2 + 2, mid + 1, r, ql, qr);

    if (lres == -1 && rres == -1) return -1;
    if (lres == -1) return rres;
    if (rres == -1) return lres;

    return arr[lres] <= arr[rres] ? lres : rres;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int op, ii, x;
        cin >> op >> ii >> x;

        if (op == 1) {
            arr[ii] = x;
            update(1, 1, n, ii);
        } else {
            cout << query(1, 1, n, ii, x) << "\n";
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll arr[1000001], seg[4000004];

void build(int index, int l, int r) {
    if (l == r) {
        seg[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(index * 2, l, mid);
    build(index * 2 + 1, mid + 1, r);
    seg[index] = seg[index * 2] * seg[index * 2 + 1] % MOD;
}

void update(int index, int target, int newVal, int l, int r) {
    if(l == r) {
        arr[l] = newVal;
        seg[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    if(target <= mid) {
        update(index*2 ,target, newVal, l, mid);
    } else {
        update(index*2+1, target, newVal, mid+1, r);
    }
    seg[index] = seg[index * 2] * seg[index * 2 + 1] % MOD;
}

ll query(int index, int ql, int qr, int l, int r) {
    if (r < ql || qr < l) return 1;
    if (ql <= l && r <= qr) return seg[index];
    int mid = (l + r) / 2;
    return query(index * 2, ql, qr, l, mid) * query(index * 2 + 1, ql, qr, mid + 1, r) % MOD;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n;++i) {
        cin >> arr[i];
    }
    build(1, 1, n);

    for(int i = 0; i < m+k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, b, c, 1, n);
        } else {
            cout << query(1, b, c, 1, n) << '\n';
        }
    }

    return 0;
}

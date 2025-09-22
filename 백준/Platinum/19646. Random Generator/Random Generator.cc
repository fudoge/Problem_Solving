#include <bits/stdc++.h>
#define MAX 200001

using namespace std;


int w[MAX];
int seg[MAX*4];
int n;

void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx] = w[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(idx *2, l, mid);
    build(idx *2 + 1, mid+1, r);
    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

void update(int idx, int target, int l, int r) {
    if(l == r) {
        w[l] = 0;;
        seg[idx] = 0;
        return;
    }

    int mid = (l + r) >> 1;
    if(target <= mid) {
        update(idx *2, target, l, mid);
    } else {
        update(idx*2+1, target, mid+1, r);
    }

    seg[idx] = seg[idx * 2] + seg[idx*2 + 1];
}

int findKth(int idx, int l, int r, int k) {
    if (l == r) return l;
    int leftSum = seg[idx*2];
    int mid = (l + r) >> 1;
    if(k <= leftSum) return findKth(idx*2, l, mid, k);
    else return findKth(idx*2+1, mid+1, r, k-leftSum);
}

int main (int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    build(1, 1, n);

    for(int i = 0; i < n ; i++) {
        int p;
        cin >> p;

        int idx = findKth(1, 1, n, p);
        cout << idx << " ";
        update(1, idx, 1, n);
    }
    cout << "\n";

    return 0;
}

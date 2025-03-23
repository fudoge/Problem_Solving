#include <bits/stdc++.h>

using namespace std;
const int LIMIT = 1e6 + 1;

vector<int> parent(LIMIT);
vector<int> groupSize(LIMIT, 1);

int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void merge(int x, int y) {
    int xRoot = getRoot(x);
    int yRoot = getRoot(y);

    if (xRoot == yRoot) return;
    if (xRoot < yRoot) {
        parent[yRoot] = xRoot;
        groupSize[xRoot] += groupSize[yRoot];
    } else {
        parent[xRoot] = yRoot;
        groupSize[yRoot] += groupSize[xRoot];
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    iota(parent.begin(), parent.end(), 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'I') {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        } else {
            int c;
            cin >> c;
            cout << groupSize[getRoot(c)] << "\n";
        }
    }

    return 0;
}
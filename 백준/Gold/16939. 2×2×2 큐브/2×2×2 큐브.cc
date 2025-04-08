#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& cube) {
    for (int i = 1; i < 25; i += 4) {
        if (!(cube[i] == cube[i + 1] && cube[i + 1] == cube[i + 2] &&
              cube[i + 2] == cube[i + 3]))
            return false;
    }
    return true;
}

void rotate(int a, int b, int c, int d, vector<int>& cube) {
    int temp = cube[d];
    cube[d] = cube[c];
    cube[c] = cube[b];
    cube[b] = cube[a];
    cube[a] = temp;
}

int main(int argc, char* argv[]) {
    vector<int> cube(25);
    for (int i = 1; i < 25; i++) {
        cin >> cube[i];
    }

    bool ans = false;

    // 1
    auto dup = cube;
    rotate(1, 5, 9, 24, dup);
    rotate(3, 7, 11, 22, dup);
    ans |= check(dup);

    // 2
    dup = cube;
    rotate(24, 9, 5, 1, dup);
    rotate(22, 11, 7, 3, dup);
    ans |= check(dup);

    // 3
    dup = cube;
    rotate(2, 6, 10, 23, dup);
    rotate(4, 8, 12, 21, dup);
    ans |= check(dup);

    // 4
    dup = cube;
    rotate(23, 10, 6, 2, dup);
    rotate(21, 12, 8, 4, dup);
    ans |= check(dup);

    // 5
    dup = cube;
    rotate(13, 5, 17, 21, dup);
    rotate(14, 6, 18, 22, dup);
    ans |= check(dup);

    // 6
    dup = cube;
    rotate(21, 17, 5, 13, dup);
    rotate(22, 18, 6, 14, dup);
    ans |= check(dup);

    // 7
    dup = cube;
    rotate(15, 7, 19, 23, dup);
    rotate(16, 8, 20, 24, dup);
    ans |= check(dup);

    // 8
    dup = cube;
    rotate(23, 19, 7, 15, dup);
    rotate(24, 20, 8, 16, dup);
    ans |= check(dup);

    // 9
    dup = cube;
    rotate(14, 9, 19, 4, dup);
    rotate(16, 10, 17, 3, dup);
    ans |= check(dup);

    // 10
    dup = cube;
    rotate(4, 19, 9, 14, dup);
    rotate(3, 17, 10, 16, dup);
    ans |= check(dup);

    // 11
    dup = cube;
    rotate(13, 11, 20, 2, dup);
    rotate(15, 12, 18, 1, dup);
    ans |= check(dup);

    // 12
    dup = cube;
    rotate(2, 20, 11, 13, dup);
    rotate(1, 18, 12, 15, dup);
    ans |= check(dup);

    cout << (ans ? "1\n" : "0\n");

    return 0;
}
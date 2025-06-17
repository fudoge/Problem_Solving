#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;

    unordered_map<int, int> freq;
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int> maxHeap;

    for (int i = 0; i < k; i++) {
        char op;
        int num;
        cin >> op >> num;
        if (op == 'I') {
            freq[num]++;
            minHeap.emplace(num);
            maxHeap.emplace(num);
        } else if (num == -1) {
            while (!minHeap.empty() && freq[minHeap.top()] <= 0) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                freq[minHeap.top()]--;
                minHeap.pop();
            }
        } else {
            while (!maxHeap.empty() && freq[maxHeap.top()] <= 0) {
                maxHeap.pop();
            }
            if (!maxHeap.empty()) {
                freq[maxHeap.top()]--;
                maxHeap.pop();
            }
        }
    }

    while (!minHeap.empty() && freq[minHeap.top()] <= 0) minHeap.pop();
    while (!maxHeap.empty() && freq[maxHeap.top()] <= 0) maxHeap.pop();
    if (minHeap.empty() || maxHeap.empty()) {
        cout << "EMPTY\n";
    } else {
        cout << maxHeap.top() << " " << minHeap.top() << "\n";
    }
}
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
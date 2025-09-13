#include <bits/stdc++.h>

using namespace std;

string romans = "ABC";
string ans;

bool check(string &conc) {
    int curr = 0;
    for (int i = 0; i < conc.size(); i++) {
        if (conc[i] == '|') {
            curr++;
            continue;
        }
        if (conc[i] != romans[curr]) {
            return false;
        }
    }

    return true;
}

void cut(string &conc, string &a, string &b, string &c) {
    int i = 0;
    while (i < conc.size() && conc[i] != '|') {
        a += conc[i];
        i++;
    }
    i++;
    while (i < conc.size() && conc[i] != '|') {
        b += conc[i];
        i++;
    }
    i++;
    while (i < conc.size() && conc[i] != '|') {
        c += conc[i];
        i++;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a = "", b = "", c = "";
    int al, bl, cl;

    unordered_map<string, int> dist;
    cin >> al;
    if (al > 0) cin >> a;
    cin >> bl;
    if (bl > 0) cin >> b;
    cin >> cl;
    if (cl > 0) cin >> c;

    string state = a + '|' + b + '|' + c;
    dist[state] = 0;

    queue<string> q;
    q.emplace(state);
    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (check(curr)) {
            ans = curr;
            break;
        }

        string A, B, C;
        cut(curr, A, B, C);

        if (!A.empty()) {
            char disk = A.back();
            string poppedA = A;
            poppedA.pop_back();

            {
                string nextB = B;
                nextB.push_back(disk);
                string newState = poppedA + '|' + nextB + '|' + C;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }

            {
                string nextC = C;
                nextC.push_back(disk);
                string newState = poppedA + '|' + B + '|' + nextC;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }
        }

        if (!B.empty()) {
            char disk = B.back();
            string poppedB = B;
            poppedB.pop_back();

            {
                string nextA = A;
                nextA.push_back(disk);
                string newState = nextA + '|' + poppedB + '|' + C;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }

            {
                string nextC = C;
                nextC.push_back(disk);
                string newState = A + '|' + poppedB + '|' + nextC;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }
        }

        if (!C.empty()) {
            char disk = C.back();
            string poppedC = C;
            poppedC.pop_back();

            {
                string nextA = A;
                nextA.push_back(disk);
                string newState = nextA + '|' + B + '|' + poppedC;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }

            {
                string nextB = B;
                nextB.push_back(disk);
                string newState = A + '|' + nextB + '|' + poppedC;
                if (dist.find(newState) == dist.end()) {
                    dist[newState] = dist[curr] + 1;
                    q.push(newState);
                }
            }
        }
    }

    cout << dist[ans] << "\n";

    return 0;
}

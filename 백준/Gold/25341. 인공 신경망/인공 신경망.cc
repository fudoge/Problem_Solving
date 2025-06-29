#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> hidden_inputs(m + 1);
    vector<vector<ll>> hidden_weights(m + 1);
    vector<ll> hidden_biases(m + 1);

    vector<ll> tot_weights(n + 1);
    ll final_bias;
    for (int i = 1; i <= m; i++) {
        int c;
        cin >> c;

        hidden_inputs[i].resize(c + 1);
        hidden_weights[i].resize(c + 1);

        for (int j = 1; j <= c; j++) cin >> hidden_inputs[i][j];
        for (int j = 1; j <= c; j++) cin >> hidden_weights[i][j];

        cin >> hidden_biases[i];
    }

    for (int i = 1; i <= m; i++) {
        ll w;
        cin >> w;
        for (int j = 1; j < hidden_inputs[i].size(); j++) {
            tot_weights[hidden_inputs[i][j]] += hidden_weights[i][j] * w;
        }
        hidden_biases[i] *= w;
    }
    cin >> final_bias;
    for (int i = 1; i <= m; i++) {
        final_bias += hidden_biases[i];
    }

    vector<vector<ll>> inputs(q, vector<ll>(n + 1));
    for (int i = 0; i < q; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> inputs[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        ll res = 0;
        for (int j = 1; j <= n; j++) {
            res += tot_weights[j] * inputs[i][j];
        }
        res += final_bias;
        cout << res << "\n";
    }

    return 0;
}
int main() {
    vector<vector<ll>> g(n, vector<ll>(n));
    fori(i, 0, n) {
        fori(j, 0, n) {
            cin >> g[i][j];
        }
    }

    fori(i, 0, n) {
        fori(j, 0, n) {
            if (g[i][j] == -1)
                g[i][j] = INF;
        }
    }

    vector<vector<ll>> v = g;
    fori(k, 0, n) {
        fori(i, 0, n) {
            fori(j, 0, n) {
                if (v[i][k] != INF and v[k][j] != INF and v[i][k] + v[k][j] < v[i][j])
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
}
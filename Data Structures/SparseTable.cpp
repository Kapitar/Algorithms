class SparseTable {
public:
    vector <vector<int>> d;
    int n;
    vector<int> lg;

    explicit SparseTable(const vector<int> &v) {
        n = v.size();
        lg.resize(n + 1);
        for (int i = 2 ; i <= n ; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        d.resize(lg[n] + 1, vector<int>(n, INF));
        d[0] = v;
        for (int k = 1 ; k <= lg[n] ; ++k) {
            for (int i = 0 ; i + (1 << k) <= n ; ++i) {
                d[k][i] = min(d[k - 1][i], d[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int get(int l, int r) {
        int q = lg[r - l + 1];
        return min(d[q][l], d[q][r - (1 << q) + 1]);
    }
};
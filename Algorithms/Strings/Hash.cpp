struct Hash {
    int p, k;
    vector<int> v, pows;

    vector<int> build_pows(int n) {
        pows.resize(n + 1);
        pows[0] = 1;

        for (int i = 1; i <= n; i++) {
            pows[i] = (pows[i - 1] * k) % p;
        }

        return pows;
    }

    void build(string a, int p, int k) {
        this->p = p;
        this->k = k;

        v.resize((int) a.size() + 1, 0);
        build_pows((int) a.size() + 1);
        for (int i = 0; i < a.size(); i++) {
            v[i + 1] = (v[i] * k + a[i] - 'a' + 1) % p;
        }
    }

    int sub_hash(int l, int r) {
        return ((v[r + 1] - v[l] * pows[r - l + 1]) % p + p) % p;
    }
};
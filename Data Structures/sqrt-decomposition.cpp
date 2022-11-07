struct sqrt_decomposition {
    vector <vector<int>> v;
    vector<int> maxxes;
    int k;

    void build(int k, vector<int> &a) {
        int n = a.size();
        this->k = k;
        v.resize((n + k - 1) / k);
        maxxes.resize((n + k - 1) / k, -1e9);

        for (int i = 0 ; i < a.size() ; i++) {
            v[i / k].push_back(a[i]);
            maxxes[i / k] = max(maxxes[i / k], a[i]);
        }
    }

    int get_max(int l, int r) {
        if (l / k == r / k) {
            return *max_element(v[l / k].begin() + l % k, v[l / k].begin() + r % k + 1);
        } else {
            int q;
            int ans = *max_element(v[l / k].begin() + l % k, v[l / k].end());
            if (l / k != r / k - 1) {
                q = *max_element(maxxes.begin() + l / k + 1, maxxes.begin() + r / k);
                ans = max(q, ans);
            }

            q = *max_element(v[r / k].begin(), v[r / k].begin() + r % k + 1);
            return max(q, ans);
        }
    }
};
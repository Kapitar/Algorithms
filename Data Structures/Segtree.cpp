struct Segtree {
    vector<int> tree;
    int size = 1;

    void build(int v, int l, int r, vector<int> &a) {
        if(l + 1 == r) {
            if(l < sz(a)) {
                tree[v] = a[l];
            }
            return;
        }

        int k = (l + r) / 2;
        build(v * 2 + 1, l, k, a);
        build(v * 2 + 2, k, r, a);
        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }

    Segtree(vector<int> &v) {
        while(size < sz(v)) {
            size *= 2;
        }
        tree.resize(2 * size - 1);
        build(0, 0, size, v);
    }

    int get_size() {
        return size;
    }

    int get_max(int v, int l, int r, int lq, int rq) {
        if(l >= lq && r <= rq)
            return tree[v];

        if (max(l, lq) >= min(r, rq))
            return 0;

        int k = (l + r) / 2;
        return max(get_max(2 * v + 1, l, k, lq, rq), get_max(2 * v + 2, k, r, lq, rq));
    }

    void change_element(int v, int l, int r, int i, int x) {
        if(l + 1 == r) {
            tree[v] = x;
            return;
        }
        int k = (l + r) / 2;
        if(i < k) {
            change_element(v * 2 + 1, l, k, i, x);
        } else {
            change_element(v * 2 + 2, k, r, i, x);
        }

        tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}
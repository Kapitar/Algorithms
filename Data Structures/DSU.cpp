class DSU {
public:
    vector<int> roots, sizes;

    explicit DSU(int n) {
        roots = vector<int>(n, 0);
        sizes = vector<int>(n, 1);

        iota(all(roots), 0ll);
    }

    int find_root(int a) {
        if (roots[a] == a) return a;

        return roots[a] = find_root(roots[a]);
    }

    void union_sets(int a, int b) {
        a = find_root(a);
        b = find_root(b);

        if (a == b) return;

        if (sizes[a] > sizes[b]) swap(a, b);
        sizes[a] += sizes[b];
        roots[b] = a;
    }
};
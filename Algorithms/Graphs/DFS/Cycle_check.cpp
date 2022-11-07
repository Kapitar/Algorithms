bool cycle_check(int u) {
    used_c[u] = 1;
    for (auto v : g[u]) {
        if (used_c[v] == 0) {
            if (cycle_check(v)) return true;
        } else if (used_c[v] == 1) {
            return true;
        }
    }
    used_c[u] = 2;
    return false;
}
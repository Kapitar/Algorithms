void dfs(int u) {
    used[u] = true;

    for (auto v : g[u]) {
        if (!used[v])
            dfs(v);
    }
}
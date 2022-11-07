void topsort(int u) {
    used[u] = true;

    for (auto v : g[u]) {
        if (!used[v])
            dfs(v);
    }

    top_sort.emplace_back(u + 1);
}
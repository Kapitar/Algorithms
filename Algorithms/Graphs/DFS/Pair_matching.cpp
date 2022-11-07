void dfs(int u, ld r, int color) {
    used[u] = color;

    for(int i = 0; i < n; i++) {
        if(v[i].dist(v[u]) <= r + r and !used[i])
            dfs(i, r, 3 - color);
    }
}
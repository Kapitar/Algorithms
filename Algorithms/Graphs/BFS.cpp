int main() {
    queue<int> q;
    while (q.size()) {
        v = q.front();
        q.pop();

        for (auto u : g[v]) {
            if (dist[u] > dist[v] + 1) {
                q.push({v.first, u});
                dist[u] = dist[v] + 1;
            }
        }
    }
}
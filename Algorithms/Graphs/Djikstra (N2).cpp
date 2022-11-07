int main() {
    while(true) {
        for(int i = 0; i < n; i++) {
            if(g[cur][i] != -1)
                if(dist[i] > dist[cur] + g[cur][i]) {
                    dist[i] = dist[cur] + g[cur][i];
                }
        }

        int min_vertex = -1;
        int min_dist = 1e9;
        for(int i = 0; i < n; i++) {
            if(min_dist > dist[i] and !used[i]) {
                min_dist = dist[i];
                min_vertex = i;
            }
        }

        if(min_vertex == -1) break;
        cur = min_vertex;
        used[cur] = true;
    }
}
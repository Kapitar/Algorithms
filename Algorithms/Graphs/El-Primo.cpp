int main() {
    for (int i = 0 ; i < n ; i++) {
        int v = -1;
        for (int j = 0 ; j < n ; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1)
            ans += min_e[v];

        for (int j = 0 ; j < n ; ++j) {
            if (j == v) continue;
            ld w = sqrt((cities[v].first - cities[j].first) * (cities[v].first - cities[j].first) +
                        (cities[v].second - cities[j].second) * (cities[v].second - cities[j].second));
            if (w < min_e[j]) {
                min_e[j] = w;
                sel_e[j] = v;
            }
        }
    }
}
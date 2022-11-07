int main() {
    vector<int> z(n, 0);
    z[0] = n;

    int l = 0;
    int r = 0;
    for (int i = 1 ; i < n ; i++) {
        z[i] = min(max(r - i, 0ll), z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (r < i + z[i]) {
            r = i + z[i];
            l = i;
        }
    }
}
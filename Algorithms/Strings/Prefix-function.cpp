int main() {
    vector<int> p(n);
    p[0] = 0;

    fori(i, 1, n) {
        int j = p[i - 1];

        while (j != 0 && s[i] != s[j]) {
            j = p[j - 1];
        }

        if (s[i] == s[j]) {
            p[i] = j + 1;
        }
    }
}
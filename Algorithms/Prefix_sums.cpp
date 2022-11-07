int main() {
    vector<int> pref(n + 1);
    for (int i = 1; i < n + 1; i++) {
        pref[i] += pref[i - 1] + a[i - 1];
    }

    pref[r] - pref[l - 1]
}
int main() {
    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;

        if (start > finish) {
            swap(start, finish);
        }

        v.push_back({ start, -1, 0 });
        v.push_back({ finish, 1, 0 });
    }

    sort(all(v));

    for (auto elem : v) {
        if (get<1>(elem) == -1) {
            flag++;
        }
        else if (get<1>(elem) == 1) {
            flag--;
        }
        else {
            cnt[get<2>(elem)] += flag;
        }
    }
}
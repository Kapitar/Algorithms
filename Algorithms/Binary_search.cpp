int main() {
    int l = 0, r = 1e9;
    while(l != r) {
        int mid = (l + r) / 2;

        if(f(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    int l = 0, r = 1e9;
    while(l != r) {
        int mid = (l + r + 1) / 2;

        if(f(mid)) {
            l = mid;
        } else {
            r = mid + 1;
        }
    }
}
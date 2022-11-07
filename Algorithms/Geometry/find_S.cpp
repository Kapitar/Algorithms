int main() {
    Point P1 = st[0];
    ld sq = 0;
    for(int i = 1; i < sz(st) - 1; i++) {
        sq += Point(P1, st[i]).vectorMultiply(Point(st[i], st[i + 1]));
    }
}
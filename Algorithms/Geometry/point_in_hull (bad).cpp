int main() {
    fori(i,0,n) {
        cin >> v[i];
    }

    fori(i,0,n) {
        if(abs(v[i].x - P.x) < eps and abs(v[i].y - P.y) < eps) {
            cout << "YES";
            return;
        }
    }

    ld min_x = INF;
    ld min_y = INF;

    for(auto p : v) {
        min_x = min(min_x, p.x);
        min_y = min(min_y, p.y);
    }

    Point P2(min_x - 17, min_y - 19);
    Segment l1(P, P2);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        Segment l2(v[i], v[(i + 1) % n]);
        if(l1.areSegmentsCrossed(l2)) {
            cnt++;
        }
    }

    if(cnt % 2 == 0)
        cout << "NO";
    else
        cout << "YES";
}
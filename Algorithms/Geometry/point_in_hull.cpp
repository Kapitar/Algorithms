int main() {
    if(Point(v[0], v[1]).scalarMultiply(Point(v[1], v[2])) >= 0)
        reverse(all(v));

    Point P;
    cin >> P;

    int l = 1;
    int r = n - 1;

    while(r - l > 1) {
        int mid = (l + r + 1) / 2;

        if(Line(v[0], v[mid]).isOnSameSide(P, v[l]))
            r = mid;
        else
            l = mid;
    }

    if(Line(v[l], v[r]).isOnSameSide(v[0], P) and Line(v[l], v[0]).isOnSameSide(P, v[r]) and Line(v[r], v[0]).isOnSameSide(P, v[l]))
        cout << "YES";
    else
        cout << "NO";
}
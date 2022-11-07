int main() {
    int k = 0;
    for (int i = 1 ; i < n ; i++) {
        if (v[i].x < v[k].x) {
            k = i;
        }

        if (v[i].x == v[k].x) {
            k = i;
        }
    }
    flag[k] = true;
    ans.push_back(k);

    while(true) {
        Point P = v[k];
        int q = !k;

        for(int i = 0; i < n; i++) {
            if(i != k) {
                if(abs(Point(P, v[q]).vectorMultiply(Point(P, v[i]))) < eps and P.dist(v[q]) < P.dist(v[i])) {
                    q = i;
                }
                else if(Point(P, v[q]).vectorMultiply(Point(P, v[i])) < 0)
                    q = i;
            }
        }

        if(flag[q]) {
            break;
        } else {
            k = q;
            flag[k] = true;
            ans.push_back(k);
        }
    }
}
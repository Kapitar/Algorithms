int main() {
    int k = 0;
    for (int i = 1 ; i < n ; i++) {
        if (v[i].x < v[k].x) {
            k = i;
        }

        else if (v[i].x == v[k].x and v[i].y < v[k].y) {
            k = i;
        }
    }

    swap(v[0], v[k]);

    vector<Point> st;
    st.push_back(v[0]);

    sort(v.begin() + 1, v.end(), [&](Point A, Point B) {
        if(abs(Point(v[0], A).vectorMultiply(Point(v[0], B))) < eps) return v[0].dist(A) < v[0].dist(B);
        return Point(v[0], A).vectorMultiply(Point(v[0], B)) > 0;
    });

//    for(auto elem : v) {
//        cout << elem << "    ";
//    }
//    cout << "\n";

    for(int i = 1; i < n; i++) {
        while(sz(st) > 2) {
            if(Point(st[sz(st) - 2], st.back()).vectorMultiply(Point(st.back(), v[i])) < 0) {

                st.pop_back();
            } else {
                break;
            }
        }
        st.push_back(v[i]);
    }
}
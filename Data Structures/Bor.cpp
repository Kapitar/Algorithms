const int k = 2;

struct Vertex {
    Vertex *to[k] = {nullptr, nullptr};
    int terminal = 0;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex *v = root;
    for (char c : s) {
        v->terminal++;
        if (c == '0') {
            if (!v->to[0])
                v->to[0] = new Vertex();
            v = v->to[0];
        } else {
            if (!v->to[1])
                v->to[1] = new Vertex();
            v = v->to[1];
        }
    }
    v->terminal++;
}

void erase(string &s) {
    Vertex *v = root;
    for (char c : s) {
        --v->terminal;
        if (c == '0')
            v = v->to[0];
        else
            v = v->to[1];
    }
    v->terminal--;
}

str find(string &s) {
    Vertex *v = root;
    str p;
    for (char c : s) {
        if (c == '0') {
            swap(v->to[0], v->to[1]);
        }
        if (c == '1') {
            cerr << "";
        }
        Vertex *next = (v->to[0] && v->to[0]->terminal ? v->to[0] : v->to[1]);
        char toAdd = ((v->to[0] && v->to[0]->terminal) ^ (c == '1')) + '0';
        p += toAdd;
        if (c == '0') {
            swap(v->to[0], v->to[1]);
        }
        v = next;
    }
    return p;
}
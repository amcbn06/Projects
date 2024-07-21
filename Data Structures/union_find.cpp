struct union_find {
    vector<int> parent, size;
    union_find(int __size = 0) {
        this->build(__size);
    }
    void build(int __size) {
        parent.resize(__size);
        iota(all(parent), 0);
        size.assign(__size, 1);
    }
    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        size[y] = 0;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

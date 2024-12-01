// Works with nodes in range [1, size]
struct union_find {
    vector<int> parent, rank;
    int size, components;
    union_find(int size = 0) {
        this->resize(size);
    }
    void resize(int size) {
        this->size = size;
        this->components = size;
        parent.resize(size + 1);
        for (int i = 1; i <= size; ++i) {
            parent[i] = i;
        }
        rank.assign(size + 1, 1);
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
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        parent[y] = x;
        rank[x] += rank[y];
        rank[y] = 0;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
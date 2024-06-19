struct union_find {
    vector<int> father, rank;
    int size, components = 0;
    union_find(int size = 0) {
        this->resize(size);
    }
    void resize(int size) {
        this->size = size;
        father.resize(size);
        rank.resize(size);
        for (int i = 1; i < size; ++i) {
            father[i] = i, rank[i] = 1;
        }
    }
    void clear() {
        this->size = 0;
        father.clear();
        rank.clear();
    }
    int find(int x) {
        return father[x] == x ? x : (father[x] = find(father[x]));
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        components--;
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        father[y] = x;
        rank[x] += rank[y];
        rank[y] = 0;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
} dsu(nmax + 5);

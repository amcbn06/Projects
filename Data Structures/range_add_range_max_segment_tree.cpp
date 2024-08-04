// Update type: add x on [l, r]
// Query type: maximum value on [l, r]
template<typename T>
struct segment_tree {
    int size;
    vector<T> table, lazy;
    segment_tree(int size = 0) {
        this->size = size;
        table.resize(size * 4 + 5);
        lazy.resize(size * 4 + 5);
    }
    segment_tree(T arr[], int size) {
        this->size = size;
        table.resize(size * 4 + 5);
        lazy.resize(size * 4 + 5);
        build(1, 1, size, arr);
    }
    void add(int i, T x) { add(1, 1, size, i, i, x); }
    void add(int l, int r, T x) { add(1, 1, size, l, r, x); }
    T get(int l, int r) { return get(1, 1, size, l, r); }
    T get(int i) { return get(1, 1, size, i, i); }
private:
    void build(int node, int tl, int tr, T arr[]) {
        if (tl == tr) {
            table[node] = arr[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(node << 1, tl, mid, arr);
        build(node << 1 | 1, mid + 1, tr, arr);
        table[node] = max(table[node << 1], table[node << 1 | 1]);
    }
    void propagate(int node, int l, int r) {
        if (lazy[node]) {
            table[node] += lazy[node];
            if (l != r) {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void add(int node, int tl, int tr, int l, int r, T x) {
        propagate(node, tl, tr);
        if (r < tl || tr < l) {
            return;
        }
        if (l <= tl && tr <= r) {
            lazy[node] = x;
            propagate(node, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        add(node << 1, tl, mid, l, r, x);
        add(node << 1 | 1, mid + 1, tr, l, r, x);
        table[node] = max(table[node << 1], table[node << 1 | 1]);
    }
    T get(int node, int tl, int tr, int l, int r) {
        propagate(node, tl, tr);
        if (r < tl || tr < l) {
            return numeric_limits<T>::min();
        }
        if (l <= tl && tr <= r) {
            return table[node];
        }
        int mid = (tl + tr) / 2;
        return max(get(node << 1, tl, mid, l, r),
            get(node << 1 | 1, mid + 1, tr, l, r));
    }
};

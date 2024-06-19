struct fenwick {
    vector<int> table;
    int size;
    fenwick(int size = 0) {
        this->resize(size);
    }
    void resize(int size) {
        this->size = size;
        table.assign(size, 0);
    }
    void add(int i, int x) {
        for (; i < size; i += i & -i) {
            table[i] += x;
        }
    }
    int get(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += table[i];
        }
        return sum;
    }
    int get(int i, int j) {
        return get(j) - get(i - 1);
    }
};

template<typename T>
struct fenwick {
    vector<T> table;
    int size;
    fenwick(int size = 0) {
        this->resize(size);
    }
    void resize(int size) {
        this->size = size;
        table.assign(size, 0);
    }
    void add(int i, T x) {
        for (; i < size; i += i & -i) {
            table[i] += x;
        }
    }
    T get(int i) {
        T sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += table[i];
        }
        return sum;
    }
    T get(int i, int j) {
        return get(j) - get(i - 1);
    }
};

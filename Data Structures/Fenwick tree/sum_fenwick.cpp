// Works with indicies in range [1, size]
template<typename T>
struct sum_fenwick {
    vector<T> table;
    int size;
    sum_fenwick(int size = 0) {
        this->resize(size);
    }
    void resize(int size) {
        this->size = size;
        table.assign(size + 1, 0);
    }
    // a[i] += x
    void add(int i, T x) {
        for (; i <= size; i += i & -i) {
            table[i] += x;
        }
    }
    // sum(a[1...i])
    T query(int i) {
        T sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += table[i];
        }
        return sum;
    }
    // sum(a[i...j])
    T query(int i, int j) {
        return query(j) - query(i - 1);
    }
};

using fenwick = sum_fenwick<int>; 
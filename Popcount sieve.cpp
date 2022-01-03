
struct popCountSieve {
private:
    int size;
    char* arr;
public:
    popCountSieve(int _size) {
        size = _size;
        arr = new char[size + 1];
        int iterations = 0;
        for (int p = 0; (1 << p) <= size; ++p) {
            for (int i = (1 << p); i <= size; i += (1 << (p + 1))) {
                for (int j = 0; j < (1 << p) && i + j <= size; j++) {
                    arr[i + j]++, iterations++;
                }
            }
        }
        cout << iterations;
    }
    const int operator[](int n) {
        assert(0 <= n && n <= size);
        return arr[n];
    }
};

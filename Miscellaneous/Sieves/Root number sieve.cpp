// For a number x of form p^x * q^y * ..., p, q prime numbers,
// its root number is p * q * ...
struct rootNumberSieve {
private:
    int size;
    unsigned int* arr;
public:
    rootNumberSieve(int _size) {
        size = _size;
        arr = new unsigned int[size + 1];
        for (int i = 0; i <= size; ++i) {
            arr[i] = i | (1u << 31);
        }
        for (long long i = 2; i <= size; ++i) {
            if ((arr[i] >> 31) & 1) {
                for (long long j = i * i; j <= size; j += i) {
                    arr[j] = ~(~arr[j] | (1u << 31));
                    while (arr[j] % (i * i) == 0)
                        arr[j] /= i;
                }
            }
        }
    }
    const int operator[](int n) {
        assert(0 <= n && n <= size);
        return ~(~arr[n] | (1u << 31));
    }
};

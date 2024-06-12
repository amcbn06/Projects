// M prim
template<int M>
struct Mint {
    int x;
    Mint() : x(0) { }
    Mint(int y) {
        x = y % M;
        if (x < 0) {
            x += M;
        }
    }
    Mint(long long y) {
        x = y % M;
        if (x < 0) {
            x += M;
        }
    }
    int get() const { return x; }
    bool operator==(const Mint& r) const { return x == r.x; }
    Mint& operator+=(const Mint& r) { if ((x += r.x) >= M) x -= M; return *this; }
    Mint& operator-=(const Mint& r) { if ((x += M - r.x) >= M) x -= M; return *this; }
    Mint& operator*=(const Mint& r) { x = (long long)x * r.x % M; return *this; }
    Mint& operator/=(const Mint& r) { x = (long long)x * r.inv().x % M; return *this; }
    Mint operator+(const Mint& r) const { return Mint(*this) += r; }
    Mint operator-(const Mint& r) const { return Mint(*this) -= r; }
    Mint operator*(const Mint& r) const { return Mint(*this) *= r; }
    Mint operator/(const Mint& r) const { return Mint(*this) /= r; }
    Mint pow(long long n) const {
        if (n >= M) {
            n %= M - 1;
        }
        Mint res(1), aux(x);
        for (; n; n >>= 1) {
            if (n & 1) {
                res *= aux;
            }
            aux = aux * aux;
        }
        return res;
    }
    Mint inv() const {
        return this->pow(M - 2);
    }
    friend istream& operator>>(istream& is, Mint& m) {
        return is >> m.x;
    }
    friend ostream& operator<<(ostream& os, Mint& m) {
        return os << m.x;
    }
};

typedef Mint<998244353> mint;

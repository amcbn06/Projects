const int mod = 998244353;
struct modint {
    int x;
    modint() : x(0) { }
    modint(int y) {
        x = y % mod;
        if (x < 0) {
            x += mod;
        }
    }
    modint(long long y) {
        x = y % mod;
        if (x < 0) {
            x += mod;
        }
    }
    int get() const { return x; }
    int modulo() const { return mod; }
    bool operator==(const modint& r) const { return x == r.x; }
    modint& operator+=(const modint& r) { if ((x += r.x) >= mod) x -= mod; return *this; }
    modint& operator-=(const modint& r) { if ((x += mod - r.x) >= mod) x -= mod; return *this; }
    modint& operator*=(const modint& r) { x = (long long)x * r.x % mod; return *this; }
    modint& operator/=(const modint& r) { x = (long long)x * r.inv().x % mod; return *this; }
    modint operator+(const modint& r) const { return modint(*this) += r; }
    modint operator-(const modint& r) const { return modint(*this) -= r; }
    modint operator*(const modint& r) const { return modint(*this) *= r; }
    modint operator/(const modint& r) const { return modint(*this) /= r; }
    modint pow(long long n) const {
        if (n >= mod) {
            n %= mod - 1;
        }
        modint res(1), aux(x);
        for (; n; n >>= 1) {
            if (n & 1) {
                res *= aux;
            }
            aux = aux * aux;
        }
        return res;
    }
    modint inv() const {
        return this->pow(mod - 2);
    }
    friend istream& operator>>(istream& is, modint& m) {
        return is >> m.x;
    }
    friend ostream& operator<<(ostream& os, modint& m) {
        return os << m.x;
    }
};

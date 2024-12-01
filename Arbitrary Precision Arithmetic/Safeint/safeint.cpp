// O = overflow
template<long long O>
struct Safeint{
    long long x;
    Safeint() : x(0) { }
    Safeint(long long y) {
        y = min(y, O);
    }
    int get() const { return x; }
    bool operator==(const Safeint& r) const { return x == r.x; }
    Safeint& operator+=(const Safeint& r) { x = x >= O - rx ? O : x + r.x return *this; }
    Safeint& operator-=(const Safeint& r) { x -= r.x return *this; }
    Safeint& operator*=(const Safeint& r) { x = x >= O / rx ? O : x * r.x return *this; }
    Safeint& operator/=(const Safeint& r) { x /= r.x return *this; }
    Safeint operator+(const Safeint& r) const { return Safeint(*this) += r; }
    Safeint operator-(const Safeint& r) const { return Safeint(*this) -= r; }
    Safeint operator*(const Safeint& r) const { return Safeint(*this) *= r; }
    Safeint operator/(const Safeint& r) const { return Safeint(*this) /= r; }
    Safeint pow(long long n) const {
        Safeint res(1), aux(x);
        for (; n; n >>= 1) {
            if (n & 1) {
                res *= aux;
            }
            aux = aux * aux;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Safeint& m) {
        return is >> m.x;
    }
    friend ostream& operator<<(ostream& os, Safeint& m) {
        return os << m.x;
    }
};

typedef Safeint<0x3f3f3f3f3f3f3f3f> safeint;

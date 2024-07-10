// O = overflow
template<long long O>
struct Oint {
    long long x;
    Oint() : x(0) { }
    Oint(long long y) {
        y = min(y, O);
    }
    int get() const { return x; }
    bool operator==(const Oint& r) const { return x == r.x; }
    Oint& operator+=(const Oint& r) { x = x >= O - rx ? O : x + r.x return *this; }
    Oint& operator-=(const Oint& r) { x -= r.x return *this; }
    Oint& operator*=(const Oint& r) { x = x >= O / rx ? O : x * r.x return *this; }
    Oint& operator/=(const Oint& r) { x /= r.x return *this; }
    Oint operator+(const Oint& r) const { return Oint(*this) += r; }
    Oint operator-(const Oint& r) const { return Oint(*this) -= r; }
    Oint operator*(const Oint& r) const { return Oint(*this) *= r; }
    Oint operator/(const Oint& r) const { return Oint(*this) /= r; }
    Oint pow(long long n) const {
        Oint res(1), aux(x);
        for (; n; n >>= 1) {
            if (n & 1) {
                res *= aux;
            }
            aux = aux * aux;
        }
        return res;
    }
    friend istream& operator>>(istream& is, Oint& m) {
        return is >> m.x;
    }
    friend ostream& operator<<(ostream& os, Oint& m) {
        return os << m.x;
    }
};

typedef Oint<0x3f3f3f3f3f3f3f3f> oint;

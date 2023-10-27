using ll = long long;
class BN {
private:
    vector<int> dg;
    int cmp(const BN& lhs, const BN& rhs) { if (lhs.size() != rhs.size()) { return lhs.size() > rhs.size() ? 1 : -1; } for (int i = lhs.size() - 1; i >= 0; --i) { if (lhs[i] != rhs[i]) { return lhs[i] > rhs[i] ? 1 : -1; } } return 0; }
    void trim() { while (dg.size() > 1 && dg.back() == 0) { dg.pop_back(); } }
    void a(BN& lhs, const BN& rhs) { lhs.dg.resize(max(lhs.size(), rhs.size()) + 1); ll r = 0; for (int i = 0; i < rhs.size() || r != 0; ++i) { lhs[i] += r; if (i < rhs.size()) { lhs[i] += rhs[i]; } r = lhs[i] / 10; lhs[i] %= 10; } lhs.trim(); }
    void s(BN& lhs, const BN& rhs) { ll r = 0; for (int i = 0; i < rhs.size() || r != 0; ++i) { lhs[i] -= r; if (i < rhs.size()) { lhs[i] -= rhs[i]; } r = (-lhs[i] + 9) / 10; lhs[i] += r * 10; } lhs.trim(); }
    void m(BN& lhs, const BN& rhs) { BN res; res.dg.resize(lhs.size() + rhs.size() - 1); for (int i = 0; i < lhs.size(); ++i) { for (int j = 0; j < rhs.size(); ++j) { res[i + j] += lhs[i] * rhs[j]; } } ll r = 0; for (int i = 0; i < res.size(); ++i) { r = (res[i] += r) / 10; res[i] %= 10; } while (r > 0) { res.dg.push_back(r % 10); r /= 10; } res.trim(); lhs = res; }
    void d(const BN& lhs, const BN& rhs, BN& q, BN& rm) { q.dg.resize(lhs.size()); rm = { 0 }; for (int i = lhs.size() - 1; i >= 0; --i) { rm.sl(); rm[0] += lhs[i]; q[i] = 0; while (cmp(rhs, rm) != 1) { q[i]++; s(rm, rhs); } } q.trim(); rm.trim(); }
    void sr(int power = 1) { if (*this == 0) { return; } if (power >= dg.size()) { *this = 0; return; } dg.erase(dg.begin(), dg.begin() + power); }
    void sl(int power = 1) { if (*this == 0) { return; } dg.insert(dg.begin(), power, 0); }
public:
    BN() { dg = { 0 }; }
    BN(ll nr) { while (nr > 9) { dg.push_back(nr % 10); nr /= 10; } dg.push_back(nr); }
    BN(const string& str) { dg.resize(str.size()); for (int i = 0; i < dg.size(); ++i) { dg[i] = str[str.size() - i - 1] - '0'; } }
    BN(const BN& o) { dg = o.dg; }
    BN& operator=(ll nr) { dg.clear(); while (nr > 9) { dg.push_back(nr % 10); nr /= 10; } dg.push_back(nr); return *this; }
    BN& operator=(const BN& o) { if (this == &o) { return *this; } dg = o.dg; return *this; }
    int size() const { return dg.size(); }
    int& operator[](int idx) { return dg[idx]; }
    int operator[](int idx) const { return dg[idx]; }
    bool operator==(const BN& o) { return cmp(*this, o) == 0; }
    bool operator!=(const BN& o) { return cmp(*this, o) != 0; }
    bool operator<(const BN& o) { return cmp(*this, o) < 0; }
    bool operator>(const BN& o) { return cmp(*this, o) > 0; }
    bool operator<=(const BN& o) { return cmp(*this, o) <= 0; }
    bool operator>=(const BN& o) { return cmp(*this, o) >= 0; }
    friend BN operator+(BN lhs, const BN& rhs) { return lhs += rhs; }
    friend BN operator-(BN lhs, const BN& rhs) { return lhs -= rhs; }
    friend BN operator*(BN lhs, const BN& rhs) { return lhs *= rhs; }
    friend BN operator/(BN lhs, const BN& rhs) { return lhs /= rhs; }
    friend BN operator%(BN lhs, const BN& rhs) { return lhs %= rhs; }
    BN& operator+=(const BN& rhs) { a(*this, rhs); return *this; }
    BN& operator-=(const BN& rhs) { s(*this, rhs); return *this; }
    BN& operator*=(const BN& rhs) { m(*this, rhs); return *this; }
    BN& operator/=(const BN& rhs) { BN q, rm; d(*this, rhs, q, rm); return *this = q; }
    BN& operator%=(const BN& rhs) { BN q, rm; d(*this, rhs, q, rm); return *this = rm; }
    BN& operator++() { *this += 1; return *this; }
    BN operator++(int) { BN old = *this; ++(*this); return old; }
    BN& operator--() { *this -= 1; return *this; }
    BN operator--(int) { BN old = *this; --(*this); return old; }
    ll to_llong() { ll nr = 0; for (int i = 0; i < dg.size(); ++i) { if (nr > (LLONG_MAX - dg[i]) / 10) { return -1; } nr = nr * 10 + dg[i]; } return nr; }
    friend istream& operator>>(istream& is, BN& o) { string str; cin >> str; o.dg.resize(str.size()); for (int i = 0; i < o.dg.size(); ++i) { o.dg[i] = str[str.size() - i - 1] - '0'; } return is; }
    friend ostream& operator<<(ostream& os, const BN& o) { for (int i = o.dg.size() - 1; i >= 0; --i) { os << o.dg[i]; } return os; }
    ~BN() { dg.clear(); }
};
using BigNumber = BN;

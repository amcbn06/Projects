ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1, g;
    g = extended_gcd(b, a % b, x1, y1);
    x = y1, y = x1 - y1 * (a / b);
    return g;
}

ll mod_inv(ll a, ll m) {
    ll x, y, g;
    g = extended_gcd(a, m, x, y);
    assert(g == 1);
    return (x % m + m) % m;
}

struct Congruence {
    ll a, m;
    Congruence() {
        a = m = 0;
    }
    Congruence(ll a, ll m) {
        this->a = a % m, this->m = m;
    }
    friend ostream& operator<<(ostream& os, Congruence& c) {
        return os << "Congruence(a = " << c.a << ", m = " << c.m << ")";
    }
    friend Congruence merge(Congruence lhs, Congruence rhs) {
        assert(gcd(lhs.m, rhs.m) == 1);
        Congruence res;
        res.m = lhs.m * rhs.m;
        res.a = (res.a + ((lhs.a * mod_inv(rhs.m, lhs.m) % res.m) * rhs.m) % res.m) % res.m;
        res.a = (res.a + ((rhs.a * mod_inv(lhs.m, rhs.m) % res.m) * lhs.m) % res.m) % res.m;
        return res;
    }
    friend Congruence merge(vector<Congruence> congruences) {
        Congruence result = congruences.back();
        congruences.pop_back();
        for (auto& it : congruences) {
            result = merge(result, it);
        }
        return result;
    }
};

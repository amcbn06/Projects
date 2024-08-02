ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll p = b / a;
    ll g = extended_gcd(b - p * a, a, y, x);
    x -= p * y;
    return g;
}

bool diophantine(ll a, ll b, ll c, ll& x, ll& y, ll& g) {
    if (a == 0 && b == 0) {
        if (c == 0) {
            x = y = g = 0;
            return true;
        }
        return false;
    }
    if (a == 0) {
        if (c % b == 0) {
            x = 0;
            y = c / b;
            g = abs(b);
            return true;
        }
        return false;
    }
    if (b == 0) {
        if (c % a == 0) {
            x = c / a;
            y = 0;
            g = abs(a);
            return true;
        }
        return false;
    }
    g = extended_gcd(a, b, x, y);
    if (c % g != 0) {
        return false;
    }
    ll dx = c / a;
    c -= dx * a;
    ll dy = c / b;
    c -= dy * b;
    x = dx + (ll)((__int64)x * (c / g) % b);
    y = dy + (ll)((__int64)y * (c / g) % a);
    g = abs(g);
    return true;
    // |x|, |y| <= max(|a|, |b|, |c|) [tested]
}

bool crt(ll k1, ll m1, ll k2, ll m2, ll& k, ll& m) {
    k1 %= m1;
    if (k1 < 0) k1 += m1;
    k2 %= m2;
    if (k2 < 0) k2 += m2;
    ll x, y, g;
    if (!diophantine(m1, -m2, k2 - k1, x, y, g)) {
        return false;
    }
    ll dx = m2 / g;
    ll delta = x / dx - (x % dx < 0);
    k = m1 * (x - dx * delta) + k1;
    m = m1 / g * m2;
    assert(0 <= k && k < m);
    return true;
}

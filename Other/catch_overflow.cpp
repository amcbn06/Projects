const ll overflow = 0x3f3f3f3f3f3f3f3f;
ll mult(ll a, ll b) {
    return a >= overflow / b ? overflow : a * b;
}
ll add(ll a, ll b) {
    return a >= overflow - b ? overflow : a + b;
}

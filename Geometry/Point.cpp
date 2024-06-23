struct point {
    ll x = 0, y = 0;
    int index = 0;
    point() { }
    point(ll x, ll y) { this->x = x; this->y = y; }
    double length() { return sqrt(pow(x, 2) + pow(y, 2)); }
    bool operator==(const point& other) const { return x == other.x && y == other.y; }
    bool operator!=(const point& other) const { return !(*this == other); }
    friend point operator+(const point& a, const point& b) { return point(a.x + b.x, a.y + b.y); }
    friend point operator-(const point& a, const point& b) { return point(a.x - b.x, a.y - b.y); }
    friend bool operator<(const point& a, const point& b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); }
    friend double distance(const point& a, const point& b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
    friend ll cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
    friend int orientation(const point& a, const point& b, const point& c) { ll o = cross(b - a, c - a); return (o > 0) - (o < 0); }
};

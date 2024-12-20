struct point {
    long long x = 0, y = 0;
    point() {}
    point(long long x, long long y) : x(x), y(y) {

    }
};
struct segment {
    // a * x + b * y + c
    long long a = 0, b = 0, c = 0;
    point u, v;
    segment() {}
    segment(point u, point v) : u(u), v(v) {
        a = v.y - u.y; // a = 0 => horizontal line
        b = u.x - v.x; // b = 0 => vertical line
        c = u.y * v.x - u.x * v.y;
        int g = gcd(a, gcd(b, c));
        if (a < 0 || (a == 0 && b < 0)) {
            g *= -1;
        }
        a /= g, b /= g, c /= g;
    }
};

namespace Geometry {
    const double eps = 1e-10;

    inline bool _eq(long double a, long double b) { return abs(a - b) <= eps; }
    inline bool _ls(long double a, long double b) { return b - a > eps; }
    inline bool _gt(long double a, long double b) { return a - b > eps; }
    inline bool _lse(long double a, long double b) { return _eq(a, b) || _ls(a, b); }
    inline bool _gte(long double a, long double b) { return _eq(a, b) || _gt(a, b); }
    inline long double min(long double a, long double b) { return _ls(a, b) ? a : b; }
    inline long double max(long double a, long double b) { return _ls(a, b) ? b : a; }


    struct Point {
        long double x = 0, y = 0;
        Point() {}
        Point(long double x, long double y) : x(x), y(y) {

        }
        friend istream& operator>>(istream& is, Point& pt) {
            return is >> pt.x >> pt.y;
        }
        friend ostream& operator<<(ostream& os, Point& pt) {
            return os << pt.x << " " << pt.y;
        }
    };

    // the distance from point `u` to point `v`
    long double distance(Point u, Point v) {
        return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
    }

    // area of triangle determined by three points
    long double area(Point u, Point v, Point w) {
        return abs(u.x * (v.y - w.y) + v.x * (w.y - u.y) + w.x * (u.y - v.y)) / 2;
    }

    struct Segment {
        // a * x + b * y + c
        long double a = 0, b = 0, c = 0;
        Point u, v;
        Segment() {}
        Segment(Point u, Point v) : u(u), v(v) {
            a = v.y - u.y; // a = 0 => horizontal line
            b = u.x - v.x; // b = 0 => vertical line
            c = u.y * v.x - u.x * v.y;
        }
    };

    // does the segment `s` include point `p`
    bool includes(Segment s, Point p) {
        // satisfies the line equation and is in bounds
        return _eq(s.a * p.x + s.b * p.y + s.c, 0) && _lse(min(s.u.x, s.v.x), p.x) && _lse(p.x, max(s.u.x, s.v.x)) && _lse(min(s.u.y, s.v.y), p.y) && _lse(p.y, max(s.u.y, s.v.y));
    }

    // the distance from point `p` to the segment `s`
    long double distance(Point p, Segment s) {
        assert(s.a * s.a + s.b * s.b != 0);
        Point q; // the projection of `u` onto the line of the segment
        q.x = (s.b * (s.b * p.x - s.a * p.y) - s.a * s.c) / (s.a * s.a + s.b * s.b);
        q.y = (s.a * (s.a * p.y - s.b * p.x) - s.b * s.c) / (s.a * s.a + s.b * s.b);
        if (includes(s, q)) {
            return distance(p, q);
        }
        else {
            return min(distance(p, s.u), distance(p, s.v));
        }
    }

    struct Square {
        Point corner[4]; // the four corners
        Segment side[4]; // and the four sides
        Square() {}
        Square(Point c1, Point c2) {
            corner[0] = c1;
            corner[2] = c2;
            long double foo = (c1.x + c2.x + c1.y + c2.y) / 2;
            corner[1] = Point(foo - c2.y, foo - c1.x);
            corner[3] = Point(foo - c1.y, foo - c2.x);
            for (int k = 0; k < 4; ++k) {
                side[k] = Segment(corner[k], corner[(k + 1) % 4]);
            }
        }
    };

    // area of square `sq`
    long double area(Square sq) {
        return area(sq.corner[0], sq.corner[1], sq.corner[2]) + area(sq.corner[0], sq.corner[2], sq.corner[3]);
    }

    // does the square `sq` include point `p`
    bool includes(Square sq, Point p) {
        // handle the case in which the square has area equal to zero
        if (_eq(area(sq), 0)) {
            return _eq(distance(p, sq.corner[0]), 0);
        }
        else {
            long double total = 0;
            for (int k = 0; k < 4; ++k) {
                total += area(p, sq.corner[k], sq.corner[(k + 1) % 4]);
            }
            return _eq(area(sq), total);
        }
    }

    // the minimum distance from point `p` to the sides of square `sq`
    long double distance(Point p, Square sq) {
        // handle the case in which the square has area equal to zero
        if (_eq(area(sq), 0)) {
            return distance(p, sq.corner[0]);
        }
        else {
            long double aux = 1e18;
            for (int k = 0; k < 4; ++k) {
                aux = min(aux, distance(p, sq.side[k]));
            }
            return aux;
        }
    }
}

using namespace Geometry;

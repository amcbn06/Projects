class fraction {
private:
    void normalize() {
        if (a == 0 && b == 0) {
            return; // undefined
        }
        if (a == 0) {
            b = 1;
        }
        else if (b == 0) {
            a = sgn(a);
        }
        else {
            long long g = gcd(abs(a), abs(b));
            a /= g, b /= g;
            if (b < 0) {
                a = -a, b = -b;
            }
        }
    }
public:
    long long a;
    long long b;
    fraction() {
        a = 0, b = 1;
    }
    fraction(long long a) {
        this->a = a, b = 1;
    }
    fraction(long long a, long long b) {
        this->a = a, this->b = b;
        normalize();
    }
    fraction operator-() const {
        return fraction(-a, b);
    }
    static const fraction infinity() {
        return fraction(1, 0);
    }
    bool operator==(const fraction& other) const {
        return a == other.a && b == other.b;
    }
    bool operator!=(const fraction& other) const {
        return !(*this == other);
    }
    bool operator<(const fraction& other) const {
        if (*this == infinity()) {
            return false;
        }
        if (*this == -infinity()) {
            return other != -infinity();
        }
        if (other == infinity()) {
            return true;
        }
        if (other == -infinity()) {
            return false;
        }
        return a * other.b < other.a * b;
    }
    fraction operator+(const fraction& other) const { return fraction(a * other.b + other.a * b, b * other.b); }
    fraction operator-(const fraction& other) const { return fraction(a * other.b - other.a * b, b * other.b); }
    fraction operator*(const fraction& other) const { return fraction(a * other.a, b * other.b); }
    fraction operator/(const fraction& other) const { return fraction(a * other.b, b * other.a); }
    fraction operator+(int c) const { return *this + c; }
    fraction operator-(int c) const { return *this - c; }
    fraction operator*(int c) const { return *this * c; }
    fraction operator/(int c) const { return *this / c; }
    operator double() const {
        return 1.0 * a / b;
    }
    friend string to_string(const fraction& other) {
        return to_string(double(other));
    }
    friend fraction abs(const fraction& other) {
        return fraction(abs(other.a), other.b);
    }
};

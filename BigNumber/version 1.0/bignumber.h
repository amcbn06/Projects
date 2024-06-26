class BigNumber {
private:
    vector<int> digits;
    int compare(const BigNumber& lhs, const BigNumber& rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() > rhs.size() ? 1 : -1;
        }
        for (int i = lhs.size() - 1; i >= 0; --i) {
            if (lhs[i] != rhs[i]) {
                return lhs[i] > rhs[i] ? 1 : -1;
            }
        }
        return 0;
    }
    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }
    void add(BigNumber& lhs, const BigNumber& rhs) {
        lhs.digits.resize(max(lhs.size(), rhs.size()) + 1);
        long long r = 0;
        for (int i = 0; i < rhs.size() || r != 0; ++i) {
            lhs[i] += r;
            if (i < rhs.size()) {
                lhs[i] += rhs[i];
            }
            r = lhs[i] / 10;
            lhs[i] %= 10;
        }
        lhs.trim();
    }
    void substract(BigNumber& lhs, const BigNumber& rhs) {
        long long r = 0;
        for (int i = 0; i < rhs.size() || r != 0; ++i) {
            lhs[i] -= r;
            if (i < rhs.size()) {
                lhs[i] -= rhs[i];
            }
            r = (-lhs[i] + 9) / 10;
            lhs[i] += r * 10;
        }
        lhs.trim();
    }
    void multiply(BigNumber& lhs, const BigNumber& rhs) {
        BigNumber result;
        result.digits.resize(lhs.size() + rhs.size() - 1);
        for (int i = 0; i < lhs.size(); ++i) {
            for (int j = 0; j < rhs.size(); ++j) {
                result[i + j] += lhs[i] * rhs[j];
            }
        }
        long long r = 0;
        for (int i = 0; i < result.size(); ++i) {
            r = (result[i] += r) / 10;
            result[i] %= 10;
        }
        while (r > 0) {
            result.digits.push_back(r % 10);
            r /= 10;
        }
        result.trim();
        lhs = result;
    }
    void division(const BigNumber& lhs, const BigNumber& rhs, BigNumber& quotient, BigNumber& remainder) {
        quotient.digits.resize(lhs.size());
        remainder = { 0 };
        for (int i = lhs.size() - 1; i >= 0; --i) {
            remainder.shift_left();
            remainder[0] += lhs[i];
            quotient[i] = 0;
            while (compare(rhs, remainder) != 1) {
                quotient[i]++;
                substract(remainder, rhs);
            }
        }
        quotient.trim();
        remainder.trim();
    }
    void shift_right(int power = 1) {
        if (*this == 0) {
            return;
        }
        if (power >= digits.size()) {
            *this = 0;
            return;
        }
        digits.erase(digits.begin(), digits.begin() + power);
    }
    void shift_left(int power = 1) {
        if (*this == 0) {
            return;
        }
        digits.insert(digits.begin(), power, 0);
    }
public:
    BigNumber() {
        digits = { 0 };
    }
    BigNumber(long long number) {
        while (number > 9) {
            digits.push_back(number % 10);
            number /= 10;
        }
        digits.push_back(number);
    }
    BigNumber(const string& str) {
        digits.resize(str.size());
        for (int i = 0; i < digits.size(); ++i) {
            digits[i] = str[str.size() - i - 1] - '0';
        }
    }
    BigNumber(const BigNumber& other) {
        digits = other.digits;
    }
    BigNumber& operator=(long long number) {
        digits.clear();
        while (number > 9) {
            digits.push_back(number % 10);
            number /= 10;
        }
        digits.push_back(number);
        return *this;
    }
    BigNumber& operator=(const BigNumber& other) {
        if (this == &other) {
            return *this;
        }
        digits = other.digits;
        return *this;
    }

    int size() const { return digits.size(); }
    int& operator[](int index) { return digits[index]; }
    int operator[](int index) const { return digits[index]; }


    bool operator==(const BigNumber& other) { return compare(*this, other) == 0; }
    bool operator!=(const BigNumber& other) { return compare(*this, other) != 0; }
    bool operator<(const BigNumber& other) { return compare(*this, other) < 0; }
    bool operator>(const BigNumber& other) { return compare(*this, other) > 0; }
    bool operator<=(const BigNumber& other) { return compare(*this, other) <= 0; }
    bool operator>=(const BigNumber& other) { return compare(*this, other) >= 0; }

    friend BigNumber operator+(BigNumber lhs, const BigNumber& rhs) { return lhs += rhs; }
    friend BigNumber operator-(BigNumber lhs, const BigNumber& rhs) { return lhs -= rhs; }
    friend BigNumber operator*(BigNumber lhs, const BigNumber& rhs) { return lhs *= rhs; }
    friend BigNumber operator/(BigNumber lhs, const BigNumber& rhs) { return lhs /= rhs; }
    friend BigNumber operator%(BigNumber lhs, const BigNumber& rhs) { return lhs %= rhs; }

    BigNumber& operator+=(const BigNumber& rhs) { add(*this, rhs); return *this; }
    BigNumber& operator-=(const BigNumber& rhs) { substract(*this, rhs); return *this; }
    BigNumber& operator*=(const BigNumber& rhs) { multiply(*this, rhs); return *this; }
    BigNumber& operator/=(const BigNumber& rhs) { BigNumber quotient, remainder; division(*this, rhs, quotient, remainder); return *this = quotient; }
    BigNumber& operator%=(const BigNumber& rhs) { BigNumber quotient, remainder; division(*this, rhs, quotient, remainder); return *this = remainder; }

    BigNumber& operator++() { *this += 1; return *this; }
    BigNumber operator++(int) { BigNumber old = *this; ++(*this); return old; }
    BigNumber& operator--() { *this -= 1; return *this; }
    BigNumber operator--(int) { BigNumber old = *this; --(*this); return old; }

    long long to_llong() {
        long long number = 0;
        for (int i = 0; i < digits.size(); ++i) {
            if (number > (LLONG_MAX - digits[i]) / 10) {
                return -1;
            }
            number = number * 10 + digits[i];
        }
        return number;
    }

    friend istream& operator>>(istream& is, BigNumber& other) {
        string str;
        is >> str;
        other.digits.resize(str.size());
        for (int i = 0; i < other.digits.size(); ++i) {
            other.digits[i] = str[str.size() - i - 1] - '0';
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const BigNumber& other) {
        for (int i = other.digits.size() - 1; i >= 0; --i) {
            os << other.digits[i];
        }
        return os;
    }

    ~BigNumber() {
        digits.clear();
    }
};

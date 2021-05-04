typedef unsigned long long int U64;
struct U128{
    U64 lo, hi;
    static const U64 bmax = -1;
    static const size_t sz  = 128;
    static const size_t hsz = 64;
    inline U128() : lo(0), hi(0) {}
    inline U128(unsigned long long v) : lo(v), hi(0) {}
    inline U128 operator-() const {return ~U128(*this) + 1;}
    inline U128 operator~() const {
	U128 t(*this);t.lo = ~t.lo;t.hi = ~t.hi;return t;
    }
    inline U128 &operator +=(const U128 &b) {
        if (lo > bmax - b.lo) ++hi;lo += b.lo;hi += b.hi;return *this;
    }
    inline U128 &operator -= (const U128 &b){return *this += -b;}
    inline U128 &operator *= (const U128 &b) {
        if (*this == 0 || b == 1) return *this;
        if (b == 0){lo = hi = 0;return *this;}
        U128 a(*this);U128 t = b;lo = hi = 0;
        for (size_t i = 0; i < sz; i++) {
            if((t & 1) != 0){*this += (a << i);} t >>= 1;
        }
        return *this;
    }
    inline U128 &operator /= (const U128 &b) {
	U128 rem;divide(*this, b, *this, rem);return *this;
    }
    inline U128 &operator %= (const U128 &b) {
	U128 quo;divide(*this, b, quo, *this);return *this;
    }
    inline static void divide(const U128 &num, const U128 &den, U128 &quo, U128 &rem) {
        if(den == 0) {int a = 0;quo = U128(a / a);}
        U128 n = num, d = den, x = 1, ans = 0;
        while((n >= d) && (((d >> (sz - 1)) & 1) == 0)) {
            x <<= 1;d <<= 1;
        }
        while(x != 0) {
            if(n >= d) { n -= d;ans |= x;} x >>= 1, d >>= 1;
        }
        quo = ans, rem = n;
    }
    inline U128 &operator&=(const U128 &b) {
        hi &= b.hi;lo &= b.lo;return *this;
    }
    inline U128 &operator|=(const U128 &b) {
        hi |= b.hi;lo |= b.lo;return *this;
    }
    inline U128 &operator<<=(const U128& rhs) {
	size_t n = rhs.to_int();
        if (n >= sz){lo = hi = 0;return *this;}
        if(n >= hsz){n -= hsz;hi = lo;lo = 0;}
        if(n != 0) {
            hi <<= n;const U64 mask(~(U64(-1) >> n));
            hi |= (lo & mask) >> (hsz - n);lo <<= n;
        }
        return *this;
     }
    inline U128 &operator>>=(const U128& rhs) {
        size_t n = rhs.to_int();
        if (n >= sz){lo = hi = 0;return *this;}
        if(n >= hsz){n -= hsz;lo = hi; hi = 0;}
        if(n != 0) {
            lo >>= n;const U64 mask(~(U64(-1) << n));
            lo |= (hi & mask) << (hsz - n);hi >>= n;
        }
        return *this;
    }
    inline int to_int() const { return static_cast<int> (lo); }
    inline U64 to_U64() const { return lo; }
    inline bool operator == (const U128 &b) const {
        return hi == b.hi && lo == b.lo;
    }
    inline bool operator != (const U128 &b) const {
        return !(*this == b);
    }
    inline bool operator < (const U128 &b) const {
        return (hi == b.hi) ? lo < b.lo : hi < b.hi;
    }
    inline bool operator >= (const U128 &b) const {
        return ! (*this < b);
    }
    inline U128 operator & (const U128 &b) const {
        U128 a(*this); return a &= b;
    }
    inline U128 operator << (const U128 &b) const {
        U128 a(*this); return a <<= b;
    }
    inline U128 operator >> (const U128 &b) const {
        U128 a(*this); return a >>= b;
    }
    inline U128 operator * (const U128 &b) const {
        U128 a(*this); return a *= b;
    }
    inline U128 operator + (const U128 &b) const {
        U128 a(*this); return a += b;
    }
    inline U128 operator - (const U128 &b) const {
        U128 a(*this); return a -= b;
    }
    inline U128 operator % (const U128 &b) const {
        U128 a(*this); return a %= b;
    }
    inline void print(){
        U128 x = *this;char str[128];int i, j, len = 0;
        do{str[len++]=(x % 10).lo+48;x/=10;}while (x != 0);
        reverse(str, str + len);str[len] = 0;puts(str);
    }
};
inline U128 gcd(U128 a, U128 b){
    if (b == 0) return a;return gcd(b, a % b);
}
inline U128 expo(U128 b, U128 e){
    U128 res = 1;
    while (e != 0){if ((e & 1) != 0) res *= b;e >>= 1, b *= b;}
    return res;
}
inline U128 expo(U128 x, U128 n, U128 m){
    U128 res = U128(1);
    while (n != 0){
        if ((n & 1) != 0){res *= n;res %= m;}
        x *= x;x %= m;n >>= 1;
    }
    return res % m;
}
struct Rational{
    U128 p, q;
    inline Rational(){p = 0, q = 1;}
    inline Rational(U128 P, U128 Q) : p(P), q(Q){simplify();}
    inline void simplify() {U128 g = gcd(p, q);p /= g;q /= g;}
    inline Rational operator+ (const Rational &f) const {
        return Rational(p * f.q + q * f.p, q * f.q);
    }
    inline Rational operator- (const Rational &f) const {
        return Rational(p * f.q - q * f.p, q * f.q);
    }
    inline Rational operator* (const Rational &f) const {
        return Rational(p * f.p, q * f.q);
    }
    inline Rational operator/ (const Rational &f) const {
        return Rational(p * f.q, q * f.p);
    }
};
int main(){
    U128 X = U128(9178291938173ULL);
    U128 Y = U128(123456789123456ULL);
    U128 M = U128(10000000000000000000ULL);
    for(int i = 0; i < 10000; i++)  U128 R = expo(X, Y, M);
}

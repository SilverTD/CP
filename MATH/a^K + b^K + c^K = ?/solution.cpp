#include <iostream>
#include <algorithm>
#include <math.h>
#include <array>

struct Fraction {
        int64_t numerator = 0;
        int64_t denominator = 1;
        Fraction() = default;
        Fraction(const int64_t& a) : numerator(a) {}
        Fraction(const int64_t& a, const int64_t& b) :
                numerator(a),
                denominator(b)
        {}

        Fraction& simplify() {
                int64_t GCD = std::__gcd(numerator, denominator);
                numerator /= GCD;
                denominator /= GCD;
                return *this;
        }

        Fraction simplify(Fraction&& fraction) {
                int64_t GCD = std::__gcd(fraction.numerator, fraction.denominator);
                fraction.numerator /= GCD;
                fraction.denominator /= GCD;
                return fraction;
        }

        Fraction operator-(const Fraction& other) {
                return simplify({ (numerator * other.denominator) - (denominator * other.numerator), denominator * other.denominator });
        }

        Fraction operator+(const Fraction& other) {
                return simplify({ (numerator * other.denominator) + (denominator * other.numerator), denominator * other.denominator });
        }

        Fraction operator*(const Fraction& other) {
                return simplify({ numerator * other.numerator, denominator * other.denominator });
        }

        Fraction operator/(const int& scalar) {
                return simplify({ numerator, denominator * scalar });
        }

        friend Fraction pow(Fraction fraction, const int& n) {
                fraction.numerator = std::pow(fraction.numerator, n);
                fraction.denominator = std::pow(fraction.denominator, n);
                return fraction.simplify();
        }

        friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
                if (fraction.denominator != 1) os << fraction.numerator << '/' << fraction.denominator;
                else os << fraction.numerator;
                return os;
        }
};

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);

        Fraction a, b, c;
        unsigned m;
        std::array<Fraction, 100> f, base;
        std::cin >> a.numerator >> b.numerator >> c.numerator >> m;
        f[0] = 3;
        f[1] = a;
        f[2] = b;
        f[3] = c;

        auto ab_bc_ac = (b - pow(a, 2)) / -2;
        auto abc = (c - a*(b - ab_bc_ac)) / 3;

        base[0] = 3;
        base[1] = ab_bc_ac;
        base[2] = pow(ab_bc_ac, 2) - Fraction(2)*abc*a;
        for (unsigned n = 3; n <= m; ++n) base[n] = (base[n - 1] * ab_bc_ac) - abc*(a * base[n - 2] - abc * base[n -3]);
        for (unsigned n = 4; n <= m; ++n) {
                if (n & 1) {
                        unsigned K = (n + 1)/ 2;
                        unsigned E  = n - K;

                        f[n] = f[K]*f[E] - a*base[K - 1] + abc*(base[E - 1]);
                } else {
                        unsigned K = n / 2;
                        f[n] = pow(f[K], 2) - Fraction(2)*base[K];
                }
        }

        //#define DEBUG 1
        #ifdef DEBUG
                std::cout << "ab*bc*ac = " << ab_bc_ac << '\n';
                std::cout << "abc = " << abc << '\n';
                for (unsigned n = 1; n <= m; ++n) {
                        std::cout << "a^" << n << " + b^" << n << " + c^" << n << " = " << f[n] << '\n';
                }
        #else
                std::cout << "a + b + c = " << a << '\n';
                std::cout << "a^2 + b^2 + c^2 = " << b << '\n';
                std::cout << "a^3 + b^3 + c^3 = " << c << '\n';
                std::cout << "a^" << m << " + b^" << m << " + c^" << m << " = " << f[m] << '\n';
        #endif
        return 0;
}

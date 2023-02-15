/*
        DUONG DI
        https://tinhocnqd.ucode.vn/problems/qqd-duong-di-117216

        Môt cô bé được mẹ giao nhiện vụ đi thăm bà nội, từ nhà mình đến nhà bà nội cô bé phải đi qua một khu rừng. Khu rừng đđược chia thành một lưới ô vuông n hàng, n cột. Nhà cô bé ở ô vuông đầu tiên (1, 1), nhà bà nội ở ô vuôn cuối cùng (n, n). Cô bé chỉ đi sang phải hoặc xuống dưới trong dưới ô vuông.
        Yêu cầu: Tìm số lượng đường đi khác nhau từ nhà cô bé đến nhà bà nội.
        Dữ liệu: Vào từ tệp DUONGDI.INP chỉ chứa một số nguyên n
        Kết quả: Ghi ra tệp DUONGDI.OUT là số lượng đường đi tìm được
        
        SOLVE0 (QHD) TLE TEST CUOI 14/15
        SOLVE (Su dung toan to hop) FULL TEST 15/15
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; i++)
#define EACH(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a, n) { cout << #a << " = "; FOR(_, 1, n) cout << a[_] << ' '; cout << endl; }
#define PR0(a, n) { cout << #a << " = "; REP(_, n) cout << a[_] << ' '; cout << endl; }

#define sqr(x)((x) * (x))
#define SZ(a)((int)(a.size()))

// For printing pair, container, etc.
// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
template < class U, class V > ostream & operator << (ostream & out,
        const pair < U, V > & p) {
        return out << '(' << p.first << ", " << p.second << ')';
}

template < class Con, class = decltype(begin(declval < Con > ())) >
        typename enable_if < !is_same < Con, string > ::value, ostream & > ::type
operator << (ostream & out,
        const Con & con) {
        out << '{';
        for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
                out << (it == beg ? "" : ", ") << * it;
        }
        return out << '}';
}
template < size_t i, class T > ostream & print_tuple_utils(ostream & out,
        const T & tup) {
        if constexpr(i == tuple_size < T > ::value) return out << ")";
        else return print_tuple_utils < i + 1, T > (out << (i ? ", " : "(") << get < i > (tup), tup);
}
template < class...U > ostream & operator << (ostream & out,
        const tuple < U... > & t) {
        return print_tuple_utils < 0, tuple < U... >> (out, t);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long r) {
        return uniform_int_distribution < long long > (0, r - 1)(rng);
}

template <typename T>
vector <T> read_vector(int n) {
        vector <T> res(n);
        for (int & x: res) cin >> x;
        return res;
}

void solve();

int32_t main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        solve();
        return 0;
}

string sum(string a, string b) {
        int carry = 0;
        string res;

        while (a.length() < b.length())
                a = '0' + a;
        while (b.length() < a.length())
                b = '0' + b;

        for (int i = a.length() - 1; i >= 0; --i) {
                int d = (a[i] - '0') + (b[i] - '0') + carry;
                carry = d / 10;
                res = (char)(d % 10 + '0') + res;
        }

        if (carry) res = '1' + res;
        return res;
}

string dp[1002][1002];
void solve0() {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) dp[0][i] = "1";
        for (int i = 0; i < n; ++i) dp[i][0] = "1";
        for (int i = 1; i < n; ++i) {
                for (int j = 1; j < n; ++j) {
                        dp[i][j] = sum(dp[i - 1][j], dp[i][j - 1]);
                }
        }
        cout << dp[n - 1][n - 1];
}

class BigInt {
        string digits;
        public:

                //Constructors:
                BigInt(unsigned long long n = 0);
        BigInt(string & );
        BigInt(const char * );
        BigInt(BigInt & );

        //Helper Functions:
        friend void divide_by_2(BigInt & a);
        friend bool Null(const BigInt & );
        friend int Length(const BigInt & );
        int operator[](const int) const;

        /* * * * Operator Overloading * * * */

        //Direct assignment
        BigInt & operator = (const BigInt & );

        //Post/Pre - Incrementation
        BigInt & operator++();
        BigInt & operator--();

        //Addition and Subtraction
        friend BigInt & operator += (BigInt & ,
                const BigInt & );
        friend BigInt operator + (const BigInt & ,
                const BigInt & );
        friend BigInt operator - (const BigInt & ,
                const BigInt & );
        friend BigInt & operator -= (BigInt & ,
                const BigInt & );

        //Comparison operators
        friend bool operator == (const BigInt & ,
                const BigInt & );
        friend bool operator != (const BigInt & ,
                const BigInt & );

        friend bool operator > (const BigInt & ,
                const BigInt & );
        friend bool operator >= (const BigInt & ,
                const BigInt & );
        friend bool operator < (const BigInt & ,
                const BigInt & );
        friend bool operator <= (const BigInt & ,
                const BigInt & );

        //Multiplication and Division
        friend BigInt & operator *= (BigInt & ,
                const BigInt & );
        friend BigInt operator * (const BigInt & ,
                const BigInt & );
        friend BigInt & operator /= (BigInt & ,
                const BigInt & );
        friend BigInt operator / (const BigInt & ,
                const BigInt & );

        //Modulo
        friend BigInt operator % (const BigInt & ,
                const BigInt & );
        friend BigInt & operator %= (BigInt & ,
                const BigInt & );

        //Power Function
        friend BigInt & operator ^= (BigInt & ,
                const BigInt & );
        friend BigInt operator ^ (BigInt & ,
                const BigInt & );

        //Square Root Function
        friend BigInt sqrt(BigInt & a);

        //Read and Write
        friend ostream & operator << (ostream & ,
                const BigInt & );
        friend istream & operator >> (istream & , BigInt & );

        //Others
        friend BigInt NthCatalan(int n);
        friend BigInt NthFibonacci(int n);
        friend BigInt Factorial(int n);
};

BigInt::BigInt(string & s) {
        digits = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
                if (!isdigit(s[i]))
                        throw ("ERROR");
                digits.push_back(s[i] - '0');
        }
}
BigInt::BigInt(unsigned long long nr) {
        do {
                digits.push_back(nr % 10);
                nr /= 10;
        } while (nr);
}
BigInt::BigInt(const char * s) {
        digits = "";
        for (int i = strlen(s) - 1; i >= 0; i--) {
                if (!isdigit(s[i]))
                        throw ("ERROR");
                digits.push_back(s[i] - '0');
        }
}
BigInt::BigInt(BigInt & a) {
        digits = a.digits;
}

bool Null(const BigInt & a) {
        if (a.digits.size() == 1 && a.digits[0] == 0)
                return true;
        return false;
}
int Length(const BigInt & a) {
        return a.digits.size();
}
int BigInt::operator[](const int index) const {
        if (digits.size() <= index || index < 0)
                throw ("ERROR");
        return digits[index];
}
bool operator == (const BigInt & a,
        const BigInt & b) {
        return a.digits == b.digits;
}
bool operator != (const BigInt & a,
        const BigInt & b) {
        return !(a == b);
}
bool operator < (const BigInt & a,
        const BigInt & b) {
        int n = Length(a), m = Length(b);
        if (n != m)
                return n < m;
        while (n--)
                if (a.digits[n] != b.digits[n])
                        return a.digits[n] < b.digits[n];
        return false;
}
bool operator > (const BigInt & a,
        const BigInt & b) {
        return b < a;
}
bool operator >= (const BigInt & a,
        const BigInt & b) {
        return !(a < b);
}
bool operator <= (const BigInt & a,
        const BigInt & b) {
        return !(a > b);
}

BigInt & BigInt::operator = (const BigInt & a) {
        digits = a.digits;
        return * this;
}

BigInt & BigInt::operator++() {
        int i, n = digits.size();
        for (i = 0; i < n && digits[i] == 9; i++)
                digits[i] = 0;
        if (i == n)
                digits.push_back(1);
        else
                digits[i]++;
        return * this;
}

BigInt & BigInt::operator--() {
        if (digits[0] == 0 && digits.size() == 1)
                throw ("UNDERFLOW");
        int i, n = digits.size();
        for (i = 0; digits[i] == 0 && i < n; i++)
                digits[i] = 9;
        digits[i]--;
        if (n > 1 && digits[n - 1] == 0)
                digits.pop_back();
        return * this;
}
BigInt & operator += (BigInt & a,
        const BigInt & b) {
        int t = 0, s, i;
        int n = Length(a), m = Length(b);
        if (m > n)
                a.digits.append(m - n, 0);
        n = Length(a);
        for (i = 0; i < n; i++) {
                if (i < m)
                        s = (a.digits[i] + b.digits[i]) + t;
                else
                        s = a.digits[i] + t;
                t = s / 10;
                a.digits[i] = (s % 10);
        }
        if (t)
                a.digits.push_back(t);
        return a;
}
BigInt operator + (const BigInt & a,
        const BigInt & b) {
        BigInt temp;
        temp = a;
        temp += b;
        return temp;
}

BigInt & operator -= (BigInt & a,
        const BigInt & b) {
        if (a < b)
                throw ("UNDERFLOW");
        int n = Length(a), m = Length(b);
        int i, t = 0, s;
        for (i = 0; i < n; i++) {
                if (i < m)
                        s = a.digits[i] - b.digits[i] + t;
                else
                        s = a.digits[i] + t;
                if (s < 0)
                        s += 10,
                        t = -1;
                else
                        t = 0;
                a.digits[i] = s;
        }
        while (n > 1 && a.digits[n - 1] == 0)
                a.digits.pop_back(),
                n--;
        return a;
}
BigInt operator - (const BigInt & a,
        const BigInt & b) {
        BigInt temp;
        temp = a;
        temp -= b;
        return temp;
}

BigInt & operator *= (BigInt & a,
        const BigInt & b) {
        if (Null(a) || Null(b)) {
                a = BigInt();
                return a;
        }
        int n = a.digits.size(), m = b.digits.size();
        vector < int > v(n + m, 0);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                        v[i + j] += (a.digits[i]) * (b.digits[j]);
                }
        n += m;
        a.digits.resize(v.size());
        for (int s, i = 0, t = 0; i < n; i++) {
                s = t + v[i];
                v[i] = s % 10;
                t = s / 10;
                a.digits[i] = v[i];
        }
        for (int i = n - 1; i >= 1 && !v[i]; i--)
                a.digits.pop_back();
        return a;
}
BigInt operator * (const BigInt & a,
        const BigInt & b) {
        BigInt temp;
        temp = a;
        temp *= b;
        return temp;
}

BigInt & operator /= (BigInt & a,
        const BigInt & b) {
        if (Null(b))
                throw ("Arithmetic Error: Division By 0");
        if (a < b) {
                a = BigInt();
                return a;
        }
        if (a == b) {
                a = BigInt(1);
                return a;
        }
        int i, lgcat = 0, cc;
        int n = Length(a), m = Length(b);
        vector < int > cat(n, 0);
        BigInt t;
        for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
                t *= 10;
                t += a.digits[i];
        }
        for (; i >= 0; i--) {
                t = t * 10 + a.digits[i];
                for (cc = 9; cc * b > t; cc--);
                t -= cc * b;
                cat[lgcat++] = cc;
        }
        a.digits.resize(cat.size());
        for (i = 0; i < lgcat; i++)
                a.digits[i] = cat[lgcat - i - 1];
        a.digits.resize(lgcat);
        return a;
}
BigInt operator / (const BigInt & a,
        const BigInt & b) {
        BigInt temp;
        temp = a;
        temp /= b;
        return temp;
}

BigInt & operator %= (BigInt & a,
        const BigInt & b) {
        if (Null(b))
                throw ("Arithmetic Error: Division By 0");
        if (a < b) {
                return a;
        }
        if (a == b) {
                a = BigInt();
                return a;
        }
        int i, lgcat = 0, cc;
        int n = Length(a), m = Length(b);
        vector < int > cat(n, 0);
        BigInt t;
        for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
                t *= 10;
                t += a.digits[i];
        }
        for (; i >= 0; i--) {
                t = t * 10 + a.digits[i];
                for (cc = 9; cc * b > t; cc--);
                t -= cc * b;
                cat[lgcat++] = cc;
        }
        a = t;
        return a;
}
BigInt operator % (const BigInt & a,
        const BigInt & b) {
        BigInt temp;
        temp = a;
        temp %= b;
        return temp;
}

BigInt & operator ^= (BigInt & a,
        const BigInt & b) {
        BigInt Exponent, Base(a);
        Exponent = b;
        a = 1;
        while (!Null(Exponent)) {
                if (Exponent[0] & 1)
                        a *= Base;
                Base *= Base;
                divide_by_2(Exponent);
        }
        return a;
}
BigInt operator ^ (BigInt & a, BigInt & b) {
        BigInt temp(a);
        temp ^= b;
        return temp;
}

void divide_by_2(BigInt & a) {
        int add = 0;
        for (int i = a.digits.size() - 1; i >= 0; i--) {
                int digit = (a.digits[i] >> 1) + add;
                add = ((a.digits[i] & 1) * 5);
                a.digits[i] = digit;
        }
        while (a.digits.size() > 1 && !a.digits.back())
                a.digits.pop_back();
}

BigInt sqrt(BigInt & a) {
        BigInt left(1), right(a), v(1), mid, prod;
        divide_by_2(right);
        while (left <= right) {
                mid += left;
                mid += right;
                divide_by_2(mid);
                prod = (mid * mid);
                if (prod <= a) {
                        v = mid;
                        ++mid;
                        left = mid;
                } else {
                        --mid;
                        right = mid;
                }
                mid = BigInt();
        }
        return v;
}

BigInt NthCatalan(int n) {
        BigInt a(1), b;
        for (int i = 2; i <= n; i++)
                a *= i;
        b = a;
        for (int i = n + 1; i <= 2 * n; i++)
                b *= i;
        a *= a;
        a *= (n + 1);
        b /= a;
        return b;
}

BigInt NthFibonacci(int n) {
        BigInt a(1), b(1), c;
        if (!n)
                return c;
        n--;
        while (n--) {
                c = a + b;
                b = a;
                a = c;
        }
        return b;
}

BigInt Factorial(int n) {
        BigInt f(1);
        for (int i = 2; i <= n; i++)
                f *= i;
        return f;
}

istream & operator >> (istream & in, BigInt & a) {
        string s;
        in >> s;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
                if (!isdigit(s[i]))
                        throw ("INVALID NUMBER");
                a.digits[n - i - 1] = s[i];
        }
        return in;
}

ostream & operator << (ostream & out,
        const BigInt & a) {
        for (int i = a.digits.size() - 1; i >= 0; i--)
                cout << (short) a.digits[i];
        return cout;
}

void solve() {
        int n;
        cin >> n;

        BigInt res(1);
        for (int i = n; i < (2 * n - 1); ++i) {
                res *= BigInt(i);
                res /= BigInt(i - n + 1);
        }
        cout << res;
}

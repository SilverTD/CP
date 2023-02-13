/*
        DUONG DI
        https://tinhocnqd.ucode.vn/problems/qqd-duong-di-117216

        Môt cô bé được mẹ giao nhiện vụ đi thăm bà nội, từ nhà mình đến nhà bà nội cô bé phải đi qua một khu rừng. Khu rừng đđược chia thành một lưới ô vuông n hàng, n cột. Nhà cô bé ở ô vuông đầu tiên (1, 1), nhà bà nội ở ô vuôn cuối cùng (n, n). Cô bé chỉ đi sang phải hoặc xuống dưới trong dưới ô vuông.
        Yêu cầu: Tìm số lượng đường đi khác nhau từ nhà cô bé đến nhà bà nội.
        Dữ liệu: Vào từ tệp DUONGDI.INP chỉ chứa một số nguyên n
        Kết quả: Ghi ra tệp DUONGDI.OUT là số lượng đường đi tìm được
        
        SU DUNG QUY HOACH DONG VA BIGNUM
        TLE TEST CUOI 14/15
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))

// For printing pair, container, etc.
// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {
        return out << '(' << p.first << ", " << p.second << ')';
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator << (ostream& out, const Con& con) {
        out << '{';
        for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
        out << (it == beg ? "" : ", ") << *it;
        }
        return out << '}';
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
        if constexpr(i == tuple_size<T>::value) return out << ")"; 
        else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> ostream& operator << (ostream& out, const tuple<U...>& t) {
        return print_tuple_utils<0, tuple<U...>>(out, t);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long r) {
        return uniform_int_distribution<long long> (0, r-1)(rng);
}

template<typename T>
vector<T> read_vector(int n) {
        vector<T> res(n);
        for (int& x : res) cin >> x;
        return res;
}

void solve();

int32_t main() {
        ios::sync_with_stdio(0); cin.tie(0);
        solve();
        return 0;
}

class BigInt {
        private:
                string value;
        public:
                BigInt() {
                        value = "0";
                }

                BigInt(const int& num) {
                        value = std::to_string(std::abs(num));
                }

                BigInt& operator=(const BigInt& a) {
                        value = a.value;
                        return *this;
                }

                BigInt& operator=(const int& a) {
                        BigInt temp(a);
                        value = temp.value;
                        return *this;
                }

                BigInt operator+(const BigInt& num) const {
                        string str1 = value, str2 = num.value;
                        if (str1.length() > str2.length())
                                swap(str1, str2);
                        string str = "";
 
                        int n1 = str1.length(), n2 = str2.length();
 
                        reverse(str1.begin(), str1.end());
                        reverse(str2.begin(), str2.end());
 
                        int carry = 0;
                        for (int i = 0; i < n1; i++) {
                                int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
                                str.push_back(sum % 10 + '0');
                                carry = sum / 10;
                        }

                        for (int i = n1; i < n2; i++) {
                                int sum = ((str2[i] - '0') + carry);
                                str.push_back(sum % 10 + '0');
                                carry = sum / 10;
                        }
 
                        if (carry) str.push_back(carry + '0');
 
                        reverse(str.begin(), str.end());

                        BigInt temp;
                        temp.value = str;
                        return temp;
                }

                friend ostream& operator<<(std::ostream& out, const BigInt& num) {
                        out << num.value;
                        return out;
                }
};

BigInt dp[1002][1002];
void solve() {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) dp[0][i] = 1;
        for (int i = 0; i < n; ++i) dp[i][0] = 1;
        for (int i = 1; i < n; ++i) {
                for (int j = 1; j < n; ++j) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
        }
        cout << dp[n - 1][n - 1];
}

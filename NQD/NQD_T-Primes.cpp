/*
        Số T - Prime

        Bạn Nam rất yêu thích toán học, đặc biệt là thích tìm hiểu về số học. Một ngày nọ, trong lúc giải một bài toán số học, bạn Nam phát hiện ra trong các số mà mình tìm được có rất nhiều số có đặc điểm là chúng có đúng ba ước số nguyên dương khác nhau, và bạn Nam gọi những số này là số T-Prime.
        Yêu cầu: Hãy lập trình giúp bạn Nam đếm xem có bao nhiêu số T-Prime (tức là số có đúng ba ước số nguyên dương khác nhau) có giá trị không vượt quá số nguyên n cho trước.
        Dữ liệu vào: Cho từ tệp văn bản TPRIME.INP gồm một dòng ghi số nguyên dương n.
        Kết quả: Ghi ra tệp văn bản TPRIME.OUT gồm một dòng ghi một số nguyên là số lượng số T-Prime đếm được.
        Ví dụ:
        INPUT: 6
        OUTPUT: 1

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

constexpr int N = 1000001;
int is_prime[N];
constexpr void sieve() {
        for (int i = 0; i < N; ++i) is_prime[i] = 1;
        is_prime[0] = 0;
        is_prime[1] = 0;
        int i = 2;
        while (i * i <= N) {
                if (is_prime[i] == 0) {
                        ++i;
                        continue;
                }

                int j = 2 * i;
                while (j < N) {
                        is_prime[j] = 0;
                        j += i;
                }
                ++i;
        }
}

void solve() {
        int n, c = 0;
        cin >> n;

        sieve();

        for (int i = 2; i * i <= n; ++i) {
                if (is_prime[i] && i * i > 1)
                        ++c;
        }
        cout << c;
}

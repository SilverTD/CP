/*
        Cho dãy số A gồm n phần tử nguyên dương A1, A2,..., An. Mỗi phần tử có giá trị không vượt quá 1e9 và 1 <= n <= 500. Một bộ ba số được gọi là bộ số tam giác, nếu ba số này tạo thành ba cạnh của một tam giác nào đó.

        Yêu cầu: Hãy đếm xem trong dãy A có bao nhiêu bộ số tam giác (Ai, Aj, Ak) với i, j, k đôi một khác nhau.

        Input
        Dòng đầu là số n.
        Dòng tiếp theo là các phần tử của dãy A, mỗi phần tử cách nhau một dấu cách.
        Output
        Ghi ra số lượng bộ số tam giác.
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define uint unsigned long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))

// Bitmask
#define SET_BIT(mask, bit) (mask |= 1 << bit)
#define CLEAR_BIT(mask, bit) (mask &= ~(1 << bit))
#define TEST_BIT(mask, bit) ((mask & (1 << bit)) != 0)

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

template<typename T = int>
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

int a[100001], c = 0;
void solve() {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        for (int i = 0; i < n - 2; ++i) {
                for (int j = i + 1; j < n - 1; ++j) {
                        int temp = (lower_bound(a + j + 1, a + n, a[i] + a[j]) - a) - 1;
                        c += temp - j;
                }
        }
        cout << c;
}

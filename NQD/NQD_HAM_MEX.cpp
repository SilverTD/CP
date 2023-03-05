/*
        https://tinhocnqd.ucode.vn/problems/102-ham-mex-bang-b-tin-hoc-tre-2021-93840
        102. Hàm Mex - Bảng B - Tin học Trẻ 2021
        Trong lý thuyết trò chơi hàm mex đóng vai trò quan trọng. Hàm mex được định nghĩa như sau: Cho tập số nguyên dương A. mex(A) là số nguyên dương nhỏ nhất không có trong tập A. Ví dụ, với A = {2,1,3,5,100}, mex(A) = 4, với A = {2,3,4,5}, mex(A) = 1.
        Bé Sen rất thích thú với vai trò và ứng dụng của hàm mex. Sẵn có trong tay dãy số nguyên dương A = (a1, a2, . . ., an), trong đó các số khác nhau từng đôi một, bé Sen quyết định thực hiện k lần phép bổ sung mex vào dãy số, mỗi lần đưa thêm vào A số mex tìm được và làm tăng số lượng phần tử của dãy lên 1.

        Yêu cầu: Hãy xác định giá trị của phần tử cuối cùng được bổ sung vào dãy.

        Dữ liệu vào:

        Dòng đầu tiên chứa hai số nguyên n và k (1 ≤ n ≤ 10^5, 1 ≤ k ≤ 10^9),
        Dòng thứ 2 chứa n số nguyên khác nhau đôi một a1, a2, . . ., an (1 ≤ ai ≤ 10^5, i = 1.. n).
        Kết quả: Đưa ra một số nguyên – giá trị số cuối cùng được bổ sung vào dãy.
        VD:
                INPUT: 
                5 1
                3 5 2 6 8
                OUPUT:
                1
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

bool a[1000000] = { false };
void solve() {
        int n, k, l, max_i = -1;
        cin >> n >> k;

        for (int i = 0; i < n; ++i) {
                int x; cin >> x;
                a[x] = true;
                max_i = max(x, max_i);
        }

        for (int i = 1; i <= max_i; ++i) {
                if (k == 0) break;
                if (!a[i]) {
                        l = i;
                        --k;
                }
        }

        if (k > 0) l = max_i + k;
        cout << l;
}

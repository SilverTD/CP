/*
        Đoạn con có tổng bằng 0

        ĐOẠN CON CÓ TỔNG BẰNG 0
        Cho một dãy số nguyên A gồn có n phần tử: a1, a2, ..., an. Một đoạn con liên tiếp của dãy A có điểm đầu L, điểm cuối R với L ≤ R là tập hợp tất cả các phần tử ai với L≤ i ≤R.
        Yêu cầu: Đếm số lượng đoạn con có tổng các phần tử bằng 0.
        Dữ liệu vào: Cho trong tệp văn bản SUMSEQ.INP gồm:

        Dòng thứ nhất chứa số nguyên n (0 < n ≤ 106)
        Dòng thứ hai chứa n số nguyên a1, a2, ..., an ( |ai| ≤ 109; i=1..n).
        Giữa các số ghi trên một dòng cách nhau một khoảng trống.
        Kết quả: Ghi vào tệp văn bản SUMSEQ.OUT chỉ có một dòng chứa số nguyên là số lượng đoạn con có tổng bằng không.
        
        VD:
        INPUT:
                5
                2 1 -1 -2 0
        OUTPUT:
                4
                
        Dễ chứng minh

        s[i] = a[1] + a[2] + ... + a[i]
        Từ đó ta có:

        s[i] = a[1] + a[2] + ... + a[i]
        s[j] = a[1] + a[2] + ... + a[i] + a[i+1] + ... + a[j]
        => s[j] - s[i] = a[i+1] + ... + a[j]
        Nếu s[j] - s[i] = 0 <=> a[i+1] + ... + a[j] = 0 , độ dài doạn [i+1,j] = j-(i+1)+1 = j - i
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

void solve() {
        int n, c = 0;
        cin >> n;
        vector<int> a(n);

        unordered_map<int, int> b;

        b[0] = 1;
        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                prefixSum += a[i];

                if (b.count(prefixSum)) {
                        c += b[prefixSum];
                        b[prefixSum] += 1;
                } else {
                        b[prefixSum] = 1;
                }
        }
        cout << c;
}

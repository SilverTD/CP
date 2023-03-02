/*
        Q2 Đoạn đường đẹp nhất
        Bài 5: (HSG 2019) ĐOẠN ĐƯỜNG ĐẸP NHẤT
        Trong thời gian vừa qua, người dân ở thành phố XYZ đã vui mừng chào đón sự xuất hiện của con đường ven biển, con đường được đầu tư rất nhiều kinh phí làm đường và xây dựng các tòa nhà đẹp nằm ở cùng một phía của con đường, con đường này được coi là con đường có cảnh quang đẹp nhất hành tinh. Con đường có n tòa nhà, được đánh thứ tự từ 1 đến n, tính từ đầu đường, tòa nhà thứ i có độ cao là hi ( i = 1..n). Theo các chuyên gia kiến trúc và thẩm mĩ, đoạn đường đẹp nhất là đoạn đường mà ở đó có độ cao trung bình của các tòa nhà đúng bằng k.
        Yêu cầu: Em hãy tìm đoạn đường có các tòa nhà liên tiếp nhau nhiều nhất sao cho đoạn đường này là đoạn đường đẹp nhất (độ cao trung bình của các tòa nhà đúng bằng k).
        Dữ liệu vào: Cho từ tệp văn bản DDUONG.INP gồm:
        • Dòng thứ nhất ghi hai số nguyên n và k (1 ≤ n ≤ 105; 0 ≤ k ≤ 109).
        • Dòng thứ hai ghi n số nguyên h1, h2, …, hn (0 < hi ≤ 109; i = 1..n).
        Các số trên cùng một dòng ghi cách nhau ít nhất một khoảng trống.
        Kết quả: Ghi vào tệp văn bản DDUONG.OUT gồm:
        • Dòng thứ nhất ghi một số nguyên u là chỉ số bắt đầu của toà nhà thuộc đoạn đường đẹp nhất tìm được, nếu có nhiều đáp án thì ghi chỉ số u nhỏ nhất.
        • Dòng thứ hai ghi một số nguyên v là số lượng toà nhà thuộc đoạn đường tìm được.
        Nếu không có đoạn đường nào đẹp nhất thì ghi ra duy nhất số 0.
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
        int n, k;
        cin >> n >> k;
        vector<int> prefix_sum(n + 1, 0);
        unordered_map<int, int> furthest;

        int start = n + 2, max_length = 0;
        for (int i = 1; i <= n; ++i) {
                int x;
                cin >> x;
                prefix_sum[i] = prefix_sum[i - 1] + (x - k);
                furthest[prefix_sum[i]] = i;
        }

        for (int i = 1; i <= n; ++i) {
                if (prefix_sum[i] == 0) {
                        start = 1;
                        max_length = i;
                }
                else if (furthest_index.count(prefix_sum[i])) {
                        int j = furthest_index[prefix_sum[i]];
                        if (j > i) {
                                if (j - i > max_length || (start == 1 && j - i > max_length)) {
                                        start = i + 1;
                                        max_length = j - i;
                                }
                                else if (j - i == max_length) {
                                        start = min(start, i + 1);
                                }
                        }
                }
        }
        if (max_length > 0)
                cout << start << '\n' <<  max_length << '\n';
        else
                cout << 0;
}

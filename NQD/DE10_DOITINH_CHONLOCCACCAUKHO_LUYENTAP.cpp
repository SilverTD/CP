/*
        Luyện tập
        https://tinhocnqd.ucode.vn/contests/de-10-doi-tinh-chon-loc-cac-cau-kho-de-dt-32512?u=49792&l=32512&q=122181&lg=54
        Để tăng cường kỹ năng lập trình cũng như rèn luyện tư duy thuật toán nhằm chuẩn bị cho kỳ thi Olympic Tin học sắp tới, bạn An quyết định tham gia trang Web làm bài tập trực tuyến trên mạng. Trang Web luyện tập lập trình này mỗi ngày đều tổ chức một kỳ thi và sẽ chấm điểm trực tuyến ngay sau khi kết thúc thời gian làm bài. Vì tiêu chí chấm điểm dựa vào nhiều yếu tố nên điểm số bài thi có thể là một số âm.
        Hiện tại, bạn An đã tham gia luyện tập được n ngày, mỗi ngày bạn An đều nghiêm túc làm bài với kết quả ngày thứ i bạn An đạt được số điểm là ai. Theo kinh nghiệm của các anh chị khóa trước, muốn đạt giải trong kỳ thi Olympic Tin học thì mỗi ngày đều phải tham gia kỳ thi trực tuyến sao cho tổng điểm đạt được tối thiểu là k, ngoài ra nếu đạt tổng số điểm tối thiểu là k trong số ngày liên tiếp càng ít thì khả năng đạt giải càng cao.
        Yêu cầu: Hãy tìm số ngày liên tiếp ít nhất (có thể một ngày) trong số n ngày mà bạn An đã tham gia kỳ thi trực tuyến sao cho tổng số điểm đạt được trong những ngày này tối thiểu là k.
        Dữ liệu vào: Cho từ tệp văn bản LUYENTAP.INP có dạng :

        Dòng thứ nhất ghi hai số nguyên n, k (1 ≤ n ≤ 50000, 0 < k ≤ 109)
        Dòng thứ hai ghi n số nguyên a1, a2, …, an (-106 ≤ ai ≤ 106, i = 1..n).
        Các số trên cùng một dòng ghi cách nhau một dấu cách.
        Kết quả: Ghi ra tệp văn bản LUYENTAP.OUT gồm một dòng ghi duy nhất một số nguyên là số ngày liên tiếp ít nhất mà tổng số điểm đạt được tối thiểu là k. Nếu không có số ngày liên tiếp nào đạt tổng điểm tối thiểu là k thì ghi ra số -1
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

void solve0() {
        int n, k, s = 0;
        cin >> n >> k;
        vector<int> a(n + 1), f(n + 1);
        f[0] = 0;
        int left = 1, right = -1;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                f[i] = f[i - 1] + a[i];
                if (f[i] >= k && right == -1)
                        right = i;
        }
        int sum = f[right];
        int max_left = 0;
        while (left < right) {
                sum -= a[left];
                if (sum >= k) max_left = max(max_left, left);
                ++left;
        }
        cout << right - max_left;
}

void solve1() {
        int n, k, s = 0;
        cin >> n >> k;
        vector<int> a(n + 1), f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
                f[i] = f[i - 1] + a[i];
        }

        int _min = n;
        for (int i = n; i > 0; --i) {
                for (int j = i; j > 0; --j) {
                        if (f[i] - f[j] >= k)
                                _min = min(_min, i - j);
                }
        }

        cout << _min;
}

void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        deque<int> d;
        int res = n + 1;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
                if (i > 0) a[i] += a[i - 1];
                if (a[i] >= k) res = min(res, i + 1);

                while (d.size() > 0 && a[i] - a[d.front()] >= k)
                        res = min(res, i - d.front()), d.pop_front();
                while (d.size() > 0 && a[i] <= a[d.back()])
                        d.pop_back();
                d.push_back(i);

        }
        cout << (res <= n ? res : -1);
}

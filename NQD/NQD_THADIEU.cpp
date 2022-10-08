#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

int main() {
        ios_base::sync_with_stdio(false);

        cin.tie(NULL);
        cout.tie(NULL);

        freopen("THADIEU.INP", "r", stdin);
        freopen("THADIEU.OUT", "w", stdout);

        unsigned n;
        cin >> n;
        vector<pair<unsigned, unsigned>> a(n + 1);

        for (int i = 1; i <= n; ++i) {
                cin >> a[i].first;
                a[i].second = i;
        }

        for (int i = 1; i <= n; ++i) {
                for (int j = i; j >= 1; --j) {
                        if (a[i].first > a[j].first)
                                --a[i].second;
                }
        }

        for (int i = 1; i <= n; ++i) {
                cout << a[i].second << '\n';
        }

        return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
        ios_base::sync_with_stdio(false);

        cin.tie(NULL);
        cout.tie(NULL);

        freopen("SIGNA.INP", "r", stdin);
        freopen("SIGNA.OUT", "r", stdout);

        unsigned L, R, S = 0;
        cin >> L >> R;

        auto sum = [](unsigned n) -> unsigned {
                unsigned s = 0;
                while (n != 0) {
                        s += (n % 10);
                        n /= 10;
                }

                return s;
        };

        for (unsigned i = L; i <= R; ++i) {
                unsigned n = sum(i);
                bool isPrime = (n > 1) ? true : false;

                for (unsigned j = 2; j <= (n >> 1); ++j) {
                        if (n % j == 0) {
                                isPrime = false;
                                break;
                        }
                }
                if (isPrime) ++S;
        }
        cout << S << '\n';

        return 0;
}

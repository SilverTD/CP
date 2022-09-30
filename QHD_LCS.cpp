#include <iostream>
#include <string>

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);

        std::string a, b;
        std::cin >> a >> b;

        unsigned n = a.size(), m = b.size();
        unsigned dp[n + 1][m + 1];

        for (unsigned i = 0; i <= n; ++i) {
                for (unsigned j = 0; j <= m; ++j) {
                        if (i == 0 || j == 0) {
                                dp[i][j] = 0;
                                continue;
                        }
                        if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                        else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
        }

        std::cout << dp[n][m] << '\n';

        return 0;
}

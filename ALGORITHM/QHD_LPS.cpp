#include <iostream>
#include <string>
#include <string.h>

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);

        std::string s;
        std::cin >> s;
        unsigned n = s.size(), q = 1;
        bool dp[n + 1][n + 1];
        memset(dp, false, sizeof(dp));
        for (unsigned i = 1; i <= n; ++i) dp[i][i] = true;
        for (unsigned len = 2; len <= n; ++len) {
                for (unsigned i = 1; i <= n - len + 1; ++i) {
                        unsigned j = i + len - 1;
                        if (len == 2 && s[i] == s[j]) dp[i][j] = true;
                        else dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                        if (dp[i][j]) q = std::max(q, len);
                }
        }

        std::cout << q << '\n';

        return 0;
}

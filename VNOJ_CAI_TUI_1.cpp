#include <iostream>
#include <utility>
#include <vector>
#include <string.h>

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);

        uint64_t n, m;
        std::cin >> n >> m;
        uint64_t dp[n + 1][m + 1];
        std::vector<std::pair<uint64_t, uint64_t>> a(n);
        for (auto& [w, v] : a) std::cin >> w >> v;

        memset(dp, 0, sizeof(dp));
        for (uint64_t i = 1; i <= n; ++i) {
                for (uint64_t j = 1; j <= m; ++j) {
                        auto [w, v] = a[i - 1];
                        dp[i][j] = dp[i - 1][j];
                        if (w <= j) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - w] + v); 
                }
        }

        std::cout << dp[n][m] << '\n';

        return 0;
}

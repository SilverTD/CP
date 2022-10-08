#include <iostream>
#include <cmath>
#include <cstdio>

int main() {
        std::ios_base::sync_with_stdio(false);

        std::cin.tie(NULL);
        std::cout.tie(NULL);

        freopen("FROG.INP", "r", stdin);
        freopen("FROG.OUT", "w", stdout);

        unsigned n;
        std::cin >> n;

        unsigned dp[n + 1], h[n + 1];
        for (unsigned i = 0; i < n; ++i) std::cin >> h[i];

        dp[0] = 0;
        dp[1] = abs(h[1] - h[0]);

        for (unsigned i = 2; i < n; ++i)
                dp[i] = std::min(
                                dp[i - 1] + abs(h[i] - h[i - 1]),
                                dp[i - 2] + abs(h[i] - h[i - 2])
                       );

        std::cout << dp[n - 1] << '\n';

        return 0;
}

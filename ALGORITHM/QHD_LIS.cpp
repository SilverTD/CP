#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

int main() {
        std::ios_base::sync_with_stdio(false);

        std::cin.tie(NULL);
        std::cout.tie(NULL);

        freopen("LIS.INP", "r", stdin);
        freopen("LIS.OUT", "w", stdout);

        unsigned n;
        std::cin >> n;
        unsigned a[n], dp[n];
        std::fill_n(dp, n, 1);
        for (unsigned i = 0; i < n; ++i) std::cin >> a[i];
        for (unsigned i = 0; i < n; ++i)
                for (unsigned j = 0; j < i; ++j)
                        if (a[i] > a[j]) 
                                dp[i] = std::max(dp[i], dp[j] + 1);
        std::cout << *std::max_element(dp, dp + n) << '\n';
        return 0;
}

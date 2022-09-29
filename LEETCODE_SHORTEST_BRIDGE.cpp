#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

constexpr double PI_2 = (3.14159 / 2);

class Solution {
        private:
                std::vector<std::vector<int>> grid;
        public:
                unsigned shortestBridge(const std::vector<std::vector<int>>& __grid) {
                        grid = std::move(__grid);

                        auto [r, c] = find_first_land();
                        mark_island_as_2(r, c);

                        const unsigned N = grid.size();
                        std::vector<std::pair<int, int>> island_1_lands;
                        for (unsigned r = 0; r < N; ++r) {
                                for (unsigned c = 0; c < N; ++c) {
                                        if (grid[r][c] == 1)
                                                island_1_lands.push_back(std::make_pair<int, int>(r, c));
                                }
                        }

                        unsigned dist = 0;
                        while (!island_1_lands.empty()) {
                                std::vector<std::pair<int, int>> new_island_1_lands;
                                for (auto [r, c] : island_1_lands) {
                                        for (unsigned i = 0; i < 4; ++i) {
                                                int x = r + std::round(-1 * std::cos(PI_2 * i));
                                                int y = c + std::round(-1 * std::sin(PI_2 * i));

                                                if (x < 0 || x >= N || y < 0 || y >= N)
                                                        continue;

                                                if (grid[x][y] == 0) {
                                                        grid[x][y] = -dist-1;
                                                        new_island_1_lands.push_back(std::make_pair<int, int>(x, y));
                                                }
                                                else if (grid[x][y] == 2) {
                                                        return dist;
                                                }
                                        }
                                }
                                ++dist;
                                island_1_lands = std::move(new_island_1_lands);
                        }
                        return dist;
                }

                std::pair<int, int> find_first_land() {
                        for (unsigned r = 0; r < grid.size(); ++r) {
                                for (unsigned c = 0; c < grid[0].size(); ++c) {
                                        if (grid[r][c] == 1)
                                                return std::make_pair<int, int>(r, c);
                                }
                        }
                        return {};
                }

                void mark_island_as_2(const int& r, const int& c) {
                        grid[r][c] = 2;
                        for (unsigned i = 0; i < 4; ++i) {
                                int x = r + std::round(-1 * std::cos(PI_2 * i));
                                int y = c + std::round(-1 * std::sin(PI_2 * i));

                                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[r][c] == 1)
                                        mark_island_as_2(x, y);
                        }
                }
};

int main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        Solution solution;
        std::cout << solution.shortestBridge({{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}) << '\n';
        return 0;
}

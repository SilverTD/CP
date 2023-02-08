/*
        De 5: Doi tinh 2022-2023
        Bai 2: Chia deu
        https://tinhocnqd.ucode.vn/contests/de-5-doi-tinh-2022-2023-32341?u=49792&l=32341&q=121929&lg=54

        - Trên trục tọa độ ox, cho n điểm p1, p2,..pn đôi một khác nhau,
        đoạn thẳng AB được gọi là chia đều nếu xác định 3 điểm cho trước A, B, M sao cho M là trung điểm của AB.
        
        - Yêu cầu: Cho trước n và tọa độ các điểm p1, p2,..., pn. Hỏi có bao nhiêu đoạn thẳng chia đều từ các điểm đã cho.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int32_t main() {
        int n, count = 0;
        std::cin >> n;
        std::vector<in32_t> b(n);
        std::unordered_map<int32_t, int> a;
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        std::sort(b.begin(), b.end(), [](const int32_t& a, const int32_t& b) { return a > b; });
        for (int i = 0; i < n; ++i) a.insert({ b[i], 1 });
        for (int i = 0; i < n; ++i)
                for (int j = i + 1, v = (b[i] + b[j]); j < n; ++j, v = (b[i] + b[j]))
                        if (!(v & 1) && a.count(v >> 1))
                                ++count;
        std::cout << count;
        return 0;
}

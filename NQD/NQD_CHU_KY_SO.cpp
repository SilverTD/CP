/*
        https://tinhocnqd.ucode.vn/problems/97-chu-ki-so-hsgnqd-k102020-82862
        
        CHỮ KÍ SỐ
        Chữ ký số cá nhân là một loại chữ ký điện tử, có giá trị tương đương với chữ ký tay của mỗi cá nhân. Chữ ký số cá nhân được dùng với mục đích xác thực danh tính của người ký trong các trường hợp giao dịch điện tử. Chữ kí số được số hóa (mã hóa) với thuật toán cơ bản là dự trên số nguyên có tổng các chữ số là số nguyên tố.
        Yêu cầu: Cho trước hai số nguyên L, R. Hãy đếm xem trong đoạn L, R có bao nhiêu số nguyên có tổng các chữ số là số nguyên tố (kể cả số nguyên L, R).
        Dữ liệu: Cho từ tệp văn bản SIGNA.INP chỉ một dòng ghi hai số nguyên L và R (1 ≤ L < R ≤ 10^5).
        Kết quả: Ghi vào tệp văn bản SIGNA.OUT chỉ có một dòng ghi số nguyên theo yêu cầu.
        
        Input: 7 20
        Output: 6
        
        Using Digit-DP
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define int long long

constexpr int N = 100001;
int dp[10][2][10 * 9 + 1];
int is_prime[N];

constexpr void sieve() {
        for (int i = 0; i < N; ++i) is_prime[i] = 1;
        is_prime[0] = 0;
        is_prime[1] = 0;
        int i = 2;
        while (i * i <= N) {
                if (is_prime[i] == 0) {
                        ++i;
                        continue;
                }

                int j = 2 * i;
                while (j < N) {
                        is_prime[j] = 0;
                        j += i;
                }
                ++i;
        }
}

int f(int index, int flag, int sum, std::vector<int> a) {
        if (index == a.size()) {
                if (is_prime[sum]) return 1;
                return 0;
        }
        if (dp[index][flag][sum] != -1)
                return dp[index][flag][sum];

        int limit = (flag == 0) ? a[index] : 9;
        int count = 0;

        for (int i = 0; i <= limit; ++i)
                count += f(index + 1, (flag == 0 && i == a[index]) ? 0 : 1, sum + i, a);

        return dp[index][flag][sum] = count;
}

int get(const int n) {
        std::vector<int> a;
        while (n > 0) {
                a.push_back(n % 10);
                n /= 10;
        }
        std::reverse(a.begin(), a.end());
        memset(dp, -1, sizeof dp);
        return f(0, 0, 0, a);
}

int32_t main() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        sieve();

        int l, r;
        std::cin >> l >> r;
        std::cout << get(r) - get(l - 1);
        return 0;
}

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")

#include <iostream>
#include <bitset>
#include <utility>
#include <ciso646>

template<typename T> constexpr std::size_t get_max_bits() { return sizeof(T) * 8; }
template<typename T, std::size_t MAX_BITS = get_max_bits<T>()>
[[nodiscard]] std::pair<T, std::bitset<MAX_BITS>> reverse_bit(const T& n) {
        T reverse_num = 0;

        for (unsigned i = 0; i < MAX_BITS; ++i)
                if ((n bitand (1 << i)))
                        reverse_num or_eq 1 << ((MAX_BITS - 1) - i);

        return { reverse_num, std::bitset<MAX_BITS>(reverse_num) };
}

int main() {
        short n = 522;
        auto [number, bits] = reverse_bit<short>(n);
        std::cout << n << "\t" << std::bitset<get_max_bits<short>()>(n) << '\n';
        std::cout << number << "\t" << bits << '\n';
        return 0;
}

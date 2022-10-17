#include <iostream>
#include <iterator>
#include <algorithm>

template<class T>
uint32_t lcs(T iter1, T iter2, uint32_t len1, uint32_t len2) {
    uint32_t *arr1 = reinterpret_cast<uint32_t *>(alloca(sizeof(uint32_t) * (len2 + 1)));
    uint32_t *arr2 = reinterpret_cast<uint32_t *>(alloca(sizeof(uint32_t) * (len2 + 1)));

    arr1[0] = 0;
    arr2[0] = 0;
    for (uint32_t j = 0; j <= len2; j++) {
        arr1[j] = 0;
    }

    T iter2_ = iter2;
    for (uint32_t i = 1; i <= len1; i++) {
        iter2 = iter2_;
        for (uint32_t j = 1; j <= len2; j++) {
            if (*iter1 == *iter2) {
                arr2[j] = 1 + arr1[j - 1];
            }
            else {
                arr2[j] = std::max({arr1[j], arr2[j - 1]});
            }
            ++iter2;
        }
        ++iter1;
        memcpy(arr1, arr2, sizeof(uint32_t) * (len2 + 1));
    }
    return arr2[len2];
}

int main() {
    std::string str1 = "classical", str2 = "musical";
    std::cout << lcs(str1.cbegin(), str2.cbegin(), str1.length(), str2.length()) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

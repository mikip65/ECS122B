#ifndef ZALGO_H
#define ZALGO_H
#include <iostream>
#include <string>
#include <vector>
class Zalgo {
public:
    Zalgo(const std::string& str) : s(str) {
        std::cerr << "The original std::string is \"" << s << "\", with length of " << s.length() << std::endl;
        Z.resize(s.length());
        int l = 0;
        int r = 0;
        for (int i = 1; i < s.length(); ++i) {
            std::cerr << "Now perform Z[" << i + 1 << "]" << std::endl;
            if (r < i) {
                std::cerr << "The r of current Z-box is " << r + 1 << " , smaller than current index, calculate new Z-box" << std::endl;
                l = i;
                Z[i] = cmp(i);
                r = l + Z[i] - 1;
                std::cerr << "The new l is " << l + 1 << ", and the new r is " << r + 1 << std::endl;
            } else {
                std::cerr << "The r is "<< r + 1 << ", bigger than the current index, k is " << i - l + 1 << ", and Z[k] is " << Z[i - l];
                if (Z[i - l] < r - i + 1) {
                    std::cerr << ", smaller than r - i + 1, which is " << r - i + 2 << ", use Z[k] for current Z value." << std::endl;
                    Z[i] = Z[i - l];
                } else {
                       std::cerr << ", bigger than or equal to r - i + 1, which is " << r - i + 2 << ", calculate new Z-box" << std::endl;
                       l = i;
                       r += cmp(r + 1, r - i + 1);
                       Z[i] = r - l + 1;
                       std::cerr << "The new l is " << l + 1 << ", and the new r is " << r + 1 << std::endl;
                    }
            }
            std::cerr << "Z[" << i + 1 << "] is " << Z[i] << std::endl;
        }
    }
    const std::vector<int>& getZ() const {
        return Z;
    }
private:
    std::string s;
    int cmp(int current, int begin = 0) const {
        int res = 0;
        while (current < s.length() && s[current] == s[begin]) {
            ++res;
            ++current;
            ++begin;
        }
        return res;
    }
    std::vector<int> Z;
};

void patternMatching(const std::string& pattern, const std::string& text) {
    std::string S = pattern + "$" + text;
    Zalgo Z(S);
    for (int i = pattern.length() + 1; i < S.length(); ++i) {
        if (Z.getZ()[i] == pattern.length()) {
            std::cout << "Pattern found at index " << i - pattern.length() << std::endl;
        }
    }
}
#endif

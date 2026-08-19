#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        std::string num = std::to_string(x);
        int n = num.length();
        for (size_t i = 0; i < n/2; i++){
            if (num[i] != num[n - i - 1])
                return false;
        }
        return true;
    }
};
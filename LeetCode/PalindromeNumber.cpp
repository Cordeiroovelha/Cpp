#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        std::string num = std::to_string(x);
        for(size_t i{0}; i < num.length()/2; ++i){
            if(num[i] != num[num.length() - i - 1])
                return false;
        }
        return true;
    }
};
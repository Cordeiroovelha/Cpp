#include <string>
using std::string;
class Solution {
public:
    bool isPalindrome(string s) {
        int Left = 0, Right = s.size() - 1;

        while (Left < Right) {
            while (Left < Right && !isalnum(s[Left])) {
                Left++;
            }
            while (Left < Right && !isalnum(s[Right])) {
                Right--;
            }
            if (Left < Right && tolower(s[Left]) != tolower(s[Right])) {
                return false;
            }
            Left++;
            Right--;
        }
        return true;
    }
};
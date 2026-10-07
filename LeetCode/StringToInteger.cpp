#include <string>
#include <iostream>
using std::string;
class Solution {
public:
    int myAtoi(string s) {
        int ans{std::stoi(s)};
        return ans;
    }
};
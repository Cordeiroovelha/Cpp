#include <string>
#include <unordered_map>
class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> d = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int R{0};
        int i{0};

        while (i < s.size()){
            if (i < s.size() && d[s[i]] < d[s[i + 1]]){
                R += d[s[i + 1]] - d[s[i]];
                i += 2;
            }
            else {
                R += d[s[i]];
                i++;
            }
        }
        return R;
    }
};
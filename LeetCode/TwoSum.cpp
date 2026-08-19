#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& num, int target) {
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                if (num[i] + num[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
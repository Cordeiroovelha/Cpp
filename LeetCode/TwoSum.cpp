#include <vector>

class Solution {
public:
    std::vector<int> twoSumBrutalForce(std::vector<int>& num, int target) {
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                if (num[i] + num[j] == target)
                    return {i, j};
            }
        }
        return {};
    }

    // caso o array ja esteja ordenado!!
    // é mais rapido fazer a busca da soma utilizando dois ponteiros
    // Time = O(n)  Space = O(1)
    std::vector<int> twoSumSorted(std::vector<int>& num, int target){
        int L{0};
        int R = num.size() - 1;

        while (L < R){
            int sum = num[L] + num[R];
            if (sum == target)
                return {L + 1, R + 1};
            else if (sum < target)
                L++;
            else
                R--;
        }

        throw std::invalid_argument("No Two Sum solution, or Out of order");

    }
};
#include <vector>
#include <cmath>
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        // transpose
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                std::swap(matrix[i][j], matrix[j][i]);
        }
        
        // reflection
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n / 2; j++)
                std::swap(matrix[i][j], matrix[i][n - j - 1]);
        }
    }
};
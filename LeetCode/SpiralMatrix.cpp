// solução muito feia, mas funciona
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int m = matrix.size(); int n = matrix[0].size();
        int up{0}, right{1}, down{2}, left{3}, direction{right};
        int upWall{0}, rightWall{n}, downWall{m}, leftWall{-1};
        int i{0}, j{0};

        while(ans.size() != m*n){
            if (direction == right){
                while(j < rightWall){
                    ans.push_back(matrix[i][j]);
                    j++;
                }
                i++;
                j--;
                rightWall--;
                direction = down;
            }else if (direction == down) {
                while (i < downWall) {
                    ans.push_back(matrix[i][j]);
                    i++;
                }
                i--;
                j--;
                downWall--;
                direction = left;
            }else if (direction == left) {
                while (j > leftWall) {
                    ans.push_back(matrix[i][j]);
                    j--;
                }
                i--;
                j++;
                leftWall++;
                direction = up;
            } else {
                while (i > upWall) {
                    ans.push_back(matrix[i][j]);
                    i--;
                }
                i++;
                j++;
                upWall++;
                direction = right;
            }
        }

        return ans;
    }
};
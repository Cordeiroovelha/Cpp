#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea{0};
        int n = height.size();
        int left{0}, right{n - 1}; 

        while (left < right){
            int wide = right - left;
            int heigh = min(height[left], height[right]);
            int area = wide * heigh;
            maxArea = max(maxArea, area);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
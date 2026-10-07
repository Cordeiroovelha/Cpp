#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(std::min(numRows, int(s.length())));
        int i{0};
        bool Down{false};

        for(char c : s){
            rows[i] += c;
            if(i == 0 || i == numRows - 1)
                Down = !Down;
            i += Down ? 1 : -1;
        }

        string result;
        for (const string& row: rows)
            result += row;
        

        return result;
    }
};
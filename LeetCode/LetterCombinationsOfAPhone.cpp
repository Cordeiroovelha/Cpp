#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        unordered_map<char, string> letterMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        string path;
        backtrack(digits, 0, path, letterMap, ans);
        return ans;
    }
private:
    void backtrack(const string& digits, int index, string& path,
                   const unordered_map<char, string>& letterMap, vector<string>& ans){    
        if(index == digits.size()){
            ans.push_back(path);
            return;
        }

        const string& letters = letterMap.at(digits[index]);
        for(char letter : letters){
            path.push_back(letter);
            backtrack(digits, index+1, path, letterMap, ans);
            path.pop_back();
        }
    }
};
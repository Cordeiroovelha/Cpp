#include <string>
#include <stack>
#include <unordered_map>
class Solution {
public:
    bool verify(std::string n){
        std::unordered_map<char, char> hashmap = {{')', '('}, {'}', '{'}, {']', '['}};
	    std::stack<char> stk;
        

        for(char c : n){
            if (hashmap.find(c) == hashmap.end())
                stk.push(c);
            else {
                if (stk.empty() || stk.top() != hashmap[c])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
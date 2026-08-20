#include <string>
#include <stack>
#include <unordered_map>
class Solution {
public:
    bool verify(std::string n){
        // mapa de todas as combinaçoes de parenteses
        std::unordered_map<char, char> hashmap = {{')', '('}, {'}', '{'}, {']', '['}};
	    std::stack<char> stk;
        

        for(char c : n){ // percorre a string
            if (hashmap.find(c) == hashmap.end())
                stk.push(c);
            else {
                // se a stack estiver vazia ou
                // o topo for diferente do valor no mapa, já retorna false
                if (stk.empty() || stk.top() != hashmap[c])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
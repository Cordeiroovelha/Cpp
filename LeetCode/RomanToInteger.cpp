#include <string>
#include <unordered_map>
class Solution {
public:
    int romanToInt(std::string s) {
        // mapa de conversão
        std::unordered_map<char, int> d = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                           {'C', 100}, {'D', 500}, {'M', 1000}};        
        int R{0}; // armazena resultado
        int i{0}; // percorre a string

        while (i < s.size()){
            // se valor convertido for menor que o valor seguinte
            if (i < s.size() && d[s[i]] < d[s[i + 1]]){
                R += d[s[i + 1]] - d[s[i]]; // subtrai o valor do numero seguinte e add no R
                i += 2; // pula 2 na string
            }
            else {
                R += d[s[i]]; // só adiciona
                i++;
            }
        }
        return R;
    }
};
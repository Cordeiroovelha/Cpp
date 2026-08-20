#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if(strs.empty()) return ""; // retorna caso strs == null

        int minLength = INT_MAX;

        // acha o tamanho min de todas palavras para não dar overbound
        for(const std::string& s : strs) 
            minLength = std::min(minLength, (int)s.length());

        int i = 0;
        while(i < minLength){ // percore todas palavras comparando as letra com a da primeira palavra
            for (const std::string& s : strs) {
                if (s[i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};
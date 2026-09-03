#include <string>
#include <vector>

// Por que não std::unordered_map: 
// O algoritmo precisa percorrer os valores do MAIOR para o MENOR (1000 -> 1).
// O std::vector mantém a ordem de inserção definida pelo programador, permitindo
// o loop reverso. Já o std::unordered_map não garante NENHUMA ordem específica

class Solution {
public:
    std::string intToRoman(int num) {
        // Inclui os casos especiais (4, 9, 40, 90, 400, 900) para evitar
        // repetições desnecessárias e garantir a forma canônica.
        std::vector<std::pair<std::string, int>> symList = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
                                                  {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
                                                  {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
                                                  {"M", 1000}};
        std::string res = "";

        // Percorre a lista do maior valor (M = 1000) para o menor (I = 1).
        for (int i = symList.size() - 1; i >= 0; i--){

            std::string sym = symList[i].first;
            int val = symList[i].second;

            // Quantas vezes o valor atual cabe no número que ainda não foi convertido
            int count = num / val;

            if(count > 0){
                // Adiciona o primeiro caractere do símbolo repetido 'count' vezes.
                res.append(count, sym[0]);
                
                // Se o símbolo tem dois caracteres (casos especiais), adiciona o
                // segundo caractere uma vez.
                if (sym.size() == 2)
                    res.append(1, sym[1]);
                // Atualiza o número com o resto da divisão
                num %= val;
            }
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int altura, largura;
    cout << "Altura e largura: ";
    cin >> altura >> largura;

    // Inicializa o campo com pontos (vazio)
    vector<vector<char>> campo(altura, vector<char>(largura, '.'));

    // Lê as 5 posições das plantas
    vector<int> posicoes(5);
    cout << "Localizacao das plantas (5 valores): ";
    for (int i = 0; i < 5; ++i) {
        cin >> posicoes[i];
    }

    int total = altura * largura;

    // Passo 1: Colocar as plantas ('T')
    for (int p : posicoes) {
        if (p >= 1 && p <= total) {
            int linha = (p - 1) / largura;
            int coluna = (p - 1) % largura;
            campo[linha][coluna] = 'T';
        }
        // Posições inválidas são ignoradas
    }

    // Passo 2: Colocar armadilhas ('#') ao redor de cada planta
    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int l = 0; l < altura; ++l) {
        for (int c = 0; c < largura; ++c) {
            if (campo[l][c] == 'T') {
                for (int d = 0; d < 4; ++d) {
                    int nl = l + dl[d];
                    int nc = c + dc[d];
                    if (nl >= 0 && nl < altura && nc >= 0 && nc < largura) {
                        // Não substitui outra planta por armadilha
                        if (campo[nl][nc] != 'T') {
                            campo[nl][nc] = '#';
                        }
                    }
                }
            }
        }
    }

    // Passo 3: Exibir o campo usando setw(6) para alinhar
    for (int l = 0; l < altura; ++l) {
        for (int c = 0; c < largura; ++c) {
            cout << setw(6) << campo[l][c];
        }
        cout << endl;
    }

    return 0;
}

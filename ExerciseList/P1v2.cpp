#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(void){
    int altura{0}, largura{0}, total{0}, linha{0}, coluna{0};

    // vetores de deslocamento ou delta arrays
    // servem para organizar cordenadas em celulas vizinhas (cima, baixo, esquerda e direita)
    // dl = linha (cima, baixo)  ||  dc = coluna (direita, esquerda)
    // ex: tomate = 3  || dl[0] + dc[+1] = esquerda
    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    cout << "Altura e Largura: ";
    cin >> altura >> largura;
    total = altura * largura;

    // o mapa sera armazenado e montado nesse vector
    vector<vector<char>> campo(altura, vector<char>(largura, '.'));

    vector<int> tomates(5);
    cout << "Posicione dos tomates: ";
    for (int i = 0; i < 5; i++) {
        cin >> tomates[i];
    }
    
    // insere os tomates no mapa
    for(int i : tomates){
        if (i >= 1 && i <= total){
            linha = (i - 1) / largura;
            coluna = (i - 1) % largura;
            campo[linha][coluna] = 'T';
        }
    }

    // insere as armadilhas
    for (int l = 0; l < altura; l++) {
        for (int c = 0; c < largura; c++) {
           if(campo[l][c] == 'T'){
            // percorre as posiçoes visinhas aos tomates
            for(int indice = 0; indice < 4; indice++){
                int newLine = l + dl[indice];
                int newCol =  c + dc[indice];
                // verifica se a posição é valida
                if(newLine >= 0 && newLine < altura &&
                   newCol >= 0 && newCol < largura){
                   if (campo[newLine][newCol] != 'T') campo[newLine][newCol] = '#';
                }
            }
           } 
        }
    }
    

    //saida
    for (int l = 0; l < altura; ++l) {
        for (int c = 0; c < largura; ++c) {
            cout << setw(6) << campo[l][c];
        }
        cout << endl << endl;
    }

    return 0;
}
// programa que calcula media de n numeros
// Autoria de murilo Juttel
// escrito em c++

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Media{
    vector<float> array;
    size_t indice;
    size_t frequencia;
    float media;
    float variancia;
    float DesvioPadrao;
};

void Pausa(void){
    cout << "Aperte <enter> para continuar";
    cin.get();
    cin.ignore(80, '\n');
    cout << endl;
}

void MediaSimples(size_t indice, vector<float>& array){
    cout << "=== Media Simples ===" << endl;
    for (size_t i = 0; i < indice; i++){
        cout << "Entre o " << i+1 << "o valor: ";
        cin >> array[i];
        cin.ignore(80, '\n');
    }
}

void MediaComposta(size_t indice, vector<float>& array) {
    
    cout << "=== Media Composta ===" << endl;
    for (size_t i = 0; i < indice; i++){
        cout << "Entre o " << i+1 << "o valor: ";
        cin >> array[i];
        cin.ignore(80, '\n');
        
        cout << "Entre a frequencia para o valor " << array[i] << ": ";

        size_t freq;
        cin >> freq;
        cin.ignore(80, '\n');
        
        // Para media composta, armazenamos valor * frequencia
        array[i] = array[i] * freq;
    }
}


// Subrotina para cálculo da variância amostral
float VarianciaAmostral(const vector<float>& array, float media) {
    size_t n = array.size();
    
    if (n <= 1) {
        return 0.0;
    }
    
    float SomaQuadrados = 0.0;
    
    // Calcula a soma dos quadrados das diferenças
    for (size_t i = 0; i < n; i++) {
        float diferenca = array[i] - media;
        SomaQuadrados += pow(diferenca, 2);
    }
    
    return SomaQuadrados / (n - 1);
}

int main(void){
    char   resp;
    int16_t tipo;
    Media  Dados;

    cout << setprecision(2) << fixed << right;

    do {
        cout << "Quantos numeros na cadeia? ";
        cin >> Dados.indice;
        cin.ignore(80, '\n');
        
        if (Dados.indice == 0) {
            cout << "A cadeia deve ter pelo menos 1 numero!" << endl;
            continue;
        }
        
        Dados.array.resize(Dados.indice);
        cout << endl;

        cout << "Cadeia Simple[1] ou Composta[2]? ";
        cin >> tipo;
        cin.ignore(80, '\n');

        if (tipo == 1)
            MediaSimples(Dados.indice, Dados.array);
        else if (tipo == 2)
            MediaComposta(Dados.indice, Dados.array);
        else{
            cout << "Tipo de conta nao existente" << endl;
            Pausa();
        }

        // calculo da soma e media
        float soma = 0;
        for (size_t i = 0; i < Dados.indice; i++){
            soma = soma + Dados.array[i];
        }

        Dados.media = soma/Dados.indice;

        // Ordenação do array
        vector<float> valoresOrdenados = Dados.array;
        sort(valoresOrdenados.begin(), valoresOrdenados.end());

        // calculo de mediana
        float mediana = 0;
        if (Dados.indice % 2 == 0){
            int32_t meio1 = Dados.indice / 2 - 1;
            int32_t meio2 = Dados.indice / 2;
            mediana = (valoresOrdenados[meio1] + valoresOrdenados[meio2]) / 2;
        }
        else
            mediana = valoresOrdenados[Dados.indice / 2];

        Dados.variancia = VarianciaAmostral(Dados.array, Dados.media);
        Dados.DesvioPadrao = sqrt(Dados.variancia);
        
        cout << endl;
        cout << "Soma ...............: " << setw(6) << soma << endl;
        cout << "Media ..............: " << setw(6) << Dados.media << endl;
        cout << "Mediana ............: " << setw(6) << mediana << endl;
        cout << "Variancia Amostral .: " << setw(6) << Dados.variancia << endl;
        cout << "Desvio Padrao ......: " << setw(6) << Dados.DesvioPadrao << endl;
        cout << string(80, '-') << endl;
        cout << "Deseja continuar? [S/N] ";
        cin.get(resp);
        cin.ignore(80, '\n');

    } while(toupper(resp) == 'S');
    

    cout << endl;
    cout << "Aperte <enter> para terminar";
    cin.get();
    return 0;
}

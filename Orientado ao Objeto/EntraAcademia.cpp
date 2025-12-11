// programa que faz a entrada em uma academia
// autoria de Murilo Juttel Cordeiro
// escrito em c++

#include <iostream>
#include <string>
using namespace std;

class Pessoa{
    protected:
        string Nome;
        int32_t Idade;
    
    public:
    Pessoa() : Nome(""), Idade(0) {}

    void Entrada(const string &N, int32_t I){
        Nome = N;
        Idade = I;
    }

    void Exibir(void){
        cout << "Nome ..............: " << Nome << endl;
        cout << "Idade .............: " << Idade << endl;
    }

    ~Pessoa() {}
};

class Aluno : public Pessoa{
    private:
        string Modalidade;
    
    public:
        Aluno() : Pessoa(), Modalidade("") {}

        void Entrada(const string &N, int32_t I, const string &M){
            Pessoa::Entrada(N, I);
            Modalidade = M;
        }

        void Exibir(void){
            Pessoa::Exibir();
            cout << "Modalidade ...: " << Modalidade << endl;
        }

        ~Aluno() {}
};

int main(void){
    Aluno aluno;
    string Nome, Modalidade;
    int32_t Idade;
    char Resposta;

    do{
        cout << "===Cadastro Aluno Academia===" << endl;

        cout << "\nNome: ";
        getline(cin, Nome);
        cout << "Idade: ";
        cin >> Idade;
        cin.ignore(80, '\n');
        cout << "Modalidade: ";
        getline(cin, Modalidade);

        aluno.Entrada(Nome, Idade, Modalidade);

        cout << endl;
        cout << "===Dados Cadastrados===" << endl;
        cout << endl;

        aluno.Exibir();

        cout << "\nDeseja Continuar (s/n)? ";
        cin.get(Resposta);
    }while(toupper(Resposta) != 'N');

    cout << "Aperte <enter> para continuar";
    cin.get();
    return 0;    
}

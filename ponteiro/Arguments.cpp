#include <iostream>
using std::cout;

int main(int argc, char* argv[]){
    cout << "Number of arguments: " << argc << "\n\n";

    for (int i = 0; i < argc; i++)
        cout << "Argument " << i << " : " << argv[i] << '\n';
    
    std::cin.get();
    return 0;
}
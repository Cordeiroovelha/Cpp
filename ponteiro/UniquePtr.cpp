#include <print>
#include <memory>

using namespace std;

class Aux {
public:
    Aux(){
        std::println("{}", __func__);
    }

    ~Aux(){
        std::println("{}", __func__);
    }
};


int main(int argc, char ** argv)
{
    try {
        auto aux = std::make_unique<Aux>();

        auto aux2 = std::move(aux);
        std::unique_ptr<Aux> aux3;
        aux3 = std::move(aux2);
        
        if(argc < 3)
            return -1;

    } catch (...) {
    }

    return 0;
}

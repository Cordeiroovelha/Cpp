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
        auto aux = std::make_shared<Aux>();
        std::println("use_count: {}", aux.use_count());
        {
            auto aux2 = aux;
            std::println("use_count: {}", aux.use_count());
            {
                std::shared_ptr<Aux> aux3;
                aux3 = aux2;
                std::println("use_count: {}", aux.use_count());
            }
            std::println("use_count end: {}", aux.use_count());
        }
        std::println("use_count end: {}", aux.use_count());

    } catch (...) {
    }

    return 0;
}

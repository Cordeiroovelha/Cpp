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

        if(argc < 3)
            return -1;

    } catch (...) {
    }

    return 0;
}

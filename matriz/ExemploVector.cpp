// usos da biblioteca vector

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }

    vec.resize(10);

    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }

    std::cout << std::boolalpha;
    std::cout << vec.empty() << std::endl;

    vec.clear();

    std::cout << vec.empty() << std::endl;

    return 0;
}

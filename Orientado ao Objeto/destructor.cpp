// exemplo de destructor

#include <print>

using namespace std;

class Test{
public:
    Test() : m_id(++CURRENT_ID){
        std::println("Test({})", m_id);
    }

    ~Test() {
        std::println("~Test({})", m_id);
    }
private:
    int m_id{0};
    inline static int CURRENT_ID = 0;
};


int main()
{
    // stack = //heap
    Test *t = new Test[4];
    delete[] t; // [] apenas para mais de 1 obj
    println("End Main");

    return 0;
}

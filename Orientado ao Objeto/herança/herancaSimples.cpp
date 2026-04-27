#include <string>
#include <print>

using namespace std;

class Employee {
public:
    int id() const
    {
        return m_id;
    }

    void setId(int newId)
    {
        m_id = newId;
    }

    std::string name() const
    {
        return m_name;
    }

    void setName(const std::string &newName)
    {
        m_name = newName;
    }

private:
    int m_id{0};
    std::string m_name;
};

class Dev : public Employee {
public:
    void coding() const {
        std::println("Now Coding...");
    }
};


int main()
{
    Dev d;
    d.setId(1);
    std::println("id: {}", d.id());
    d.coding();
    return 0;
}

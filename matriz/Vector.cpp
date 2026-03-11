#include <print>
#include <chrono>
#include<vector>

using namespace std::chrono;

template<typename T>
class Vector {
public:
    Vector() = default;

    // O(n)
    Vector(const Vector &other){
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];

        for(std::size_t i = 0; i < m_size; ++i){
            m_data[i] = other.m_data[i];
        }
    }

    // O(1)
    Vector(Vector &&other){
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }

    ~Vector() {
        delete []m_data;
    }

    // O(n)
    Vector& operator=(const Vector &other){
        if (this != &other) {
            clear();
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];

            for(std::size_t i = 0; i < m_size; ++i){
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    // O(1)
    Vector& operator=(Vector &&other){
        if (this != &other) {
            clear();
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = other.m_data;

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_data = nullptr;
        }
        return *this;
    }

    constexpr void clear(){
        delete []m_data;
        m_data = nullptr;
        m_size = 0;
    }

    constexpr void resize(const std::size_t sz){
        auto newData = new T[sz]{};
        const auto minSize = (sz < m_size) ? sz : m_size;

        for(std::size_t i = 0; i < minSize; i++){
            newData[i] = m_data[i];
        }


        delete []m_data;
        m_data = newData;
        m_size = sz;

    }

    constexpr void push_back(const T& value){
        if(m_size == m_capacity){
            m_capacity = m_size > 0? m_size*2 : 2;

            auto newData = new T[m_capacity];

            for(std::size_t i = 0; i < m_size; i++){
                newData[i] = m_data[i];
            }
            delete []m_data;
            m_data = newData;
        }

        m_data[m_size] = value;
        ++m_size;
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept{
        return m_size;
    }

    [[nodiscard]] constexpr bool empty() const noexcept{
        return m_size == 0;
    }

    [[nodiscard]] constexpr T& operator[](const std::size_t index) noexcept {
        return m_data[index];
    }

    [[nodiscard]] constexpr const T& operator[](const std::size_t index) const noexcept {
        return m_data[index];
    }

private:
    T *m_data{nullptr};
    std::size_t m_capacity{0};
    std::size_t m_size{0};
};


template<typename VecType>
void print(const VecType &vec){
    for(std::size_t i = 0; i < vec.size(); ++i){
        std::println("{}", vec[i]);
    }
}

template<typename VecType>
void performarceTest(const std::size_t size){
    VecType vec;
    const auto start = high_resolution_clock::now();

    for(std::size_t i{0}; i < size; ++i)
        vec.push_back(i);

    const auto end = high_resolution_clock::now();
    const auto time = duration_cast<milliseconds>(end - start).count();
    std::println("Total (ms) {}", time);
}

Vector<int> readDatabase(){
    Vector<int> vec;
    for(std::size_t i{0}; i < 1'000'000; ++i){
        vec.push_back(i);
    }
    return vec;
}

int main()
{
    Vector<int> vec;
    vec = readDatabase();

    Vector<int> vec2(std::move(vec));
    print(vec2);

    vec.push_back(1);

    {
        Vector<int> vec2;
        vec2 = vec;
        std::println("vec2[0]: {}", vec[0]);
    }

    std::println("vec[0]: {}", vec[0]);

    std::println("Minha versão");
    performarceTest<Vector<int>>(1000000);
    std::println("Biblioteca std::Vector");
    performarceTest<std::vector<int>>(1000000);


    std::println("Size: {}", vec.size());
    std::println("Empty: {}", vec.empty());

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    print(vec);

    std::println("Size: {}", vec.size());
    std::println("Empty: {}", vec.empty());

    vec.resize(10);
    print(vec);
    std::println("Size: {}", vec.size());

    vec.resize(2);
    print(vec);
    std::println("Size: {}", vec.size());

    vec.clear();
    std::println("Size: {}", vec.size());
    std::println("Empty: {}", vec.empty());

    return 0;
}

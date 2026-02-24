// usos da biblioteca vector

#include <vector>
#include <iostream>


template<typename T>
class Vector {
public:
    ~Vector() {
        delete []m_data;
    }
    
    constexpr void clear(){
        delete []m_data;
        m_data = nullptr;
        m_size = 0;
    }
    
    constexpr void resize(const std::size_t sz){
        auto newData = new T[sz];
        const auto minSize = (sz < m_size) ? sz : m_size;
        
        for(std::size_t i = 0; i < minSize; i++){
            newData[i] = m_data[i];
        }
        
        
        delete []m_data;
        m_data = newData;
        m_size = sz;
        
    }
    
    constexpr void push_back(const T& value){
        auto newData = new T[m_size + 1];
        
        for(std::size_t i = 0; i < m_size; i++){
            newData[i] = m_data[i];
        }
        
        newData[m_size] = value;
        delete []m_data;
        m_data = newData;
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
    std::size_t m_size{0};
};


int main()
{
    std::vector<int> vec;
    std::cout << "Hello World" << std::endl;
    return 0;
}

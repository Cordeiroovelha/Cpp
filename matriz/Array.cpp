#include <print>
#include <array>
#include <cstddef>
#include <expected>
#include <string>

using namespace std;

template <typename T, size_t Size>
class Array
{
public:
    using  value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;

    Array() = default;

    template <typename... Values>
    constexpr Array(Values... values) {
        const std::array<T, sizeof...(Values)> temp = {values...};
        std::copy(temp.begin(), temp.end(), m_elements);
    }

    [[nodiscard]] constexpr size_type size(void) const noexcept
    {
        return Size;
    }

    constexpr bool empty(void) const noexcept
    {
        return Size == 0;
    }

    [[nodiscard]] constexpr reference operator[](size_type pos) noexcept
    {
        return m_elements[pos];
    }

    [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept
    {
        return m_elements[pos];
    }

private:
    T m_elements[Size]{};
};

template <typename... Args>
auto accumulate(Args... args)
{
    return (args + ...);
}

template <typename T>
constexpr std::expected<typename T::value_type, std::string> max_element(const T& arr) noexcept
{
    if (arr.empty())
        return std::unexpected("Array is empty");

    auto greaterElement = arr[0];

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > greaterElement) {
            greaterElement = arr[i];
        }
    }
    return greaterElement;
}

int main()
{
    auto r = accumulate(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::println("Result: {}", r);

    Array <int, 5> ages {10, 20, 30, 40, 50};

    if (const auto res = max_element(ages); res){
        std::println("Max: {}", res.value());
    } else {
        std::println("error: {}", res.error());
    }

    return 0;
}

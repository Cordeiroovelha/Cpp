#include <list>
#include <print>
#include <array>
#include <vector>
#include <string>
#include <cstddef>
#include <expected>

using namespace std;

namespace cppcore::container{

template <typename T, size_t Size>
class ArrayConstIterator {
public:
    using iterator_category = std::contiguous_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using const_reference = const T&;

    constexpr ArrayConstIterator() noexcept = default;

    constexpr explicit ArrayConstIterator(pointer ptr, size_t offset = 0) noexcept : m_ptr(ptr), m_offset(offset){

    }

    [[nodiscard]] constexpr const_reference operator*() const noexcept {
        return m_ptr[m_offset];
    }

    //Pre
    constexpr ArrayConstIterator& operator++() noexcept {
        ++m_offset;
        return *this;
    }

    //Pos
    constexpr ArrayConstIterator& operator++(int) noexcept {
        ArrayConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    constexpr ArrayConstIterator& operator+=(difference_type offset) noexcept{
        m_offset += offset;
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const ArrayConstIterator &other) const noexcept{
        return m_offset <=> other.m_offset;
    }

    [[nodiscard]] constexpr bool operator==(const ArrayConstIterator &other) const noexcept{
        return *this <=> other == 0;
    }

    constexpr ArrayConstIterator& operator--() noexcept{
        --m_offset;
        return *this;
    }

    constexpr ArrayConstIterator operator--(int) noexcept{
        ArrayConstIterator temp = m_offset;
        --(*this);
        return temp;
    }

    constexpr ArrayConstIterator& operator-=(difference_type offset) noexcept{
        m_offset -= offset;
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept{
        return m_ptr + m_offset;
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayConstIterator &other) const noexcept{
        return !(*this == other);
    }

    [[nodiscard]] constexpr ArrayConstIterator operator+(difference_type offset) const noexcept{
        auto temp = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr ArrayConstIterator& operator-() noexcept{
        --m_offset;
        return *this;
    }

    [[nodiscard]] constexpr ArrayConstIterator operator-(difference_type offset) const noexcept{
        auto temp = *this;
        temp -= offset;
        return temp;
    }

    [[nodiscard]] constexpr difference_type operator-(const ArrayConstIterator& other) const noexcept{
        return m_offset - other.m_offset;
    }

protected:
    pointer m_ptr {nullptr};
    size_t m_offset {0};
};

template <typename T, size_t Size>
class ArrayIterator :public ArrayConstIterator<T, Size> {
public:
    using MyBase = ArrayConstIterator<T, Size>;
    using typename MyBase::iterator_category;
    using typename MyBase::value_type;
    using typename MyBase::difference_type;
    using typename MyBase::pointer;
    using typename MyBase::const_reference;
    using typename MyBase::reference;

    constexpr ArrayIterator() noexcept = default;

    constexpr explicit ArrayIterator(pointer ptr, size_t offset = 0) noexcept : MyBase(ptr, offset){

    }

    [[nodiscard]] constexpr reference operator*()  const noexcept {
        return const_cast<reference>(MyBase::operator*());
    }

    //pre
    constexpr ArrayIterator& operator++() noexcept {
        MyBase::operator++();
        return *this;
    }

    //pos
    constexpr ArrayIterator operator++(int) noexcept {
        auto temp = *this;
        MyBase::operator++();
        return temp;
    }

    constexpr ArrayIterator& operator+=(difference_type offset) noexcept {
        MyBase::operator+=(offset);
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const ArrayIterator& other) const noexcept{
        return MyBase::operator<=>(other);
    }

    [[nodiscard]] constexpr bool operator==(const ArrayIterator& other) const noexcept{
        return MyBase::operator==(other);
    }

    // ===EXERCICIO===
    constexpr ArrayIterator& operator--() noexcept {
        MyBase::operator--();
        return *this;
    }

    constexpr ArrayIterator operator--(int) noexcept{
        auto temp = *this;
        MyBase::operator--();
        return temp;
    }

    constexpr ArrayIterator& operator-=(difference_type offset) noexcept{
        MyBase::operator-=(offset);
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept{
        return const_cast<pointer>(MyBase::operator->());
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayIterator &other) const noexcept{
        return MyBase::operator!=(other);
    }

    [[nodiscard]] constexpr ArrayIterator operator+(difference_type offset) const noexcept{
        auto temp = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr ArrayIterator& operator-() noexcept{
        MyBase::operator--();
        return *this;
    }

    [[nodiscard]] constexpr ArrayIterator operator-(difference_type offset) const noexcept{
        auto temp = *this;
        temp -= offset;
        return temp;
    }

    [[nodiscard]] constexpr difference_type operator-(const ArrayIterator& other) const noexcept{
        return MyBase::operator-(other);
    }


};

template <typename T, size_t Size>
class Array
{
public:
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_iterator = ArrayConstIterator<T, Size>;
    using iterator = ArrayIterator<T, Size>;

    Array() = default;

    template <typename... Values>
    constexpr Array(Values... values) {
        static_assert(sizeof... (Values) <= Size, "Too many initializers");
        static_assert((std::is_constructible_v<Values, T> && ...), "All values must be T");
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

    const_iterator begin() const noexcept {
        return const_iterator(m_elements);
    }

    const_iterator end() const noexcept {
        return const_iterator(m_elements, Size);
    }

    iterator begin()  noexcept {
        return iterator(m_elements);
    }

    iterator end()  noexcept {
        return iterator(m_elements, Size);
    }

private:
    T m_elements[Size]{};
};

template <typename... Args>
auto accumulate(Args... args)
{
    return (args + ...);
}
}


namespace cppcore::algorithm{

template <typename iT>
constexpr iT max_element(iT begin, iT end) noexcept
{

    auto greaterElement = begin;

    for (auto it = std::next(begin); it != end; ++it) {
        if (*it > *greaterElement) {
            greaterElement = it;
        }
    }
    return greaterElement;
}
}

namespace cont = cppcore::container;
namespace algo = cppcore::algorithm;

int main()
{
    //std::array<float, 5>  ages{12,19,17,99.5,52};
    //std::list<float>      ages{12,19,17,99.5,52};
    //cont::Array<float, 5> ages{12,19,17,99.5,52};
    std::vector <int> ages {10, 20, 30, 40, 50};

    // numero max aceito utilizando a memoria pilha/stack
    constexpr auto total = (((1024 * 1003)) / sizeof(float));

    auto r = cont::accumulate(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::println("Result: {}", r);

    const auto res = algo::max_element(ages.begin(), ages.end() - 2);
    std::println("Max: {}", *res);


    return 0;
}

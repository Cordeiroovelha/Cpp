#include <iostream>
#include <algorithm>

template <typename T>
class UniquePtr {
public:
    constexpr UniquePtr() noexcept = default;

    constexpr UniquePtr(T *pointer) noexcept : m_pointer(pointer) {}

    constexpr UniquePtr(UniquePtr &&other) noexcept : m_pointer(other.m_pointer){
        other.m_pointer = nullptr;
    }

    constexpr ~UniquePtr() noexcept {delete m_pointer; }

    constexpr UniquePtr(const UniquePtr &other) noexcept = delete;

    constexpr UniquePtr& operator = (const UniquePtr &other) noexcept = delete;

    constexpr UniquePtr& operator = (UniquePtr &&other) noexcept{
        if (this != &other){
            reset(other.m_pointer);
            other.m_pointer = nullptr;
        }
        return *this;
    }

    [[nodiscard]] constexpr T& operator*() const noexcept {return *m_pointer;}

    [[nodiscard]] constexpr T* operator->() const noexcept {return m_pointer;}

    constexpr explicit operator bool() const noexcept {
        return static_cast<bool>(m_pointer);
    }

    [[nodiscard]] constexpr T* get() const noexcept {return m_pointer;}

    constexpr void swap(UniquePtr &other){
        std::swap(m_pointer, other.m_pointer);
    }

    constexpr void reset(T *pointer){
        delete m_pointer;
        m_pointer = pointer;
    }

    constexpr T* release() noexcept {
        auto tmp = m_pointer;
        m_pointer = nullptr;
        return tmp;
    }

private:
    T *m_pointer{nullptr};
};

struct Foo
{
    Foo() {std::cout << __func__ << std::endl;}
    ~Foo() {std::cout << __func__ << std::endl;}

    void bar() const {std::cout << __func__ << std::endl;}
};

int main(void){
    UniquePtr<int> ptr1(new int(5));
    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "*ptr1.get(): " << ptr1.get() << std::endl;

    ptr1.reset(new int(10));

    std::cout << "*ptr1: " << *ptr1 << std::endl;
    std::cout << "*ptr1.get(): " << ptr1.get() << std::endl;

    UniquePtr<int> ptr3(ptr1.release());

    std::cout << "*ptr3: " << *ptr3 << std::endl;
    std::cout << "*ptr3.get(): " << ptr3.get() << std::endl;

    if (ptr1) {
        std::cout << "*ptr1: " << *ptr1 << std::endl;
    }else{
        std::cout << "ptr1 is null\n";
    }

    ptr1 = std::move(ptr3);

    if (ptr1) {
        std::cout << "*ptr1: " << *ptr1 << std::endl;
    }else{
        std::cout << "ptr1 is null\n";
    }

    ptr1.swap(ptr3);

    if (ptr1) {
        std::cout << "*ptr1: " << *ptr1 << std::endl;
    }else{
        std::cout << "ptr1 is null\n";
    }

    UniquePtr<int> ptr4(std::move(ptr3));
    std::cout << "*ptr3.get(): " << ptr3.get() << std::endl;

    UniquePtr<Foo> ptr2(new Foo());
    ptr2->bar();

    return 0;
}

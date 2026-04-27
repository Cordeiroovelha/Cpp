#include <print>

using namespace std;

class Window {
    void title() const { std::println("Title...");}
    void drawBorders() const { std::println("DrawBorders..."); }
public:
    void show() const {
        title();
        drawBorders();
    }
};

class WindowWithMessage : public Window {
public:
    using Window::show;
    
    void show() const {
        Window::show();
        std:println("Message...");
    }
};

int main()
{
    WindowWithMessage w;
    w.show();
    return 0;
}

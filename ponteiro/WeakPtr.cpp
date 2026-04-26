// weak ptr é um ponteiro que não possui a propriedade de um recurso
// ou seja, ele não é responsável por liberar o recurso
// Ele é útil para evitar ciclos de referência

#include <print>
#include <memory>
#include <vector>

using namespace std;

class Object;

class Scene{
    std::vector<std::shared_ptr<Object>> _objects;

public:
    void addObject(std::shared_ptr<Object> obj){
        _objects.push_back(obj);
    }

    void info() const{
        std::println("Object Cout: {}", _objects.size());
    }
};

class Object {
    std::weak_ptr<Scene> _scene;
public:
    Object(std::shared_ptr<Scene> scene) : _scene(scene){
    }

    void printSceneInfo() const {
        if (auto scene = _scene.lock()){
            scene->info();
        }else {
            std::println("Scene has been destroyed!");
        }
    }
};

int main(int argc, char ** argv){
    auto scene = std::make_shared<Scene>();
    auto obj1 = std::make_shared<Object>(scene);
    auto obj2 = std::make_shared<Object>(scene);

    scene->addObject(obj1);
    scene->addObject(obj2);

    obj1->printSceneInfo();
    scene.reset();
    obj1->printSceneInfo();

    return 0;
}

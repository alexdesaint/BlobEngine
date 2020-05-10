#include <cstdint>
#include <entt/entt.hpp>
#include <iostream>

using namespace std;

class Shader {
public:
    string name;

    void init() { cout << "init shader : " << name << endl; }

    void destroy() { cout << "destroy shader : " << name << endl; }
};

struct Material {
    string name;

    void init() { cout << "init Material : " << name << endl; }

    void destroy() { cout << "destroy Material : " << name << endl; }
};

int main() {
    entt::registry registry;

    {
        auto entity = registry.create();
        registry.emplace<Shader>(entity, "Defaut");
        registry.emplace<Material>(entity, "Defaut");
    }

    cout << "Engine init" << endl;

    registry.view<Shader>().each([](auto &s) { s.init(); });
    registry.view<Material>().each([](auto &m) { m.init(); });

    cout << "yay i run my program" << endl;

    registry.view<Material>().each([](auto &m) { m.destroy(); });
    registry.view<Shader>().each([](auto &s) { s.destroy(); });

    cout << "Engine close" << endl;

    return 0;
}

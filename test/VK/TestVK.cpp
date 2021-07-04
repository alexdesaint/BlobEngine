#include <Blob/VK/Vertex.hpp>
#include <Blob/VK/Window.hpp>
#include <Blob/VK/model.hpp>
#include <functional>
#include <iostream>
#include <stdexcept>

using namespace Blob::VK;

class perso : public model {
public:
    perso(const Window &coreEngine) :
        model(coreEngine, "textures/blob.bmp", "models/cube.obj") {
        // updateUniformBuffer();
        // SDL_AddTimer(25, deplacement, (void *) this);
        // interval the timer delay(ms) passed to callback
        // callback the function to call when the specified
        // interval elapses; see Remarks for details param a
        // pointer that is passed to callback
    }

    void mooveRight() { vitesse.x = vitesse.x - 0.1f; }

    void mooveLeft() { vitesse.x = vitesse.x + 0.1f; }

    void mooveUp() { vitesse.y = vitesse.y + 0.1f; }

    void moovedown() { vitesse.y = vitesse.y - 0.1f; }

    void update() { updateUniformBuffer(); }

private:
    struct vecteur {
        float x, y;
        vecteur() {
            x = 0;
            y = 0;
        }
    };

    // SDL_TimerID timer;
    vecteur vitesse;

    static uint32_t deplacement(uint32_t interval, void *xthis) {
        ((perso *) xthis)->position.x =
            ((perso *) xthis)->position.x + ((perso *) xthis)->vitesse.x;
        ((perso *) xthis)->position.y =
            ((perso *) xthis)->position.y + ((perso *) xthis)->vitesse.y;
        return 25;
    }
};

class fond : public model {
public:
    fond(const Window &coreEngine) :
        model(coreEngine, "textures/fenetre.bmp", "models/world.obj") {
        position = Blob::Vec3<float>(0, 0, 1);
        updateUniformBuffer();
    }
};

class jeu {

public:
    const Window &coreEngine;
    perso blob;
    fond fonde;

    jeu(const Window &coreEngine) :
        coreEngine(coreEngine), blob(coreEngine), fonde(coreEngine) {
        // coreEngine.pipe.loadModel();

        std::cout << "YAY" << std::endl;

        while (!quit) {
            blob.update();
            // coreEngine.pipe.drawFrame();
        }
    }

private:
    bool quit = false;
};

int main() {
    try {
        Window give_me_a_name(400, 800);
        while (give_me_a_name.isOpen()) {
            give_me_a_name.updateInputs();
        }
    } catch (const Blob::VK::Exception &e) {
        std::cout << "Vulkan error : " << std::endl << e.what();
    } catch (const std::runtime_error &e) {
        std::cout << "Game error : " << std::endl << e.what();
    }

    return 0;
}
#ifndef BOMBERMAN_CONTROLS_HPP
#define BOMBERMAN_CONTROLS_HPP

#include <string>
#include <list>

namespace Blob {

    class Controls {
    public:
        static void init(void *window);

        class Keys {
        public:
            const static bool
                    &UNKNOWN,
                    &APOSTROPHE, &COMMA, &MINUS, &EQUAL, &PERIOD, &SEMICOLON,
                    &SLASH, &BACKSLASH,
                    &NUM_0, &NUM_1, &NUM_2, &NUM_3, &NUM_4, &NUM_5, &NUM_6, &NUM_7, &NUM_8, &NUM_9,
                    &A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K, &L, &M, &N, &O, &P, &Q, &R, &S, &T, &U, &V, &W, &X, &Y, &Z,
                    &LEFT_BRACKET, &RIGHT_BRACKET, &GRAVE_ACCENT,
                    &WORLD_1, &WORLD_2,
                    &ESCAPE, &ENTER, &TAB, &SPACE, &BACKSPACE,
                    &RIGHT, &LEFT, &DOWN, &UP, &PAGE_UP, &PAGE_DOWN, &HOME, &END,
                    &CAPS_LOCK, &SCROLL_LOCK, &NUM_LOCK,
                    &PRINT_SCREEN, &PAUSE, &INSERT, &DELETE,
                    &F1, &F2, &F3, &F4, &F5, &F6, &F7, &F8, &F9, &F10, &F11, &F12, &F13, &F14,
                    &F15, &F16, &F17, &F18, &F19, &F20, &F21, &F22, &F23, &F24, &F25,
                    &KP_0, &KP_1, &KP_2, &KP_3, &KP_4, &KP_5, &KP_6, &KP_7, &KP_8, &KP_9,
                    &KP_DECIMAL, &KP_DIVIDE, &KP_MULTIPLY, &KP_SUBTRACT, &KP_ADD, &KP_ENTER, &KP_EQUAL,
                    &LEFT_SHIFT, &LEFT_CONTROL, &LEFT_ALT, &LEFT_SUPER,
                    &RIGHT_SHIFT, &RIGHT_CONTROL, &RIGHT_ALT, &RIGHT_SUPER,
                    &MENU;

            static std::string getName(const bool &key);
        };

        class Controller {
        public:
            int number;

            std::string name;
            bool stillConnected = false;

            int buttonsCount = 0;
            const unsigned char *buttons = nullptr;

            int joystickAxesCount = 0;
            const float *joystickAxes = nullptr;
        };

        const static std::list<const Controller *> &controllers;

        static void updateControllers();
    };
}

#endif //BOMBERMAN_CONTROLS_HPP

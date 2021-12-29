#pragma once

#include <ostream>

template<class T>
class Printer {
private:
    unsigned int tabulation = 0;
    const T &object;

public:
    Printer(const T &object) : object(object) {}

    std::string indent(unsigned int extra = 0) {
        std::string ret;
        ret.resize((tabulation + extra) * 4);
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const Printer<T> &object);
};
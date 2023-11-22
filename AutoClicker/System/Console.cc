#include <iostream>

namespace AutoClicker
{
    struct Console {
        bool logging;

        Console& operator<< (const char* str) {
            if (logging)
                std::cout << str;
            return *this;
        }
    } logOut{true};
}
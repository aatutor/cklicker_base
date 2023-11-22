#include <iostream>
// #include <windows.h>
#include "AutoClicker.h"

void TestPlay()
{
    using namespace std;
    using namespace AutoClicker;

    cout << "begin" << endl;

#if 1
    while(1) MouseEvent();
#else
    EventPtr lClick = new Mouse();
    while(1) lClick();
#endif
}
void TestMove() 
{
    using std::cout;
    using std::endl;
    using namespace AutoClicker;
    cout << "begin" << endl;

    EventPtr mouseMove = new Mouse({MOUSEEVENTF_MOVE, 10, -10});
    while(1) {
        mouseMove();
        Sleep(100);
    }
}


int main() 
{
    using namespace std;
    try {
        // TestPlay();
        TestMove();
    }
    catch (const exception& err) {
        cout << err.what() << endl;
    }

    cout << endl;
    return 0;
}
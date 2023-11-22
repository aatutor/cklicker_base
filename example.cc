#include <iostream>
#include "AutoClicker.h"
#include <list>

void TestPlay()
{
    using namespace AutoClicker;

#if 0
    EventPtr empty = new Mouse();
    while(true) empty();
#else
    while(true) MouseEvent();
#endif
}
void TestMove() 
{
    AutoClicker::Mouse mouseMove({MOUSEEVENTF_MOVE, 10, -10});
    while(true) {
        mouseMove();
        Sleep(100);
    }
}
void TestLeftClick()
{
    AutoClicker::EventPtr leftClick = new AutoClicker::Mouse({MOUSEEVENTF_LEFTDOWN}),
            leftUp = new AutoClicker::Mouse({MOUSEEVENTF_LEFTUP});
#if 0
    for(;;){
        leftClick();
        Sleep(10);
        leftUp();
        Sleep(10);
    }
#else
    leftClick->delay_ = 10;
    leftUp->delay_ = 50;
    for(;;){
        leftClick();
        leftUp();
    }
#endif
}
void TestCombinations()
{
    using namespace AutoClicker;
    std::list<EventPtr> commands;
    commands.push_back(new Mouse({MOUSEEVENTF_LEFTDOWN}));
    commands.push_back(new Mouse({MOUSEEVENTF_MOVE, 300}));
    commands.push_back(new Mouse({MOUSEEVENTF_LEFTUP}));
    commands.push_back(new Keyboard({VK_CONTROL}));
    commands.push_back(new Keyboard({'C'}));
    commands.push_back(new Keyboard({'C', 0, KEYEVENTF_KEYUP}));
    commands.push_back(new Keyboard({VK_CONTROL, 0, KEYEVENTF_KEYUP}));

    for(EventPtr& doing : commands) {
        doing();
    }
}


int main() 
{
    using namespace std;
    size_t i = 0;
begin_test:
    cout << "begin" << endl;
    try {
        ++i;
        switch(i){
            case 1: TestPlay();
            case 2: TestMove();
            case 3: TestLeftClick();
            case 4: TestCombinations();
        }
    }
    catch (const exception& err) {
        cout << err.what() << endl;
        goto begin_test;
    }

    cout << endl;
    return 0;
}
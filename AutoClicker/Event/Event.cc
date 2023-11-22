#include <windows.h>
#include <exception>

namespace AutoClicker {
    class Event {
        static const unsigned short SYS_DELAY_MS = 1;
    protected:

        virtual void Do() = 0;
    public:
        unsigned int delay_ = 0;
        
        void operator() () {
            Sleep(SYS_DELAY_MS);
            Sleep(delay_);

            bool pause = false;
            do {
                if ( btnPause.IsPressed() ){
                    pause = !pause;
                    logOut << "script " 
                        << (pause ? "paused":"continue")
                        << "\n";
                }
                if ( btnStop.IsPressed() ) {
                    logOut << "script stoped\n";
                    throw std::logic_error("Script stoped by User!");
                }
            } while (pause);

            Do();
        }
    };
}
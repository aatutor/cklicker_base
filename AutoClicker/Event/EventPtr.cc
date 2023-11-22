#include <memory>

namespace AutoClicker {
    class EventPtr {
        std::unique_ptr<Event> ptr_;
    public:
        EventPtr(Event* p): ptr_(p) {}
        
        void operator() () {
            (*ptr_)();
        }
    };
}
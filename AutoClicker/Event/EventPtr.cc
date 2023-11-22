#include <memory>

namespace AutoClicker {
    class EventPtr {
        std::unique_ptr<Event> ptr_;
    public:
        EventPtr(Event* p): ptr_(p) {}
        
        void operator() () {
            (*ptr_)();
        }
        Event* operator-> () {
            return &*ptr_;
        }
    };
}
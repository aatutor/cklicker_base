#include <windows.h>

namespace AutoClicker
{
    struct MouseArgs {
        short       flag;
        short       dx;
        short       dy;
        short       data;
        ULONG_PTR   extra;
    };

    class Mouse: public Control<MouseArgs> {
    public:
        Mouse(MouseArgs vals = {}): Control(vals) {}
    protected:
        void Do() override {
            mouse_event(args.flag, args.dx, args.dy, args.data, args.extra);
        }
    } MouseEvent;
}

namespace AutoClicker
{    
    struct KeyboardArgs {
        BYTE      vk;
        BYTE      scan;
        DWORD     flag;
        ULONG_PTR extra;
    };
    class Keyboard: public Control<KeyboardArgs> {
    public:
        Keyboard(KeyboardArgs vals = {}): Control(vals) {}
    protected:
        void Do() override {
            keybd_event(args.vk, args.scan, args.flag, args.extra);
        }
    } KeybdEvent;
}

#include <windows.h>

namespace AutoClicker {
    class KeysCombination {
        int key_;
        int alt_;
    public:
        KeysCombination(const int& k, const int& a)
                : key_(k), alt_(a) 
        { 
            Reset();
        }
        void SetKey(const int& k) {
            key_ = k;
            Reset();
        }
        void SetAlt(const int& a) {
            alt_ = a;
            Reset();
        }
        void Reset() {
            GetAsyncKeyState(key_);
            GetAsyncKeyState(alt_);
        }
        bool IsPressed() {
            return GetAsyncKeyState(key_) & 1 
                && GetAsyncKeyState(alt_) != 0;
        }
    }   btnStop('S', VK_LMENU), 
        btnPause('A', VK_LMENU);
}
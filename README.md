# JustClick

This is simple lib for using Win32 API. For the most convenient writing of a sequence of commands and control of its behavior.

* Use **Alt + A** for ***Pause***
* Use **Alt + S** for ***Stop*** *(thowable)*
* It works any time of sequence

Include `"AutoClicker.h"` and use `AutoClicker` namespace in your project.

For change hotkeys init values of `btnStop` and `btnPause` objects. Fields `key_` and `alt_` keeps vals.
 
Use `Mouse` or `Keyboard` class to create your functor, that calls [mouse](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event)/[keybd_event](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-keybd_event) functions. Also you can use `MouseEvent` or `KeybdEvent` global objects. 

Arguments are passed as a structure. Initialize this by *c-tor* or *operator()*, then the functor will remember args.

## Throw!

If User press ***Stop***, then next call functor will throw [logic_error](https://en.cppreference.com/w/cpp/error/logic_error). Don't forget catch it.

---

### Plained to add:
- grow events
- screen image processing
- more functional `logOut`

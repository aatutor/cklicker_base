namespace AutoClicker
{
    template <class T>
    class Control: public Event {
    public:
        T args = {};
        
        Control (const T& vals): args(vals) {}

        void operator() (T vals) {
            args = vals;
            Event::operator()();
        }
        using Event::operator(); // cz name hiding... >_<
    };
}
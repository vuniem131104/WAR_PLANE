#ifndef timer_h
#define timer_h

class Timer{
    public:
    Timer();
    ~Timer();
    void start();
    void stop();
    int get_ticks();
    void paused();
    void unpaused();
    bool is_start();
    bool is_paused();
    private:
    int start_tick_;
    int paused_tick_;
    bool is_paused_;
    bool is_started_;
};

#endif 
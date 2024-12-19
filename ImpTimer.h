#ifndef IMP_TIMER_H_
#define IMP_TIMER_H_

class ImpTimer
{
private:
    int start_tick_;
    int paused_tick_;

    bool is_paused_;
    bool is_started_;

public:
    ImpTimer(/* args */);
    ~ImpTimer();


    void Start();
    void Stop();
    void paused();
    void resume();
    
    int get_ticks();

    bool is_paused();
    bool is_started();

};
#endif
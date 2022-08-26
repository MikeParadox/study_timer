#ifndef TIMER_H
#define TIMER_H

#include "timerwidget.h"
#include <chrono>
#include <iostream>
#include <thread>

using seconds_t = std::chrono::seconds;
using minutes_t = std::chrono::minutes;
using hours_t = std::chrono::hours;
using timePoint_t = std::chrono::time_point<std::chrono::system_clock>;
using namespace std::literals; // for using literals like 10s

/**
 * class to implement timer
 */
class Timer
{
public:

    Timer() = default;

    explicit Timer(seconds_t timeForTimerSeconds);
        
    seconds_t getTimerTimeInMinutes() const;
    void setTimeForTimer(int minutes);
    void setTimeForTimer(int minutes, int hours);
    void changeExistingTimer(int hours, int minutes);
    
    /**
     * make Timer a functor(make it "collable")
     *
     * @return int
     */
    int operator()(TimerWidget* t) const;

private:
    seconds_t mTimeForTimer;
    std::string mName; // TODO add labels on timers in GUI
};

#endif  // TIMER_H

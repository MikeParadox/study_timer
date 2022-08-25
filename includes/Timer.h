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

/**
 * class to implement timer 
 * the possibility to initialise a Timer using integral types was
 *  ommited purposely, because providing just an integer would be ambiguous
 *  in relation to time units
 */

using namespace std::literals; // for using literals like 1s

class Timer
{
    seconds_t mTimeForTimer;    // timePoint mStartTime{};
public:

    Timer() = default;
    
    explicit Timer(hours_t timeForTimerHours, minutes_t timeForTimerMinutes)
        : mTimeForTimer{ timeForTimerMinutes + timeForTimerHours }
    {}

    explicit Timer(hours_t timeForTimerHours)
        : mTimeForTimer{ static_cast<minutes_t>(timeForTimerHours) }
    {}

    explicit Timer(minutes_t timeForTimerMinutes)
        : mTimeForTimer{ timeForTimerMinutes }
    {}

    explicit Timer(seconds_t timeForTimerSeconds)
        : mTimeForTimer{ timeForTimerSeconds }
    {}

    seconds_t getTimerTimeInMinutes() const { return mTimeForTimer; }

    void setTimeForTimer(int minutes)
    {
        mTimeForTimer = static_cast<seconds_t>(minutes * 60);
    }
    void setTimeForTimer(int minutes, int hours)
    {
        mTimeForTimer = static_cast<seconds_t>(minutes * 60 + hours * 3600);
    }

    void changeExistingTimer(int hours, int minutes)
    {
        mTimeForTimer = static_cast<seconds_t>(hours * 3600 + minutes * 60);
    }

    /**
     * make Timer a functor(make it "collable")
     * 
     * @return int 
     */
    //int operator()(TimerWidget *t) const
    int start(TimerWidget *t)
    {
        timePoint_t timerStartTime{ std::chrono::system_clock::now() };
        timePoint_t timeToStop{ timerStartTime + mTimeForTimer };
        while (timeToStop > std::chrono::system_clock::now())
        {
            if (!t->paused)
            {
            t->setTotalTime(t->getTotalTime()-1s);
            t->setTimeLabel(t->getTotalTime());

            if (t->getTotalTime() == 0s)
            {
                t->setTimeLabelFinished();
            }

            std::this_thread::sleep_for(1s);
            }
        }

       return 0;
    }
};

#endif  // TIMER_H

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>
#include <thread>

using minutes_t = std::chrono::minutes;
using hours_t = std::chrono::hours;
using timePoint_t = std::chrono::time_point<std::chrono::system_clock>;

/**
 * class to implement timer 
 * 
 */
class Timer
{
    minutes_t mTimeForTimer;    // timePoint mStartTime{};
public:

    Timer() = default;
    
    explicit Timer(hours_t timeForTimerHours, minutes_t timeForTimerMinutes)
        : mTimeForTimer{ timeForTimerMinutes +
        static_cast<minutes_t>(timeForTimerHours) }
    {}

    explicit Timer(hours_t timeForTimerHours)
        : mTimeForTimer{ static_cast<minutes_t>(timeForTimerHours) }
    {}

    explicit Timer(minutes_t timeForTimerMinutes)
        : mTimeForTimer{ timeForTimerMinutes }
    {}

    minutes_t getTimerTimeInMinutes() const { return mTimeForTimer; }

    void setTimeForTimer(int minutes)
    {
        mTimeForTimer = static_cast<minutes_t>(minutes);
    }
    void setTimeForTimer(int minutes, int hours)
    {
        mTimeForTimer = static_cast<minutes_t>(minutes + hours * 60);
    }

    int operator()() const
    {
        timePoint_t timerStartTime{ std::chrono::system_clock::now() };
        timePoint_t timeToStop{ timerStartTime + mTimeForTimer };
        while (timeToStop > std::chrono::system_clock::now())
        { 
        }

        return 0;
    }
};

#endif

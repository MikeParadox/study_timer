#include "Timer.h"
#include <memory>
#include <thread>

Timer::Timer(seconds_t timeForTimerSeconds)
    : mTimeForTimer{ timeForTimerSeconds }
{}

seconds_t Timer::getTimerTimeInMinutes() const { return mTimeForTimer; }

void Timer::setTimeForTimer(int minutes)
{
    mTimeForTimer = static_cast<seconds_t>(minutes * 60);
}
void Timer::setTimeForTimer(int minutes, int hours)
{
    mTimeForTimer = static_cast<seconds_t>(minutes * 60 + hours * 3600);
}

void Timer::changeExistingTimer(int hours, int minutes)
{
    mTimeForTimer = static_cast<seconds_t>(hours * 3600 + minutes * 60);
}


int Timer::operator()(TimerWidget* t) const
{
    while (t->getTotalTime() > 0s)
    {
        if (!t->getPauseState())
        {
            t->setTotalTime(t->getTotalTime() - 1s);
            t->setTimeLabel(t->getTotalTime());
            std::this_thread::sleep_for(1s);
        }
    }

    return 0; // TODO implement status code control
}

#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include "timerselection.h"

namespace Ui {
class TimerWidget;
}

class Timer;

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

    bool paused;
    Timer *timer;
    std::chrono::seconds totalTime;

    void initialize(TimerSelection *t);
    void setTime(std::chrono::seconds);
    void startTimer();
    void handlePauseButton();

private:
    Ui::TimerWidget *ui;
};

#endif // TIMERWIDGET_H

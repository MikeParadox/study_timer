#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <chrono>

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

    std::chrono::seconds totalTime;
    void setTime(std::chrono::seconds);

private:
    Ui::Timer *ui;
};

#endif // TIMER_H

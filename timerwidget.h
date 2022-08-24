#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include "includes/Timer.h"
#include "timerselection.h"

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

    Timer timer;
    std::chrono::seconds totalTime;

    void initialize(TimerSelection *t);
    void setTime(std::chrono::seconds);

private:
    Ui::TimerWidget *ui;
};

#endif // TIMERWIDGET_H

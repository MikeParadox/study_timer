#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

    std::chrono::seconds totalTime;
    void setTime(std::chrono::seconds);

private:
    Ui::TimerWidget *ui;
};

#endif // TIMERWIDGET_H

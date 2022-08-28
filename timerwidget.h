#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include "timerselection.h"
#include <string>

namespace Ui {
class TimerWidget;
}

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

    void initialize(TimerSelection *t);
    void setTimeLabel(std::chrono::seconds);
    void finished();
    int timerLoop();
    void handleStartButton();
    void handlePauseButton();
    void handleResetButton();
    void handleEditButton();
    void handleDeleteButton();
    void editTimer();
    void printName();

private:
    Ui::TimerWidget *ui;

    std::chrono::seconds initialTime;
    std::chrono::seconds totalTime;
    const QString timerName{ "timer" };
    bool paused;
    bool toBeDeleted;
    bool isFinished;
};

#endif // TIMERWIDGET_H

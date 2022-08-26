#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include "timerselection.h"

namespace Ui {
class TimerWidget;
}

class Timer;
class MainWindow;

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = nullptr);
    ~TimerWidget();

    void initialize(TimerSelection *t);
    void setTimeLabel(std::chrono::seconds);
    void finished();
    void startTimer();
    void handlePauseButton();
    void handleResetButton();
    void handleEditButton();
    void handleDeleteButton();
    std::chrono::seconds getTotalTime();
    void setTotalTime(std::chrono::seconds);
    bool getPauseState();
    void editTimer();
    bool getDeleted();

private:
    Ui::TimerWidget *ui;
    std::chrono::seconds initialTime;
    std::chrono::seconds totalTime;
    bool paused;
    bool toBeDeleted;
};

#endif // TIMERWIDGET_H

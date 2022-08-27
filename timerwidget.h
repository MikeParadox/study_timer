#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
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

    void initialize(TimerSelection *t);
    void setTimeLabel(std::chrono::seconds);
    void finished();
    int timerLoop();
    void handlePauseButton();
    void handleResetButton();
    void handleEditButton();
    void handleDeleteButton();
    void editTimer();

private:
    Ui::TimerWidget *ui;

    std::chrono::seconds initialTime;
    std::chrono::seconds totalTime;
    bool paused;
    bool toBeDeleted;
    bool isFinished;
};

#endif // TIMERWIDGET_H

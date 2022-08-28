#ifndef TIMERSELECTION_H
#define TIMERSELECTION_H

#include <QDialog>

namespace Ui {
class TimerSelection;
}

class TimerSelection : public QDialog
{
    Q_OBJECT

public:
    explicit TimerSelection(QWidget *parent = nullptr);
    ~TimerSelection();

    std::chrono::hours getHours();
    std::chrono::minutes getMinutes();
    QString getTimerName();
    void setTime(std::chrono::seconds);
    void setTimerName(QString);

private:
    Ui::TimerSelection *ui;
};

#endif // TIMERSELECTION_H

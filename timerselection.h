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
    int getMinutes();
    int getSeconds();

private:
    Ui::TimerSelection *ui;
};

#endif // TIMERSELECTION_H

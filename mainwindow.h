#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "randomguess.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_new_guess();
private slots:

    void on_enter_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<randomGuess> random;
};

#endif // MAINWINDOW_H

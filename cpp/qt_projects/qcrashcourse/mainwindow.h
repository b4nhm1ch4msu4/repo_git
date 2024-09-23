#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_plus_Button_clicked();

    void on_multi_Button_clicked();

    void on_minus_Button_clicked();

    void on_divide_Button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

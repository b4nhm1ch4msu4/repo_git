#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qcombobox.h>

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
    void toggleConnection();
    void sendData();
    void readData();

private:
    Ui::MainWindow *ui;

    void openSerialPort();
    void closeSerialPort();

    QSerialPort *serial;
    QLineEdit *portLineEdit;
    QLabel *inputLable;
    QLineEdit *inputLineEdit;
    QTextEdit *outputTextEdit;
    QPushButton *connectButton;
    QLabel *portLabel;
    QLabel *listLable;
    QComboBox *listAvailableCombobox;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
int firstNum, secondNum, result;
void MainWindow::on_plus_Button_clicked()
{
    firstNum = ui->lineEdit_firstnum->text().toInt();
    secondNum = ui->lineEdit_secondnum->text().toInt();
    result = firstNum + secondNum;
    ui->lineEdit_result->setText(QString::number(result));
}


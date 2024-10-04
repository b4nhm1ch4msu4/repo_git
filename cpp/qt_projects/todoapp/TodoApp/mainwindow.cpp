#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>

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
void MainWindow::on_addBtn_clicked()
{
    QListWidgetItem* item = new QListWidgetItem(ui->txtTask->text(), ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}


void MainWindow::on_removeBtn_clicked()
{

}


void MainWindow::on_remveAllBtn_clicked()
{

}


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

QSerialPort *serial;
QFile logFile;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox->addItem(info.portName());
    }

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);
    connect(ui->connect_pushButton, &QPushButton::clicked,this, &MainWindow::toggleConnection);

}

void MainWindow::toggleConnection() {
    if(serial->isOpen()){
        serial->close();
        ui->connect_pushButton->setText("Connect");
    }else {
        QString portName = ui->comboBox->currentText();
        // serial->setPortName(portName);
        serial->setPortName("/dev/pts/2");
        serial->setBaudRate(QSerialPort::Baud9600);
        if (serial->open(QIODevice::ReadOnly)) {
            ui->connect_pushButton->setText("Disconnect");

            logFile.setFileName("log.txt");
            logFile.open(QIODevice::Append | QIODevice::Text);
        }
    }
}

void MainWindow::readSerial(){
    QByteArray data = serial->readAll();
    QString text = QString::fromUtf8(data);
    ui->textEdit->append(text);

    if (logFile.isOpen()){
        QTextStream out(&logFile);
        out << QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ") << text;
    }
}


MainWindow::~MainWindow()
{
    if (serial->isOpen()) serial->close();
    if(logFile.isOpen()) logFile.close();
    delete ui;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSerialPort>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);

    portLabel = new QLabel("Serial Port:");
    portLineEdit = new QLineEdit;
    inputLable = new QLabel("Send command: ");
    inputLineEdit = new QLineEdit;
    inputLineEdit->setEnabled(false);  // Disabled until connected
    outputTextEdit = new QTextEdit;
    connectButton = new QPushButton("Connect");

    listLable = new QLabel("List Available Ports: ");
    listAvailableCombobox = new QComboBox;

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *portLayout = new QHBoxLayout;
    QHBoxLayout *inputLayout = new QHBoxLayout;
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portLineEdit);
    portLayout->addWidget(listLable);
    portLayout->addWidget(listAvailableCombobox);
    inputLayout->addWidget(inputLable);
    inputLayout->addWidget(inputLineEdit);
    mainLayout->addLayout(portLayout);
    mainLayout->addWidget(outputTextEdit);
    mainLayout->addLayout(inputLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(connectButton);
    mainLayout->addLayout(buttonLayout);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::toggleConnection);
    connect(inputLineEdit, &QLineEdit::returnPressed, this, &MainWindow::sendData);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        listAvailableCombobox->addItem(info.portName());
    }
}

void MainWindow::toggleConnection() {
    if (serial->isOpen()) {
        closeSerialPort();
    } else {
        openSerialPort();
    }
}

void MainWindow::openSerialPort() {
    QString portName = portLineEdit->text();
    if (portName.isEmpty()) {
        outputTextEdit->append("Please enter a serial port name");
        return;
    }
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        outputTextEdit->append(QString("Serial port %1 opened").arg(portName));
        portLineEdit->setEnabled(false);
        inputLineEdit->setEnabled(true);
        connectButton->setText("Disconnect");
    } else {
        outputTextEdit->append("Failed to open serial port: " + serial->errorString());
    }
}

void MainWindow::closeSerialPort() {
    if (serial->isOpen()) {
        serial->close();
        outputTextEdit->append("Serial port closed");
        portLineEdit->setEnabled(true);
        inputLineEdit->setEnabled(false);
        connectButton->setText("Connect");
    }
}

void MainWindow::sendData() {
    if (!serial->isOpen()) return;
    QString data = inputLineEdit->text();
    if (!data.isEmpty()) {
        outputTextEdit->append("[Serial com app]: " + data);
        QByteArray byteData = data.toUtf8() + '\n';
        serial->write(byteData);
        inputLineEdit->clear();
    }
}

void MainWindow::readData() {
    while (serial->canReadLine()) {
        QByteArray data = serial->readLine();
        outputTextEdit->append("[Fake device]: " + QString::fromUtf8(data).trimmed());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if(serial->isOpen()){
        serial->close();
    }
}

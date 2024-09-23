#include "analogclock.h"
#include "./ui_analogclock.h"

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AnalogClock)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock"));
    resize(200, 200);
}

AnalogClock::~AnalogClock()
{
    delete ui;
}

AnalogClock::paintEvent(QPaintEvent *event){
    static const QPoint hourHand[4] = {
        Point(5, 14),
        QPoint(-5, 14),
        QPoint(-4, -71),
        QPoint(4, -71)
    };
    static const QPoint minuteHand[4] = {
        QPoint(4, 14),
        QPoint(-4, 14),
        QPoint(-3, -89),
        QPoint(3, -89)
    };
    static const QPoint secondsHand[4] = {
        QPoint(1, 14),
        QPoint(-1, 14),
        QPoint(-1, -89),
        QPoint(1, -89)
    };

    const QColor hourColor(palette().color(QPalette::Text));
    const QColor minuteColor(palette().color(QPalette::Text));
    const QColor secondColor(palette().color(QPalette::Text));

    int side = qMin(width(), height());
}

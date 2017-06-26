#include "widget.h"
#include <wiringPi.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_blinkButton.setText(tr("Blink 10 times"));
    m_label.setText(tr("Output 22"));

    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->addWidget(&m_blinkButton);
    vBoxLayout->addWidget(&m_label);

    setLayout(vBoxLayout);

    setWindowTitle(tr("Hello Widget"));

    blinkButtonPressed();

    connect(&m_blinkButton, SIGNAL(pressed()), this, SLOT(blinkButtonPressed()) );
}

Widget::~Widget()
{

}

void Widget::blinkButtonPressed()
{
    m_label.setText(tr("Output 22: Blinking"));

    //  BCM: Pin Index: 6, 5, 21, 20
    //  GPIO Number:

    int pins[] = {22, 21, 29, 28 };
    wiringPiSetup () ;

    int pin = 22;

    for (int i = 0; i < 10; i++)
    {
        for (int ri = 0; ri < 4; ri++)
        {
            pin = pins[ri];
            pinMode (pin, OUTPUT) ;
            digitalWrite (pin, HIGH) ; delay (100) ;
            digitalWrite (pin,  LOW) ; delay (100) ;
        }

    }
    m_label.setText(tr("Output 22:"));

}

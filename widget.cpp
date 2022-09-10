#include "widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    CreatingModels();
    DarkTheme();

    marker1 = new QLabel;
    marker2 = new QLabel;
    marker3 = new QLabel;

    marker1->setText("Work place 1");
    marker2->setText("Work place 2");
    marker3->setText("Work place 3");

    zone3 = new QGridLayout;
    zone2 = new QGridLayout;
    zone1 = new QGridLayout;

    color_switch1 = new QComboBox;
    color_switch2 = new QComboBox;
    color_switch3 = new QComboBox;

    color_switch1->addItems(switch_c);
    color_switch2->addItems(switch_c);
    color_switch3->addItems(switch_c);

    zones =  new QHBoxLayout;

    zone1->addWidget(marker1,0,0);
    zone2->addWidget(marker2,0,0);
    zone3->addWidget(marker3,0,0);

    zone1->addWidget(color_switch1,1,0);
    zone2->addWidget(color_switch2,1,0);
    zone3->addWidget(color_switch3,1,0);

    zone1->addWidget(RGB,2,0);
    zone2->addWidget(CMYK,2,0);
    zone3->addWidget(HLS,2,0);

    zones->addLayout(zone1);
    zones->addLayout(zone2);
    zones->addLayout(zone3);



    this->setLayout(zones);
    //connect(color_switch1,SIGNAL(activated(int,QObject*)),SLOT);
    //connect();
    //connect();

    //this->setWindowFlags(Qt::Custom izeWindowHint);

}

 void Widget::CreatingModels() {
    RGB = new QGroupBox;
    HSV = new QGroupBox;
    CMYK = new QGroupBox;
    HLS = new QGroupBox;
    XYZ = new QGroupBox;
    LAB = new QGroupBox;

    RGB_l = new QGridLayout;
    HSV_l = new QGridLayout;
    CMYK_l = new QGridLayout;
    HLS_l = new QGridLayout;
    XYZ_l = new QGridLayout;
    LAB_l = new QGridLayout;

    RGB_Grad->setFixedSize(this->width()/6,this->width()/6);
    RGB_l->addWidget(RGB_Grad,0,0);
    RGB_l->addWidget(new QLabel{"R"},1,0);
    RGB_l->addWidget(R,1,1);
    RGB_l->addWidget(new QLabel{"G"},2,0);
    RGB_l->addWidget(G,2,1);
    RGB_l->addWidget(new QLabel{"B"},3,0);
    RGB_l->addWidget(B,3,1);
    RGB->setLayout(RGB_l);

    HSV_Grad->setFixedSize(this->width()/6,this->width()/6);
    HSV_l->addWidget(HSV_Grad,0,0);
    HSV_l->addWidget(new QLabel{"H"},1,0);
    HSV_l->addWidget(new QLabel{"S"},2,0);
    HSV_l->addWidget(new QLabel{"V"},3,0);
    HSV->setLayout(HSV_l);

    CMYK_Grad->setFixedSize(this->width()/6,this->width()/6);
    CMYK_l->addWidget(CMYK_Grad,0,0);
    CMYK_l->addWidget(new QLabel{"C"},1,0);
    CMYK_l->addWidget(C,1,1);
    CMYK_l->addWidget(new QLabel{"M"},2,0);
    CMYK_l->addWidget(M,2,1);
    CMYK_l->addWidget(new QLabel{"Y"},3,0);
    CMYK_l->addWidget(Y,3,1);
    CMYK_l->addWidget(new QLabel{"K"},4,0);
    CMYK_l->addWidget(K,4,1);
    CMYK->setLayout(CMYK_l);

    HLS_Grad->setFixedSize(this->width()/6,this->width()/6);
    HLS_l->addWidget(HLS_Grad,0,0);
    HLS_l->addWidget(new QLabel{"H"},1,0);
    HLS_l->addWidget(HLS_H,1,1);
    HLS_l->addWidget(new QLabel{"L"},2,0);
    HLS_l->addWidget(HLS_L,2,1);
    HLS_l->addWidget(new QLabel{"S"},3,0);
    HLS_l->addWidget(HLS_S,3,1);
    HLS->setLayout(HLS_l);

    XYZ_Grad->setFixedSize(this->width()/6,this->width()/6);
    XYZ_l->addWidget(XYZ_Grad,0,0);
    XYZ_l->addWidget(new QLabel{"X"},1,0);
    XYZ_l->addWidget(XYZ_X,1,1);
    XYZ_l->addWidget(new QLabel{"Y"},2,0);
    XYZ_l->addWidget(XYZ_Y,2,1);
    XYZ_l->addWidget(new QLabel{"Z"},3,0);
    XYZ_l->addWidget(XYZ_Z,3,1);
    XYZ->setLayout(XYZ_l);

    LAB_Grad->setFixedSize(this->width()/6,this->width()/6);
    LAB_l->addWidget(LAB_Grad,0,0);

    LAB_l->addWidget(new QLabel{"L"},1,0);
    LAB_l->addWidget(new QLabel{"A"},2,0);
    LAB_l->addWidget(new QLabel{"B"},3,0);

    LAB_l->addWidget(LAB_L,1,1);
    LAB_l->addWidget(LAB_A,2,1);
    LAB_l->addWidget(LAB_B,3,1);

    LAB->setLayout(LAB_l);
}

 void Widget::paintEvent(QPaintEvent*) {
     QPixmap pix(RGB_Grad->width(),RGB_Grad->height());
     QPainter painter(&pix);
     QLinearGradient gradl(0,0,pix.width(),0);
     gradl.setColorAt(0,Qt::black);
     gradl.setColorAt(1,Qt::red);
     painter.setBrush(gradl);
     painter.drawRect(0,0,RGB_Grad->width(),RGB_Grad->height());
     RGB_Grad->setPixmap(pix);
     CMYK_Grad->setPixmap(pix);
     HLS_Grad->setPixmap(pix);
 }

 void Widget::DarkTheme() {
         QPalette darkPalette;
         darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::WindowText, Qt::white);
         darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
         darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
         darkPalette.setColor(QPalette::ToolTipText, Qt::white);
         darkPalette.setColor(QPalette::Text, Qt::white);
         darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
         darkPalette.setColor(QPalette::ButtonText, Qt::white);
         darkPalette.setColor(QPalette::BrightText, Qt::red);
         darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
         darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
         darkPalette.setColor(QPalette::HighlightedText, Qt::black);
         qApp->setPalette(darkPalette);
 }

Widget::~Widget() {}



#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QGradient"
#include "QLabel"
#include "QHBoxLayout"
#include "QComboBox"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QGroupBox"
#include "QPainter"
#include <QApplication>
#include "QLineEdit"

class Widget : public QWidget
{
    Q_OBJECT

//public signals:
  //  void activated(int,OBject);
//private slots:
  //  void Switch();


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void CreatingModels();
    void paintEvent(QPaintEvent*);
    void DarkTheme();

    QComboBox* color_switch1;
    QComboBox* color_switch2;
    QComboBox* color_switch3;

    QHBoxLayout* zones;

    QGridLayout* zone1;
    QGridLayout* zone2;
    QGridLayout* zone3;

    QLabel* marker1;
    QLabel* marker2;
    QLabel* marker3;

    QGroupBox* RGB;
    QGroupBox* CMYK;
    QGroupBox* HSV;
    QGroupBox* HLS;
    QGroupBox* XYZ;
    QGroupBox* LAB;

    QGridLayout* RGB_l;
    QGridLayout* CMYK_l;
    QGridLayout* HSV_l;
    QGridLayout* HLS_l;
    QGridLayout* XYZ_l;
    QGridLayout* LAB_l;

    QLabel* RGB_Grad = new QLabel;
    QLabel* CMYK_Grad = new QLabel;
    QLabel* HSV_Grad = new QLabel;
    QLabel* HLS_Grad = new QLabel;
    QLabel* XYZ_Grad = new QLabel;
    QLabel* LAB_Grad = new QLabel;

    QLineEdit* R = new QLineEdit;
    QLineEdit* G = new QLineEdit;
    QLineEdit* B = new QLineEdit;

    QLineEdit* C = new QLineEdit;
    QLineEdit* M = new QLineEdit;
    QLineEdit* Y = new QLineEdit;
    QLineEdit* K = new QLineEdit;

    QLineEdit* HLS_H = new QLineEdit;
    QLineEdit* HLS_L = new QLineEdit;
    QLineEdit* HLS_S = new QLineEdit;

    QLineEdit* XYZ_X = new QLineEdit;
    QLineEdit* XYZ_Y = new QLineEdit;
    QLineEdit* XYZ_Z = new QLineEdit;

    QLineEdit* LAB_L = new QLineEdit;
    QLineEdit* LAB_A = new QLineEdit;
    QLineEdit* LAB_B = new QLineEdit;

    QLineEdit* HSV_H = new QLineEdit;
    QLineEdit* HSV_S = new QLineEdit;
    QLineEdit* HSV_V = new QLineEdit;


    QStringList switch_c {"RGB","CMYK","HSV","HLS","XYZ","LAB"};

};
#endif // WIDGET_H

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
#include "converter.h"
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QValidator>
class Widget : public QWidget
{
    Q_OBJECT

//public signals:
  //  void activated(int,OBject);
private slots:
    void Switch1(int);

    void Switch2(int);

    void Switch3(int);

    void GradientColor();

    void ExitButtonPressed();

    void set_RGB();

    void set_CMYK();

    void set_HSV();

    void set_HLS();

    void set_XYZ();

    void set_LAB();
// sliders
    void set_Slider_HSV();
    void set_Slider_RGB();
    void set_Slider_CMYK();
    void set_Slider_HLS();
    void set_Slider_LAB();
    void set_Slider_XYZ();
public:
    void setAllInfo();
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void installALLinfo();
    void CreatingModels();
    void paintEvent(QPaintEvent*);
    bool eventFilter(QObject *object, QEvent *event);
    void DarkTheme();

    QComboBox* color_switch1;
    QComboBox* color_switch2;
    QComboBox* color_switch3;

    QVBoxLayout* chosenColorl;
    QHBoxLayout* RightL;

    QHBoxLayout* zones;
    QVBoxLayout* main;
    QHBoxLayout* main_;

    QGridLayout* zone1;
    QGridLayout* zone2;
    QGridLayout* zone3;

    QLabel* marker1;
    QLabel* marker2;
    QLabel* marker3;
    QLabel* currentColorLabel =  new QLabel;

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

    QLineEdit* R = new QLineEdit;
    QLineEdit* G = new QLineEdit;
    QLineEdit* B = new QLineEdit;

    QSlider* Rs = new QSlider;
    QSlider* Gs = new QSlider;
    QSlider* Bs = new QSlider;

    QLineEdit* C = new QLineEdit;
    QLineEdit* M = new QLineEdit;
    QLineEdit* Y = new QLineEdit;
    QLineEdit* K = new QLineEdit;

    QSlider* Cs = new QSlider;
    QSlider* Ms = new QSlider;
    QSlider* Ys = new QSlider;
    QSlider* Ks = new QSlider;

    QLineEdit* HLS_H = new QLineEdit;
    QLineEdit* HLS_L = new QLineEdit;
    QLineEdit* HLS_S = new QLineEdit;

    QSlider* Hs1 = new QSlider;
    QSlider* Ls1 = new QSlider;
    QSlider* Ss1 = new QSlider;

    QLineEdit* XYZ_X = new QLineEdit;
    QLineEdit* XYZ_Y = new QLineEdit;
    QLineEdit* XYZ_Z = new QLineEdit;

    QSlider* XXs = new QSlider;
    QSlider* YYs = new QSlider;
    QSlider* ZZs = new QSlider;

    QLineEdit* LAB_L = new QLineEdit;
    QLineEdit* LAB_A = new QLineEdit;
    QLineEdit* LAB_B = new QLineEdit;

    QSlider* LLs = new QSlider;
    QSlider* AAs = new QSlider;
    QSlider* BBs = new QSlider;

    QLineEdit* HSV_H = new QLineEdit;
    QLineEdit* HSV_S = new QLineEdit;
    QLineEdit* HSV_V = new QLineEdit;

    QSlider* HHs = new QSlider;
    QSlider* SSs = new QSlider;
    QSlider* VVs = new QSlider;

    QGroupBox* mas[3];

    QColor base_c = Qt::black;
    QSlider* sliderR = new QSlider;
    QSlider* sliderG = new QSlider;
    QSlider* sliderB = new QSlider;

    QPushButton* exit = new QPushButton;

    converter color;
    QStringList switch_c {"RGB","CMYK","HSV","HLS","XYZ","LAB"};
    QColor currentColor = Qt::black;

};
#endif // WIDGET_H

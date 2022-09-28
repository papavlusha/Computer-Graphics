#include "converter.h"

converter::converter()
{

}

double F_LAB_XYZ(double x) {
    if (pow(x,3)>=0.008856) {
        return pow(x,3);
    }
    return (x-16.0/116.0)/7.878;
}

double F_XYZ_LAB(double x) {
    if (x >= 0.008856) {
        return pow(x, 1.0/3.0);
    }
    return 7.787 * x + 16.0 /(double) 116.0;
}

double F_XYZ_RGB(double x) {
    if (x >= 0.0031308) {
           return 1.055 * pow(x,1.0/2.4) - 0.055;
       }

       return 12.92 * x;
}

double F_RGB_XYZ(double x) {
    if (x >= 0.04045) {
        return pow((x + 0.055)/1.055, 2.4);
    }
    return x / 12.92;
}
void converter::setColorRGB(int r, int g, int b) {
    base4.setRgb(r,g,b);
    base4ToOthers(base4);
}

void converter::setColorCMYK(float c, float m, float y, float k) {
    base4.setCmykF(c,m,y,k);
    base4ToOthers(base4);
}

void converter::setColorHSV(float h, float s, float v) {
    base4.setHsvF(h,s,v);
    base4ToOthers(base4);
}

void converter::setColorHLS(float h, float l, float s) {
    base4.setHslF(h,s,l);
    base4ToOthers(base4);
}

void converter::setColorXYZ(float x, float y, float z) {
       XYZ.first = x;
       XYZ.second = y;
       XYZ.third = z;
       double Rn = 3.2404542 * x - 1.5371385 * y  - 0.4985314 * z;
       double Gn = -0.9692660 * x + 1.8760108 * y  + 0.0415560 * z;
       double Bn = 0.0556434 * x - 0.2040259 * y  + 1.0572252 * z;
       Rn/=100;
       Gn/=100;
       Bn/=100;
       base4.setRed(round(F_XYZ_RGB(Rn)*255));
       base4.setGreen(round(F_XYZ_RGB(Gn)*255));
       base4.setBlue(round(F_XYZ_RGB(Bn)*255));

       LAB.first = 116 * F_XYZ_LAB(x/100.0)-16;
       LAB.second = 500 * (F_XYZ_LAB(x/95.047)-F_XYZ_LAB(y/100.0));
       LAB.third = 200 * (F_XYZ_LAB(y/100.0)- F_XYZ_LAB(z/108.883));

}

void converter::setColorLAB(float l, float a, float b) {
    LAB.first = l;
    LAB.second = a;
    LAB.third = b;
    XYZ.first = F_LAB_XYZ(a/500.0+(l+16.0)/116.0) * 95.047;
    XYZ.second = F_LAB_XYZ((l+16.0)/116.0) * 100.0;
    XYZ.third = F_LAB_XYZ((l+16.0)/116.0-b/200) * 108.883;

    double Rn = 3.2406 * XYZ.first / 100 - 1.5372 * XYZ.second / 100 - 0.4986 * XYZ.third / 100;
    double Gn = -0.9689 * XYZ.first / 100 + 1.8758 * XYZ.second / 100 + 0.0415 * XYZ.third / 100;
    double Bn = 0.0557 * XYZ.first / 100 - 0.2040 * XYZ.second / 100 + 1.0570 * XYZ.third / 100;

    base4.setRed(round(F_XYZ_RGB(Rn)*255));
    base4.setGreen(round(F_XYZ_RGB(Gn)*255));
    base4.setBlue(round(F_XYZ_RGB(Bn)*255));
}

void converter::base4ToOthers(QColor a) {
  base4 = a;
  float Rn,Gn,Bn;
  Rn = F_RGB_XYZ((float)base4.red()/255) * 100;
  Gn = F_RGB_XYZ((float)base4.green()/255) * 100;
  Bn = F_RGB_XYZ((float)base4.blue()/255) * 100;
  XYZ.first = Rn * 0.412453 + Gn * 0.357580 + Bn * 0.180423;
  XYZ.second = Rn * 0.212671 + Gn * 0.715160 + Bn * 0.072169;
  XYZ.third = Rn * 0.019334 + Gn * 0.119193 + Bn * 0.950227;
  setColorXYZ(XYZ.first,XYZ.second,XYZ.third);
}

QColor converter::getColor() const {
    return base4;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include "qcustomplot.h"
#include <QDebug>
#include <algorithm>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    int x,x2;
    QString str;
    x = str.toInt();
    x2 = str.toInt();
    ui->widget->xAxis->setRange(x,x2);
    x = str.toInt();
    x2 = str.toInt();
    ui->widget->yAxis->setRange(x,x2);
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    DarkTheme();
    ui->widget->setInteraction(QCP::iRangeDrag,true);
    ui->widget->setInteraction(QCP::iRangeZoom,true);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::DarkTheme() {
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

void MainWindow::on_draw1_clicked() {
    int x_beg,x_end,y_beg,y_end;
    QString str;
    str = ui->leX->text();
    x_beg = str.toInt();
    str = ui->leXend->text();
    x_end = str.toInt();
    str = ui->leY->text();
    y_beg = str.toInt();
    str = ui->leYend->text();
    y_end = str.toInt();
    double k,b;
    if (x_beg > x_end) {
        std::swap(x_beg,x_end);
        std::swap(y_beg,y_end);
    }
    if(x_end-x_beg == 0) {
        ui->widget->graph(0)->addData(x_beg,y_beg);
        ui->widget->replot();
        ui->widget->graph(0)->addData(x_end,y_end);
        ui->widget->replot();
    } else {
    k=1.0*(y_end-y_beg)/(x_end-x_beg);
    b=y_end-k*x_end;
    X0 = x_beg;
    Y0 = y_beg;
    ui->widget->graph(0)->addData(x_beg,y_beg);
    ui->widget->replot();
    while(x_beg<x_end) {
         x_beg++;
         y_beg=round(k*x_beg+b);
         X0 = x_beg;
         Y0 = y_beg;
         ui->widget->graph(0)->addData(x_beg,y_beg);
         ui->widget->replot();
        }
    }
    ui->widget->replot();
    X0 = 0;
    Y0 = 0;
}


void MainWindow::on_clear1_clicked() {
    ui->widget->graph(0)->data().data()->clear();
    ui->widget->replot();
}


void MainWindow::on_draw2_clicked() {
    int x_beg,x_end,y_beg,y_end;
    QString str;
    str = ui->leX->text();
    x_beg = str.toInt();
    str = ui->leXend->text();
    x_end = str.toInt();
    str = ui->leY->text();
    y_beg = str.toInt();
    str = ui->leYend->text();
    y_end = str.toInt();



    if(abs(y_end-y_beg) > abs(x_end-x_beg))
    {
       std::swap(x_beg,y_beg);
       std::swap(x_end,y_end);
    }
    if (x_beg > x_end)
    {
        std::swap(x_beg,x_end);
        std::swap(y_beg,y_end);
    }
    int Dx=x_end-x_beg;
    int Dy=y_end-y_beg;
    int yi=1;
    if (Dy<0)
    {
        yi=-1;
        Dy=-Dy;
    }
    int D=2*Dy-Dx;
    int y=y_beg;
    for(int x=x_beg;x<=x_end;x++)
    {
        X0 = x;
        Y0 = y;
        ui->widget->graph(1)->addData(x,y);
        ui->widget->replot();
        if(D>0)
        {
            y+=yi;
            D+=2*(Dy-Dx);
        }
        else
            D+=2*Dy;
    }


}


void MainWindow::on_clear2_clicked() {
    ui->widget->graph(1)->data().data()->clear();
    ui->widget->replot();
}


void MainWindow::on_draw3_clicked() {
    int x_beg,x_end,y_beg,y_end;
    QString str;
    str = ui->leX->text();
    x_beg = str.toInt();
    str = ui->leXend->text();
    x_end = str.toInt();
    str = ui->leY->text();
    y_beg = str.toInt();
    str = ui->leYend->text();
    y_end = str.toInt();
    int dx = x_end - x_beg;
    int dy = y_end - y_beg;
    int step;
    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
     float x_incr = (float)dx / step;
     float y_incr = (float)dy / step;
     float x = x_beg;
     float y = y_beg;
     for (int i = 0; i <= step; i++) {
         ui->widget->graph(2)->addData(x,y);
         ui->widget->replot();
         x += x_incr;
         y += y_incr;
     }
}


void MainWindow::on_clear3_clicked() {
    ui->widget->graph(2)->data().data()->clear();
    ui->widget->replot();
}


void MainWindow::on_draw4_clicked() {
    int xm=0,ym=0,r=3;
    QString str;
    str = ui->lecx->text();
    xm = str.toInt();
    str = ui->lecy->text();
    ym = str.toInt();
    str = ui->leR->text();
    r = str.toInt();
    int x = -r, y = 0, err = 2-2*r;
while (x < 0) {
    r = err;
    if (r <= y)
        err += ++y*2+1;
    if (r > x || err > y)
        err += ++x*2+1;
        ui->widget->graph(3)->addData(xm+x, ym-y);
        ui->widget->replot();
        ui->widget->graph(4)->addData(xm+y, ym-x);
        ui->widget->replot();
        ui->widget->graph(5)->addData(xm+y, ym+x);
        ui->widget->replot();
        ui->widget->graph(7)->addData(xm-x, ym-y);
        ui->widget->replot();
        ui->widget->graph(6)->addData(xm+x, ym+y);
        ui->widget->replot();
        ui->widget->graph(8)->addData(xm-y, ym-x);
        ui->widget->replot();
        ui->widget->graph(9)->addData(xm-y, ym+x);
        ui->widget->replot();
        ui->widget->graph(10)->addData(xm-x, ym+y);
        ui->widget->replot();
    }
}


void MainWindow::on_clear4_clicked() {
    ui->widget->graph(3)->data().data()->clear();
    ui->widget->graph(4)->data().data()->clear();
    ui->widget->graph(5)->data().data()->clear();
    ui->widget->graph(6)->data().data()->clear();
    ui->widget->graph(7)->data().data()->clear();
    ui->widget->graph(8)->data().data()->clear();
    ui->widget->graph(9)->data().data()->clear();
    ui->widget->graph(10)->data().data()->clear();
    ui->widget->replot();
}


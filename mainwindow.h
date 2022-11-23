#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QColor Sequential = Qt::black,Bresenham = Qt::black,DDA = Qt::black,Bresenham_Circle = Qt::black,Castle_Pitway = Qt::black;
    void DarkTheme();
    int X0 = 0,Y0 = 0;
private slots:
    void on_draw1_clicked();

    void on_clear1_clicked();

    void on_draw2_clicked();

    void on_clear2_clicked();

    void on_draw3_clicked();

    void on_clear3_clicked();

    void on_draw4_clicked();

    void on_clear4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

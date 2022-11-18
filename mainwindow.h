#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDir>
#include <QImageReader>
#include <QStatusBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
struct visual_file
{
    QString Name;
    QString Type;
    QString Size;
    int Hresolution;
    int Vresolution;
    short Depth;
    short Compressing;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFileDirectory();
    void openFileDirectoryLE();
    void openArchive();
private:
    QTableWidget* tw = new QTableWidget(this);
    QString getFileSize(QImage);
    void fillTheTable();
    void settings();
    void fillFromDirectory(QString);
    QStringList suffixses;
    QString dirPath;
    QString archive;
    QTableWidgetItem *item = new QTableWidgetItem;
    QPushButton* pbDir = new QPushButton(this);
    QPushButton* pbArch = new QPushButton(this);
    QLineEdit* leDir = new QLineEdit(this);
    QStatusBar* statusbar = new QStatusBar(this);
    Ui::MainWindow *ui;
    QVector <visual_file> data_base;
};


#endif // MAINWINDOW_H

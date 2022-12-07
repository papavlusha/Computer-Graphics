#include "mainwindow.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QHeaderView>
#include <cmath>
#include <QImageWriter>
#include <qzipreader_p.h>
#include <qzipwriter_p.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    suffixses <<"png"<<"jpg"<< "gif" << "tif" << "bmp" << "pcx";

    this->setStatusBar(statusbar);
    settings();

    qApp->installEventFilter(this);
    connect (this->pbDir,SIGNAL(clicked()),SLOT(openFileDirectory()));
    connect (this->pbArch,SIGNAL(clicked()),SLOT(openArchive()));
    connect (this->leDir,SIGNAL(editingFinished()),SLOT(openFileDirectoryLE()));
    connect(pbOne,SIGNAL(clicked()),SLOT(openOne()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::settings()
{
    QWidget* window = new QWidget();
    this->setCentralWidget(window);
    this->setFixedWidth(922);
    QStringList str;
    str << "Имя файла" << "Расширение" << "Размер изображения" << "Горизонтальное азрешение (dot/inch)" << "Вериткальное азрешение (dot/inch)" << "Глубина цвета" <<"Сжатие";
    this->tw->setColumnCount(7);
    this->tw->setColumnWidth(0,100);
    this->tw->setHorizontalHeaderLabels(str);
    this->tw->verticalHeader()->hide();
    this->tw->setSortingEnabled(true);
    this->tw -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tw -> setSelectionMode(QAbstractItemView::NoSelection);
    this->tw->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->tw->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
    this->tw->resizeColumnsToContents();
    this->tw->setContextMenuPolicy(Qt::CustomContextMenu);
    this->pbDir->setText("Выберите папку");
    this->pbArch->setText("Выберите архив");
    QGridLayout* box = new QGridLayout;
    box->setAlignment(Qt::AlignLeft);
    pbOne->setText("Выбрать картинку");
    box->addWidget(pbOne,0,0);
    box->addWidget(this->pbArch,0,1);
    box->addWidget(this->pbDir,0,2);
    box->addWidget(this->leDir,0,3);
    box->addWidget(this->tw,1,0,1,4);
    window->setLayout(box);
}

void MainWindow::openFileDirectory()
{
    QFileDialog* d = new QFileDialog(this);
    dirPath = d->getExistingDirectory();
    fillFromDirectory(dirPath);
}

void MainWindow::openFileDirectoryLE()
{
    dirPath = this->leDir->text();
    fillFromDirectory(dirPath);
}

void MainWindow::openArchive()
{
    QString fileName = QFileDialog ::getOpenFileName(this, tr("open an archive."),"D:/",tr("zip(*zip)"));
    QFileInfo fileinfo(fileName);
    archive = fileinfo.path();
    QZipReader zipReader(fileName);
    bool check = false;
    if (zipReader.exists()) {
        foreach (QZipReader::FileInfo info, zipReader.fileInfoList()) {
           for (int i=0;i<this->suffixses.size();i++)
           {
               if(info.filePath.contains(suffixses[i]))
               {
                   check = true;
                   break;
               }
           }
           if(check)
           {
               break;
           }
        }
        archive=archive+"/temporaty_folder";
        QDir dir(archive);
        if (!dir.exists())
            dir.mkpath(archive);
        if(check)
        {
            zipReader.extractAll(archive);
            fillFromDirectory(archive);
        }
         dir.removeRecursively();
    }
}

void MainWindow::openOne() {
    QFileDialog* dial = new QFileDialog(this);
    QString path = dial->getOpenFileName(this,tr("Выберите файл"),"/",tr("img(*.png *.jpg *.tif *.gif *.bmp *.pcx)"));
    QFile file(path);
    QImage img;
    QFileInfo inf;
    QImageWriter g(dirPath);
    this->leDir->setText(dirPath);
    this->data_base.clear();
        visual_file tmp;
        inf.setFile(path);
        img.load(path);
        tmp.Name = inf.fileName();
        tmp.Type = inf.suffix();
        tmp.Size = getFileSize(img);
        int q = tmp.Name.size()-1;
        while (tmp.Name[q] != '.') {
            q--;
        }
        tmp.Name.remove(q,tmp.Name.size() - q);
        if (ceil(img.dotsPerMeterX()/39.37) - img.dotsPerMeterX()/39.37 >= 0.1) {
            tmp.Hresolution = floor(img.dotsPerMeterX()/39.37);
        } else {
            tmp.Hresolution = ceil(img.dotsPerMeterX()/39.37);
        }
        if (ceil(img.dotsPerMeterY()/39.37) - img.dotsPerMeterY()/39.37 >= 0.1) {
            tmp.Vresolution = floor(img.dotsPerMeterY()/39.37);
        } else {
            tmp.Vresolution = ceil(img.dotsPerMeterY()/39.37);
        }
        tmp.Depth = img.bitPlaneCount();
        tmp.Compressing = g.compression();
        this->data_base.push_back(tmp);
    fillTheTable();
}

void MainWindow::fillFromDirectory(QString dirPath) {
    QDir directory(dirPath);
    if(directory.exists()) {
        QFileInfoList dirContent = directory.entryInfoList(QStringList()
                                          << "*.png" <<"*.jpg"<<"*.tif"<<"*.gif"<<"*.bmp"<<"*.pcx",QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
        QImage img;
        QFileInfo inf;
        QImageWriter g(dirPath);
        this->leDir->setText(dirPath);
        this->data_base.clear();
        for (int i = 0; i < dirContent.size(); i++) {
            visual_file tmp;
            inf.setFile(dirContent[i].path() + "/" + dirContent[i].fileName());
            img.load(dirContent[i].path() + "/" + dirContent[i].fileName());
            tmp.Name = inf.fileName();
            tmp.Type = inf.suffix();
            tmp.Size = getFileSize(img);
            int q = tmp.Name.size()-1;
            while (tmp.Name[q] != '.') {
                q--;
            }
            tmp.Name.remove(q,tmp.Name.size() - q);
            if (ceil(img.dotsPerMeterX()/39.37) - img.dotsPerMeterX()/39.37 >= 0.1) {
                tmp.Hresolution = floor(img.dotsPerMeterX()/39.37);
            } else {
                tmp.Hresolution = ceil(img.dotsPerMeterX()/39.37);
            }
            if (ceil(img.dotsPerMeterY()/39.37) - img.dotsPerMeterY()/39.37 >= 0.1) {
                tmp.Vresolution = floor(img.dotsPerMeterY()/39.37);
            } else {
                tmp.Vresolution = ceil(img.dotsPerMeterY()/39.37);
            }
            tmp.Depth = img.bitPlaneCount();
            tmp.Compressing = g.compression();
            this->data_base.push_back(tmp);
        }
        fillTheTable();
    }
}

void MainWindow::fillTheTable() {
    this->tw->setRowCount(0);
    for(int i = 0; i < data_base.size(); i++) {
        this->tw->insertRow(i);
        item->setText(data_base[i].Name);
        this->tw->setItem(i,0,new QTableWidgetItem(*item));
        item->setText(data_base[i].Type);
        this->tw->setItem(i,1,new QTableWidgetItem(*item));
        item->setText(data_base[i].Size);
        this->tw->setItem(i,2,new QTableWidgetItem(*item));
        item->setText(QString::number(data_base[i].Hresolution));
        this->tw->setItem(i,3,new QTableWidgetItem(*item));
        item->setText(QString::number(data_base[i].Vresolution));
        this->tw->setItem(i,4,new QTableWidgetItem(*item));
        item->setText(QString::number(data_base[i].Depth));
        this->tw->setItem(i,5,new QTableWidgetItem(*item));
        item->setText(QString::number(data_base[i].Compressing));
        this->tw->setItem(i,6,new QTableWidgetItem(*item));
    }
    this->tw->sortByColumn(0,Qt::AscendingOrder);
}

QString MainWindow::getFileSize(QImage img) {
    QSize size_of_img = img.size();
    QString result = QString::number(size_of_img.width())+" x "+QString::number(size_of_img.height());
    return result;
}


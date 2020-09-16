#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QStandardItemModel>
#include <iostream>
#include <fstream>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("path");
    ui->lineEdit_2->setText("Palabra a buscar");
    miArchivo = new archivo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setArchivo(archivo * ar)
{
    miArchivo=ar;
}

archivo MainWindow::getArchivo() const
{
    return *miArchivo;

}

const char *MainWindow::viewPath()
{
    QString path = this->ui->lineEdit->text();
    QString  pal = this->ui->lineEdit_2->text();
    QString pathComplete = path ;
    const char *  a = path.toStdString().c_str();
    return a;
}





void MainWindow::on_commandLinkButton_clicked()
{
    QDir directory(this->ui->lineEdit->text());
    QStringList files = directory.entryList(QStringList() << "*.txt",QDir::Files);
    QStandardItemModel * model = new QStandardItemModel();
    QString path = this->ui->lineEdit->text();

    QString  pal = this->ui->lineEdit_2->text();
    int m;
    const char * cadena;
    cadena = pal.toStdString().c_str();
    float a;
    int i = 0;
    int h=0;

    model->setColumnCount(4);

    model->setHorizontalHeaderItem(0, new QStandardItem("nombre del archivo"));
    model->setHorizontalHeaderItem(1, new QStandardItem("path de busqueda"));
    model->setHorizontalHeaderItem(2, new QStandardItem("total de palabra buscada"));
    model->setHorizontalHeaderItem(3, new QStandardItem("cantidad total de palabras"));



    bool j=false;
    QString pathComplete;
    if(this->miArchivo->verificaPalabra(pal.toStdString().c_str()))
    {
        foreach(QString filename, files) {
            QStandardItem * item = new QStandardItem(filename);
            pathComplete = path + "/" + filename;
            if(this->miArchivo->buscarPalabra(cadena, pathComplete.toStdString().c_str()))
            {
                model->setItem(i, 0, item);

                QStandardItem * a = new QStandardItem(pathComplete.toStdString().c_str());
                model->setItem(i, 1, a);

                m=this->miArchivo->cuentapalabras(cadena, pathComplete.toStdString().c_str());
                QStandardItem * a2 = new QStandardItem(QString::number(m));
                model->setItem(i, 2, a2);

                h=this->miArchivo->cantidadtotalpalabras(pathComplete.toStdString().c_str());

                QStandardItem * a3 = new QStandardItem(QString::number(h));

                model->setItem(i, 3, a3);

                i++;
                j=false;
            }
            model->sort(2, Qt::SortOrder(i));

        }
    }

     this->ui->tableView->setModel(model);

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QVariant item = this->ui->tableView->model()->data(index);
    QString filename = this->ui->lineEdit->text() + "/" + item.toString();
    std::ifstream archivo;

    archivo.open (filename.toStdString().c_str());
    std::string line;
    std::string totalline="";
    if (archivo.is_open())
    {
        while ( getline (archivo,line) )
        {
              totalline = totalline + line + '\n';
        }
        this->ui->textEdit->setText(QString(totalline.c_str()));
    }
    archivo.close();
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{

}

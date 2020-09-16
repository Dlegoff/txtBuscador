#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "archivo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setArchivo(archivo * ar);
    archivo getArchivo() const;
    const char * viewPath();

private slots:
    void on_commandLinkButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    friend class archivo;
    //friend class Form;
    archivo * miArchivo;
};
#endif // MAINWINDOW_H

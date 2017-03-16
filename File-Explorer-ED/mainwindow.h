#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QAbstractButton>
#include <QPushButton>
#include <QString>
#include <QInputDialog>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QGraphicsProxyWidget>
#include <QList>
#include <QTreeView>
#include <iostream>
#include "fsu.h"
#include "treemodel.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int posxFolder, posYFolder, posxLabel, posYLabel,cantFolders,cantFiles,cantTotFolders,cantTotFiles;
    string path;

    FSU * api;
    Folder * inicial;
    Folder * actual;

    QList<QPushButton*> botones;
    QList<QLabel*> labels;
    QTreeView * view;

    void escribir();
    string getNombre();
    void openFile();
    void read();
    void wipe();
    void refresh();
    void eliminar();
    void addArchivo(string nom);
    void addFolder(string nom);
    void copyFile();
    void copyFolder();
    void label(string nom);

    void menu();
    void actions();


private slots:
    void on_btNuevo_clicked();
   /* void clickBotones();*/

    void prueba();
    void openFolder();
    QString askName();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

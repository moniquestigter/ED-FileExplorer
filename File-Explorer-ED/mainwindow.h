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
#include <QTreeWidgetItem>
#include <iostream>
#include "fsu.h"
#include "treemodel.h"
#include "treeitem.h"

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
    Archivo * tempCopied;

    QList<QPushButton*> botones;
    QList<QLabel*> labels;
    QTreeWidget * view;

    void escribir();
    string getNombre();
    void openFile();
    void read();
    void wipe();
    void refresh();
    void eliminar();
    void addArchivo(string nom);
    void addFolder(string nom);
    void copy();
    void label(string nom);

    void menu();
    void actions();


private slots:
    void on_btNuevo_clicked();
   /* void clickBotones();*/

    void prueba();
    void openFolder();
    QString askName();


    void on_btPegar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

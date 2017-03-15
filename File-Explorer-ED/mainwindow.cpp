#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QEvent>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    botones = QList<QPushButton*>();
    labels = QList<QLabel*>();
    ui->vistaPath->setText("root/");
    inicial = new Folder("root","root/");
    api = new FSU();
    actual = inicial;
    path = actual->getPath();
    view = ui->treeView;

    posxFolder = posxLabel = 320;
    posYFolder = posYLabel = 170;
    cantFiles = cantFolders = 0;
    cantTotFiles = cantTotFolders = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getPos(){
    QPushButton * temp = qobject_cast<QPushButton *>(sender());
      if(temp!=NULL){
        for(int a = 0; a < botones.length(); a++){
            if(botones.at(a) == temp)
                   return a;
           }
       }
       return -1;
}

void MainWindow::addFolder(string nom){
    QPushButton * folder = new QPushButton(this);

    folder->setStyleSheet("border-image:url(:/new/prefix1/folder.png);");
    folder->setGeometry(posxFolder,posYFolder,75,80);
    botones.insert(cantTotFolders,folder);
    TreeModel * model = new TreeModel(QString::fromStdString(nom));

    posxFolder+=100;
    posxLabel = posxFolder;
    if(posxFolder>=1120){
        posxFolder = 320;
        posYFolder+= 90;
        posxLabel = posxFolder;
        posYLabel+=90;
    }
    folder->show();
    view->setModel(model);
    view->show();
    connect(botones.at(cantTotFolders), SIGNAL (released()),this, SLOT(openFolder()));
    cantTotFolders++;

}

void MainWindow::addArchivo(string nom){
    QPushButton * file = new QPushButton(this);
    file->setStyleSheet("border-image:url(:/new/prefix1/file.png);");
    file->setGeometry(posxFolder,posYFolder,75,80);
    botones.insert(cantTotFiles,file);
    TreeModel * model = new TreeModel(QString::fromStdString(nom));

    posxFolder+=100;
    posxLabel = posxFolder;
    if(posxFolder>=1120){
        posxFolder = 320;
        posYFolder+= 90;
        posxLabel = posxFolder;
        posYLabel+=90;
    }
    view->setModel(model);
    view->show();
    file->show();
    connect(botones.at(cantTotFiles), SIGNAL (released()),this, SLOT(prueba()));
    cantTotFiles++;
}

void MainWindow::on_btNuevo_clicked()
{
    QMessageBox nuevoMsgBox;
    QAbstractButton *folderBt = nuevoMsgBox.addButton(tr("Folder"),QMessageBox::YesRole);
    QAbstractButton* fileBt = nuevoMsgBox.addButton(tr("File"),QMessageBox::YesRole);
    QAbstractButton * cancelBt = nuevoMsgBox.addButton(tr("Cancelar"),QMessageBox::NoRole);
    nuevoMsgBox.exec();

    if(nuevoMsgBox.clickedButton() == folderBt){
        QLabel * nom = new QLabel(this);
        nom->setGeometry(posxLabel,posYLabel+40,75,85);
        QString name = QInputDialog::getText(this,"Nuevo ","Ingrese el Nombre:");
        if(name == ""){
            string def = "Folder" + std::to_string(cantFolders++);
            nom->setText(def.c_str());
            addFolder(def);
            api->crearArchivo(actual,def,"Folder");
        }
        else{
            nom->setText(name);
            addFolder(name.toStdString());
            api->crearArchivo(actual,name.toStdString(),"Folder");
        }
        labels.append(nom);
        nom->show();

    }
    else if(nuevoMsgBox.clickedButton() == fileBt){
        QLabel * nom = new QLabel(this);
        nom->setGeometry(posxLabel,posYLabel+40,75,85);
        QString name = QInputDialog::getText(this,"Nuevo ","Ingrese el Nombre:");
        if(name == ""){
            string def = "Archivo" + std::to_string(cantFiles++);
            string nomCompleto = def + ".txt";
            nom->setText(nomCompleto.c_str());
            addArchivo(nomCompleto);
            api->crearArchivo(actual,nomCompleto,"Archivo");
        }
        else {
            string nomCompleto = name.toStdString() + ".txt";
            nom->setText(nomCompleto.c_str());
            addArchivo(nomCompleto);
            api->crearArchivo(actual,nomCompleto,"Archivo");
        }

        labels.append(nom);
        QInputDialog * contenido = new QInputDialog();
        nom->show();
    }
    else if(nuevoMsgBox.clickedButton() == cancelBt){
        nuevoMsgBox.close();
    }
}

void MainWindow::escribir(){
    Archivo * temp = api->cargarArchivo(getPos(),actual);
    ArchivoText * file = reinterpret_cast<ArchivoText*>(temp);
    QString cont = QInputDialog::getText(this,tr(file->nombre.c_str()),tr("Escriba su texto: "));
    file->setContenido(cont.toStdString());
}

void MainWindow::wipe(){
    for(int a = 0; a < botones.size(); a++){
        botones.at(a)->close();
        labels.at(a)->close();
    }
    for(int a = 0; a<botones.size(); a++){
        botones.removeAt(a);
        labels.removeAt(a);
    }
    posxFolder = posxLabel = 320;
    posYFolder = posYLabel = 170;
    cantFiles = cantFolders = 0;
    cantTotFiles = cantTotFolders = 0;
}

void MainWindow::eliminar(){
    api->eliminarArchivo(getPos(),actual);
    refresh();
}

void MainWindow::prueba(){
    QMessageBox msgBox;
    QAbstractButton * openBt = msgBox.addButton(tr("Abrir"), QMessageBox::YesRole);
    QAbstractButton * editBt = msgBox.addButton(tr("Editar"), QMessageBox::YesRole);
    QAbstractButton * copyBt = msgBox.addButton(tr("Copiar"), QMessageBox::YesRole);
    QAbstractButton * eliminarBt = msgBox.addButton(tr("Eliminar"), QMessageBox::YesRole);
    QAbstractButton * cancelBt = msgBox.addButton(tr("Cancelar"),QMessageBox::NoRole);
    msgBox.exec();

    if(msgBox.clickedButton() == openBt)
        read();
    else if(msgBox.clickedButton()==editBt)
        escribir();
    else if(msgBox.clickedButton()==copyBt)
        msgBox.close();
    else if(msgBox.clickedButton()==eliminarBt)
        eliminar();
    else if(msgBox.clickedButton()==cancelBt)
        msgBox.close();
}

void MainWindow::refresh(){
    wipe();
    QList <Archivo*> temp = api->listarArchivos(actual);
    for(int a = 0; a < actual->cant; a++){
        if(temp.at(a)->tipo == "Folder"){
            addFolder(temp.at(a)->nombre);
        }
        else{
             addArchivo(temp.at(a)->nombre);
        }
    }
}

void MainWindow::openFolder(){
    QMessageBox msgBox;
    QAbstractButton * openBt = msgBox.addButton(tr("Abrir"), QMessageBox::YesRole);
    QAbstractButton * eliminarBt = msgBox.addButton(tr("Eliminar"), QMessageBox::YesRole);
     QAbstractButton * copyBt = msgBox.addButton(tr("Copiar"), QMessageBox::YesRole);
    QAbstractButton * cancelBt = msgBox.addButton(tr("Cancelar"),QMessageBox::NoRole);
    msgBox.exec();
       if(msgBox.clickedButton()==openBt){
            Archivo * temp = api->cargarArchivo(getPos(),actual);
            Folder * nuevoActual = reinterpret_cast<Folder*>(temp);
            actual = nuevoActual;
            refresh();
            string p = actual->nombre + "/";
            path = path+p;
            ui->vistaPath->setText(path.c_str());
       }
       else if(msgBox.clickedButton()==eliminarBt)
           eliminar();
       else if(msgBox.clickedButton() == copyBt)
           msgBox.close();
       else if(msgBox.clickedButton()==cancelBt)
           msgBox.close();
}

void MainWindow::read(){
    QMessageBox msgBox;
    Archivo * temp = api->cargarArchivo(getPos(),actual);
    ArchivoText * file = reinterpret_cast<ArchivoText*>(temp);
    string text = file->contenido;
    msgBox.setText(text.c_str());
    msgBox.exec();
}

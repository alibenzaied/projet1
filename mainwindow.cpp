#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableRec->setModel(tmpr.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAjouter_clicked()
{
    int id=ui->ID->text().toInt();
    QString type=ui->TYPE->text();
    QString date=ui->DATE->text();
    QString description=ui->DESCRIPTION->toPlainText();
    reclamation r(id,type,date,description);
    bool test=r.ajouter();
    if(test)
    { ui->tableRec->setModel(tmpr.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter reclamation"),
                               QObject::tr("reclamation ajouté"),QMessageBox::Ok);

    }else
        QMessageBox::critical(nullptr,QObject::tr("Ajouter reclamation"),
                                      QObject::tr("reclamation non ajouté"),QMessageBox::Ok);
}


void MainWindow::on_Supprimer_clicked()
{
    int row =ui->tableRec->selectionModel()->currentIndex().row();
           int id=ui->tableRec->model()->index(row,0).data().toInt();
           tmpr.supprimer(id);
            ui->tableRec->setModel(tmpr.afficher());
}


void MainWindow::on_Modifier_clicked()
{
    int id=ui->ID->text().toInt();
    QString type=ui->TYPE->text();
    QString date=ui->DATE->text();
    QString description=ui->DESCRIPTION->toPlainText();
    reclamation r(id,type,date,description);
    bool test=r.modifier(id);
    if(test)
    { ui->tableRec->setModel(tmpr.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modifier reclamation"),
                               QObject::tr("reclamation modifié"),QMessageBox::Ok);

    }else
        QMessageBox::critical(nullptr,QObject::tr("Modifier reclamation"),
                                      QObject::tr("reclamation non modifié"),QMessageBox::Ok);
}


void MainWindow::on_Recuperer_clicked()
{
    int row =ui->tableRec->selectionModel()->currentIndex().row();
           QString id=ui->tableRec->model()->index(row,0).data().toString();
           QSqlQuery q("select * from reclamation where id="+id);


            while(q.next())
            {
                ui->tabWidget->setCurrentIndex(0);
                ui->ID->setText(q.value(0).toString());
                 ui->TYPE->setText(q.value(1).toString());
                   ui->DESCRIPTION->setPlainText(q.value(3).toString());

            }
}


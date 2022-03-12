#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reclamation.h"
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

private slots:
    void on_btnAjouter_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_Recuperer_clicked();

private:
    Ui::MainWindow *ui;
    reclamation tmpr;
};
#endif // MAINWINDOW_H

#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reclamation
{
public:
    reclamation();
    reclamation(int,QString,QString,QString);
    bool rech(int a);
    int id;
    QString date,type,description;
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel * afficher();
};

#endif // RECLAMATION_H

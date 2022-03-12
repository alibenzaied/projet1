#include "reclamation.h"

reclamation::reclamation()
{

}
reclamation::reclamation(int id,QString type,QString date,QString description)
{
    this->id=id;
    this->type=type;
    this->date=date;
    this->description=description;
}
bool reclamation::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO reclamation VALUES(:id,:type,:date,:description)");
     query.bindValue(":id",id);
     query.bindValue(":type",type);
     query.bindValue(":date",date);
     query.bindValue(":description",description);
    return query.exec();
}
bool reclamation::modifier(int id)
{
    QSqlQuery query;

    query.prepare("update reclamation set type=:type,date_rec=:date,descrition=:description where id=:id");
     query.bindValue(":id",id);
     query.bindValue(":type",type);
     query.bindValue(":date",date);
     query.bindValue(":description",description);
    return query.exec();
}
bool reclamation::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("delete from reclamation where id=:id");
     query.bindValue(":id",id);
    return query.exec();
}
QSqlQueryModel *reclamation::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from reclamation");
    return model;
}

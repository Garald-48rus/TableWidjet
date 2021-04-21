#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QTableWidgetItem>
#include "apple.h"

class Db
{
public:
    Db();
   ~Db();

private:
    QSqlDatabase db;
    QSqlQuery* qerly;

public:
  void setDb(QList<QTableWidgetItem*>);//функция добавления данных в базу

};

#endif // DB_H

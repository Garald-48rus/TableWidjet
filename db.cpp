#include "db.h"
#include <QtDebug>

Db::Db()
{
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("../Task2/data/task");
  db.open();

  if(db.isOpen()){
    qerly = new QSqlQuery(db);
    qDebug() << "oppen";
}
  else {
      qDebug() << "no oppen";
  }

}
//====================================
Db::~Db(){
    delete qerly;
}
//======================================
void Db::setDb(QList<QTableWidgetItem*> objInfo ){

   if(db.open()){
   //предварительно очищаю таблицы
   qerly->exec("DELETE FROM 'Inventory'");
   qerly->exec("DELETE FROM 'Object'");

   qerly->prepare("INSERT INTO 'Inventory' (cell, type, col) VALUES (?, ?, ?)");
        //добавляю данные в таблицу инвентаря
       for(auto &itr: objInfo){

           QString cell = QString::number(itr->row()) + ',' + QString::number(itr->column());
           qerly->addBindValue(cell);//ячейка
           qerly->addBindValue(itr->type());//тип
           qerly->addBindValue(itr->text().toInt());//количество объектов в ячейке
           qerly->exec();

       }

     qerly->prepare("INSERT INTO 'Object' (type, cell) VALUES (?, ?)");
      //добавляю данные в таблицу элемент
      for(auto &itr: objInfo){

         QString cell = QString::number(itr->row()) + ',' + QString::number(itr->column());
         QString type{};
         if(itr->type() == Apple::getType()){
             type = "Apple";
         }

         qerly->addBindValue(type);//тип объекта (название)
         qerly->addBindValue(cell);//ячека
         qerly->exec();
      }

   }

   db.close();//закрываю базу
}

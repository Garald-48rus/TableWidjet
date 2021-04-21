#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QtWidgets>
#include <QList>
#include "apple.h"
#include "sound.h"
#include "db.h"


class Inventory: public QTableWidget
{
    Q_OBJECT
public:
    Inventory(QWidget * parent = 0);
    ~Inventory();
private:
    const int CELL{9};//кол. ячеек
    QList<QTableWidgetItem*> objinfo;//контейнер хранящий элементы в таблице
    QString endl{"\n\n\n\n\n\n\n\n\n\n"};//переменная для отображения кол. элементов в ячейке(в нижнем углу)
    QTableWidgetItem * mItem{nullptr};//указатель для промежуточных данных

    Sound mSound;//объект класса звук
    Db mDb;//обект базы данных

private:
    void mousePressEvent(QMouseEvent *event) override;//переопределяю функцию нажатия кнопок миши
    void dropEvent(QDropEvent *event) override;//переопределяю функцию перемещения объектов по таблице

public slots:
    void setmItem(QTableWidgetItem *);//слот для иницилизации переменной промежуточных объектов
};

#endif // INVENTORY_H

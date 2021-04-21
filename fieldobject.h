#ifndef FIELDOBJECT_H
#define FIELDOBJECT_H
#include <QObject>
#include <QtWidgets>
#include "apple.h"

class FieldObject: public QTableWidget//класс таблицы объекта
{

public:
    FieldObject(QWidget * parent = 0);

private:
    QTableWidgetItem *thumbnail{nullptr};//указатель на элемент для использования с таблицей


};

#endif // FIELDOBJECT_H

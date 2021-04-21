#include "fieldobject.h"
#include <QPixmap>

FieldObject::FieldObject(QWidget *parent):
    QTableWidget (parent)
{
    //иницилизация таблицы
    setColumnCount(1);//кол. колонок
    setRowCount(1);//кол. строк
    setColumnWidth(0,150);//размер колонки
    setRowHeight(0,150);//размер строки
    setDragDropMode(QAbstractItemView::DragOnly);//иницилизация перемещения объекта из таблицы(вставить нельзя)

    QImage imageName = *new QImage(Apple::getPatch());//в обект изображения передаю нашу картику

   thumbnail = new QTableWidgetItem(Apple::getType());//иницилизирую элемент работы с таблицей типом нашего объекта
   thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(imageName));//Устанавливаю данные элемента для данной роли

   setItem(0,0,thumbnail);//иницилизирую я чейку таблицы элементом с данными

   //
}
//================================================


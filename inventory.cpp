#include "inventory.h"
#include <QDebug>

Inventory::Inventory(QWidget *parent):
    QTableWidget (parent)
{ //иницилизация таблици инвентарь
   setColumnCount(CELL/3);//устанока колличества  колонок
   setRowCount(CELL/3);//установка количества строк
   for(int i = 0; i< CELL/3; i++){
      setRowHeight(i,180);//установка размера строк
      setColumnWidth(i,180);//установка размера колонок
  }
   setDragDropMode(QAbstractItemView::DragDrop);//включаю возможность переноса элементов в таблице

}
//==========================================================================
Inventory::~Inventory(){

};
//=====================================================================
void Inventory::mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::RightButton){
       //если нажата правая кнопка
         mItem = itemAt(event->pos());//иницилизирую обектом на котором была нажаата кнопка
     //если объект не пустой
     if(mItem){
         auto it = qFind(objinfo.begin(), objinfo.end(), mItem);//ищу этот объект в контейнере
         int tmp = mItem->text().toInt() -1; //передаю временной переменной значение кол. елементов в ячейке и уменьшаю на 1
          //если елементов осталось болше 0
         if(tmp > 0){
         //прохожу циклом по контейнеру хранящему все елементы таблици
         for(auto &itr: objinfo){
             //нахожу нужный елемент
             if(itr == mItem){
                 //меняю кол. елементов
                itr->setText(QString::number(tmp));
                //вывожу новое кол. элементов в таблицу
               mItem->setText(endl+QString::number(tmp));
               break;
             }
         }

         }
         //если кол элементо равно 0
         else {
            //удаляю этот элемент из контейнера
            objinfo.erase(it);
            //онуляю ячейку в таблице
             setItem(rowAt(event->pos().ry()),
                         columnAt(event->pos().rx()),nullptr);
         }
             //проигрываю звук
             mSound.play();

     }
          mItem = nullptr;//обнуляю переменную хранящую временные объект

          mDb.setDb(objinfo);//обновляю базу даных

    }
      //если нажата левая кнопка
     if(event->button() == Qt::LeftButton){

         //соединяю сигнал нажатия кнопки на элементе в ячейке со слотом иницилизации указателя временых элементов
         QObject::connect(this, &QTableWidget::itemPressed, this, &Inventory::setmItem);
     }

      //пробрасываю событие
     QTableWidget::mousePressEvent(event);
}
//=====================================================================

void Inventory::dropEvent(QDropEvent *event){
    //создаю указатель на элемент в ячейке в которую помещен новый элемент
    QTableWidgetItem * targetItem = itemAt(event->pos());

      // проверяем что источник - родная таблица
    if (event->source()!= this) {

      // QTableWidget::dropEvent(event);

       // неродной источник и ячейка пуста
       if(!targetItem){
           //конструирую в ячейке новый элемент нашего яблока
           QImage imageName = *new QImage(Apple::getPatch());
           targetItem = new QTableWidgetItem(Apple::getType());
           targetItem->setData(Qt::DecorationRole, QPixmap::fromImage(imageName));
           targetItem->setText(endl+"1");//добавляю кол элементов 1
           setItem(rowAt(event->pos().ry()), columnAt(event->pos().rx()), targetItem);//отабражаю в таблице

           objinfo.append(targetItem);//добавляю новый элемент в контейнер
           }
              // неродной источник и ячейка не пуста
         else {
              int tmp = targetItem->text().toInt() + 1;//во временную переменную сохраняю кол. элементов в ячеке и прибавляю 1 эл.
              for(auto &itr: objinfo){
                  //нахожу это изменненый элемент в контейнере
                  if(itr == targetItem){
                      //меняю кол.
                  itr->setText(QString::number(tmp));
                  //отабражаю изменения в таблице
                  targetItem->setText(endl+QString::number(tmp));
                  break;
              }

              }
           }

        }

        //если источник наша таблица
        if(event->source() == this){

         //если ячейка не пуста
        if(targetItem){
          //проверяю перемещаяемый объект
          if(mItem){
              //нахожу перемещенный объект к нотейнере(итератор)
           auto it = qFind(objinfo.begin(), objinfo.end(), mItem);
           //сохраняю кол. элементов в перемещаемом объекте(ячейке)
           int tmp = mItem->text().toInt();
           for (auto &itr: objinfo) {
               //нахожу элемент который меняем
               if(itr == targetItem){
                   //меняем кол. на новое прибавив к нему кол. эл. перемещаемого
                   tmp += itr->text().toInt();
                   itr->setText(QString::number(tmp));
                   //тображаю изменения в таблице
                  targetItem->setText(endl+QString::number(tmp));
                  break;
               }
           }
            //удаляю перемещенный элемент из контейнера
           objinfo.erase(it);
           //обнуляю ячеку из которой было перемещение
           setItem(mItem->row(), mItem->column(), nullptr);
           //обнуляю указатель
           mItem = nullptr;

           }

        }
         //если ячейка пуста
        else {
             //проверяю перемещаяемый объект
            if(mItem){
             //нахожу перемещенный объект к нотейнере(итератор)
            auto it = qFind(objinfo.begin(), objinfo.end(), mItem);
             //конструирую в ячейке новый элемент нашего яблока
            QImage imageName = *new QImage(Apple::getPatch());
            targetItem = new QTableWidgetItem(Apple::getType());
            targetItem->setData(Qt::DecorationRole, QPixmap::fromImage(imageName));
            //передаю кол. эл. из перемещаемго в новый
            targetItem->setText(mItem->text());
            //отображаю в таблице
            setItem(rowAt(event->pos().ry()), columnAt(event->pos().rx()), targetItem);
            //удаляю перемещенный элемент из контейнера
            objinfo.erase(it);
            //помещаю новый
            objinfo.append(targetItem);
           }
             //обнуляю ячеку из которой было перемещение
            setItem(mItem->row(), mItem->column(), nullptr);
            //обнуляю указатель
            mItem = nullptr;
       }
    }

        mDb.setDb(objinfo);//после каждого перемещения обновляю базу данных
}
//====================================================
void Inventory::setmItem(QTableWidgetItem * Item){

    if(Item){
        //при нажатии на элемент(ячеку) в таблице иницилизирую тем элементо наш указатель
    mItem = Item;
   }
}

#include "objectinfo.h"

Objectinfo::Objectinfo(QString cell, int index): cellNunb(cell),objname(Apple::getType()),counter(index)
{

}
//=======================================================
Objectinfo::Objectinfo(){};
//==============================================================
Objectinfo Objectinfo::getObjectinfo(){
    Objectinfo tmp;
    tmp.cellNunb = this->cellNunb;
    tmp.counter = this->counter;
    tmp.objname = this->objname;

    return tmp;
}

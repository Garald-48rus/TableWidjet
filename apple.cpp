#include "apple.h"

Apple::Apple()
{

}
//=========================================
 QString Apple::getPatch(){

     return patch;
}
 //========================================
 int Apple::getType(){

     return type;

 }
 //============================================
QString Apple::patch{":/image/image/apple.jpg"};//иницилизация переменной хранящая путь
int Apple::type{1001};//иницилизация тип объекта

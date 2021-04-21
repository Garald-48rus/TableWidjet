#ifndef APPLE_H
#define APPLE_H
#include <QString>

class Apple
{
public:
    Apple();

private:
    static QString patch;//путь к файлу
    static int type;//тип объекта

public:
    static QString getPatch();//функция возвращающая переменную хранящую путь к файлу
    static int getType();//функция возвращающая переменную хранящую тип объекта
};



#endif // APPLE_H

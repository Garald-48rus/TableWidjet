#ifndef SOUND_H
#define SOUND_H

#include <QString>
#include <QSound>

class Sound
{
public:
    Sound();
   ~Sound();

private:
    QString patch;//строка хранящая адрес звука

public:
    void play();//функция воизпроизведения
};

#endif // SOUND_H

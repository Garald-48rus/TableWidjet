#include "sound.h"

Sound::Sound():patch(":/sound/sound/appleSound.wav")
{

}
//====================================================
Sound::~Sound()
{

};
//=====================================================
void Sound::play(){

    QSound::play(patch);//проигрываю звук

}

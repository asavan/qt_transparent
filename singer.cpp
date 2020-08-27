#include "singer.h"
#include "music.h"

QtBassLib::QtBassLib() : pl(new BassLib())
{
}

QtBassLib::~QtBassLib() = default;

void QtBassLib::playMusic(int key) {
    pl->playMusic(music_prepare(key));
}

int QtBassLib::music_prepare(int key)
{
    if (key == 1025)
    {
        return 7;
    }
    if (key > 1039 && key < 1046)
    {
        return key - 1039;
    }
    if (key >= 1046 && key < 1039+33)
    {
        return key - 1038;
    }
    return beep;
}

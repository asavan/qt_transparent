#include "singer.h"
#include "music.h"
#include <iostream>

MyClass::MyClass()
{
    pl = new BassLib();
}

MyClass::~MyClass()
{
    delete pl;
}

void MyClass::getData(int key) {
    pl->play_music(music_prepare(key));
}

int MyClass::music_prepare(int key)
{
    std::cout << key << std::endl;

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


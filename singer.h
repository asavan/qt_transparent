#pragma once
#include <QObject>
class BassLib;

class QtBassLib : public QObject
{
    Q_OBJECT
public:
    QtBassLib();
    ~QtBassLib();
public slots:
    void playMusic(int k);
private :
    QtBassLib(const QtBassLib&);
    QtBassLib& operator=(const QtBassLib&);
	int music_prepare(int key);
	BassLib* pl;
};

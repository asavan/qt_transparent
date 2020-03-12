#pragma once
#include <QObject>
#include <memory>
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
    QtBassLib(const QtBassLib&) = delete;
    QtBassLib& operator=(const QtBassLib&) = delete;
	int music_prepare(int key);
    std::unique_ptr<BassLib> pl;
};

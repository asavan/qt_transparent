#ifndef _MUSIC_BASS_H_SAVAS
#define _MUSIC_BASS_H_SAVAS

class BassLib
{
public:
	BassLib();
    void playMusic(int key) const;
	~BassLib();
private:
	BassLib(const BassLib&);
	BassLib& operator=(const BassLib&);
};

enum kyes
{
	beep = 34,
	eng,
	exit_key,
	last
};

#endif // _MUSIC_BASS_H_SAVAS

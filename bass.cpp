#include "music.h"
#include "bass.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
// #include <stdexcept>

#if defined _MSC_VER
#pragma comment (lib, "bass.lib");
#endif
static int init()
{
	BOOL res = BASS_Init(-1,44100,0,0,NULL);
	if (!res)
	{
		std::cout << "Can't initialize device" << std::endl;
		return 1;
	}	
	return 0;
}


static void close_all_streams(std::vector<HSTREAM>& strms)
{
	for(std::vector<HSTREAM>::iterator it = strms.begin();
		it != strms.end(); ++it)
	{
		BASS_StreamFree(*it);
	}
	strms.clear();
}

static int setup_streams(const std::vector<std::string>& names, std::vector<HSTREAM>& strms)
{
	if (!strms.empty()) return 2;
	for(std::vector<std::string>::const_iterator it = names.begin();
			it != names.end(); ++it)
	{
		HSAMPLE samp = BASS_SampleLoad(FALSE,it->c_str(), 0, 0, 5, 0 );
		if (!samp)
		{
			std::cout << "err" << std::endl;
			return 4;
		}
		HSTREAM str = BASS_SampleGetChannel(samp, FALSE);
		// HSTREAM str = BASS_StreamCreateFile(FALSE,it->c_str(),0,0,0);
		if (!str)
		{
			std::cout << it->c_str() << std::endl;
			close_all_streams(strms);
			return 1;
		}
		strms.push_back(str);
	}
	return 0;
}

static int play(int key, const std::vector<HSTREAM>& strms)
{
	if(key < 0 || key > strms.size())
	{
        std::cout << key << " " << strms.size() << std::endl;
		return 10;
		// exit(1);
	}
	int res = BASS_ChannelPlay(strms[key], FALSE);
	// Sleep(500);
	return res;
}

static int test_setup(std::vector<HSTREAM>& strms)
{
	std::ifstream ifs("keys.txt");
	std::vector<std::string> strs;
	while (ifs)
	{
		std::string str;
		getline(ifs, str);
		if (str.empty()) break;
		strs.push_back(str);
	}
    return setup_streams(strs, strms);
}


// наружу
std::vector<HSTREAM> g_strms;

BassLib::BassLib()
{
    int res = init();
    if (res) {
        std::cout << "init fail" << std::endl;
    }
    // if (res) throw std::logic_error("init fail");
    res = test_setup(g_strms);
    if (res) {
        std::cout << "streams fail" << std::endl;
    }

}

BassLib::~BassLib()
{
	close_all_streams(g_strms);
	BASS_Free();
}

void BassLib::playMusic(int key) const
{
	play(key, g_strms);
}

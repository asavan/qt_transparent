#include "music.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <cassert>
#include <cstddef>
#include <limits>

template <typename ContainerType>
constexpr int size_as_int(const ContainerType& c) {
    const auto size = c.size();  // if no auto, use `typename ContainerType::size_type`
    assert(size <= static_cast<std::size_t>(std::numeric_limits<int>::max()));
    return static_cast<int>(size);
}

#if defined _MSC_VER
#pragma comment (lib, "bass.lib")
#endif
// do not move at the top. contains macros max that ruins everything
#include "bass.h"

namespace {
    int init()
    {
        BOOL res = BASS_Init(-1, 44100, 0, 0, nullptr);
        if (!res)
        {
            std::cout << "Can't initialize device" << std::endl;
            return 1;
        }
        return 0;
    }


    void close_all_streams(std::vector<HSTREAM>& strms)
    {
        for (auto stream : strms)
        {
            BASS_StreamFree(stream);
        }
        strms.clear();
    }

    int setup_streams(const std::vector<std::string>& names, std::vector<HSTREAM>& strms)
    {
        if (!strms.empty()) return 2;
        for (const std::string& name : names)
        {
            HSAMPLE samp = BASS_SampleLoad(FALSE, name.c_str(), 0, 0, 5, 0);
            if (!samp)
            {
                std::cout << "err" << std::endl;
                return 4;
            }
            HSTREAM str = BASS_SampleGetChannel(samp, FALSE);
            // HSTREAM str = BASS_StreamCreateFile(FALSE,it->c_str(),0,0,0);
            if (!str)
            {
                std::cout << name << std::endl;
                close_all_streams(strms);
                return 1;
            }
            strms.push_back(str);
        }
        return 0;
    }

    int play(int key, const std::vector<HSTREAM>& strms)
    {
        if (key < 0 || key > size_as_int(strms))
        {
            std::cout << key << " " << strms.size() << std::endl;
            return 10;
            // exit(1);
        }
        int res = BASS_ChannelPlay(strms[key], FALSE);
        // Sleep(500);
        return res;
    }

    int test_setup(std::vector<HSTREAM>& strms)
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

}

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

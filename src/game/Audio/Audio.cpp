/*
** EPITECH PROJECT, 2022
** Audio.cpp
** File description:
** Audio
*/

#include "Audio.hpp"

namespace IS {
    Audio::Audio() :
        _music_volume(1),
        _sound_volume(1),
        _music_state(true),
        _sound_state(true),
        _musics({}),
        _sounds({})
    {
        InitAudioDevice();
    }

    IS::Audio::~Audio()
    {
        StopSoundMulti();
        for (auto &it : _sounds)
            UnloadSound(it.second);
        _sounds.clear();
        for (auto &it : _musics)
            UnloadMusicStream(it.second);
        _musics.clear();
        if (IsAudioDeviceReady())
            CloseAudioDevice();
    }

    void Audio::loadMusic(const std::string &path)
    {
        if (_musics.find(path) != _musics.end())
            throw Error("music: '" + path + "' already exists", "Audio::loadMusic");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Audio::loadMusic");
        _musics.insert({path, LoadMusicStream(path.c_str())});
    }

    void Audio::loadSound(const std::string &path)
    {
        if (_sounds.find(path) != _sounds.end())
            throw Error("sound: '" + path + "' already exists", "Audio::loadSound");
        std::ifstream file(path.c_str());
        if (!file.is_open())
            throw Error("file: '" + path + "' not found", "Audio::loadSound");
        _sounds.insert({path, LoadSound(path.c_str())});
    }

    void Audio::playUpdateMusic(const std::string &path)
    {
        auto it = _musics.find(path);

        if (it == _musics.end()) {
            try {
                loadMusic(path);
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
        }
        if (_music_state) {
            it = _musics.find(path);
            if (!IsMusicStreamPlaying(it->second))
                PlayMusicStream(it->second);
            else {
                SetMusicVolume(it->second, _music_volume);
                UpdateMusicStream(it->second);
            }
        }
    }

    void Audio::playSound(const std::string &path)
    {
        if (path == "")
            return;
        auto it = _sounds.find(path);
        if (it == _sounds.end()) {
            try {
                loadSound(path);
            } catch (const Error &e) {
                std::cerr << e.where() << e.what() << std::endl;
            }
        }
        if (_sound_state) {
            it = _sounds.find(path);
            SetSoundVolume(it->second, _sound_volume);
            PlaySoundMulti(it->second);
        }
    }

    void Audio::stopMusic(const std::string &path)
    {
        auto it = _musics.find(path);

        if (it == _musics.end())
            throw Error("music: '" + path + "' doesn't exist", "Audio::stopMusic");
        if (IsMusicStreamPlaying(it->second))
            StopMusicStream(it->second);
    }

    float Audio::getMusicVolume()
    {
        return _music_volume;
    }

    void IS::Audio::setMusicVolume(const float &music_volume)
    {
        _music_volume = music_volume;
        for (auto &it : _musics)
            SetMusicVolume(it.second, _music_volume);
    }

    float IS::Audio::getSoundVolume()
    {
        return _sound_volume;
    }

    void IS::Audio::setSoundVolume(const float &sound_volume)
    {
        _sound_volume = sound_volume;
        for (auto &it : _sounds)
            SetSoundVolume(it.second, _sound_volume);
    }

    bool IS::Audio::getMusicState()
    {
        return _music_state;
    }

    void IS::Audio::setMusicState(const bool &music_state)
    {
        _music_state = music_state;
    }

    bool IS::Audio::getSoundState()
    {
        return _sound_state;
    }

    void IS::Audio::setSoundState(const bool &sound_state)
    {
        _sound_state = sound_state;
    }

    void Audio::changeMusicState()
    {
        _music_state = (_music_state != true) ? true : false;
    }

    void Audio::changeSoundState()
    {
        _sound_state = (_sound_state != true) ? true : false;
    }
}

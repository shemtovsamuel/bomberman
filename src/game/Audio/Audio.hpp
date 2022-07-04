/*
** EPITECH PROJECT, 2022
** Audio.hpp
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <iostream>
#include <unordered_map>
#include <fstream>
#include "../Type/Type.hpp"
#include "../Error/Error.hpp"

namespace IS {
    class Audio {
        private:
            float _music_volume;
            float _sound_volume;
            bool _music_state;
            bool _sound_state;
            std::unordered_map<std::string, Music> _musics;
            std::unordered_map<std::string, Sound> _sounds;

        public:
            Audio();
            ~Audio();
            void loadMusic(const std::string &path);
            void loadSound(const std::string &path);
            void playUpdateMusic(const std::string &path);
            void playSound(const std::string &path);
            void stopMusic(const std::string &path);
            float getMusicVolume();
            void setMusicVolume(const float &music_volume);
            float getSoundVolume();
            void setSoundVolume(const float &sound_volume);
            bool getMusicState();
            void setMusicState(const bool &music_state);
            bool getSoundState();
            void setSoundState(const bool &sound_state);
            void changeMusicState();
            void changeSoundState();
    };
}

#endif /* !AUDIO_HPP_ */

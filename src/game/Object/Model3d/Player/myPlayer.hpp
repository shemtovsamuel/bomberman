/*
** EPITECH PROJECT, 2022
** myPlayer.hpp
** File description:
** myPlayer
*/

#ifndef MYPLAYER_HPP_
#define MYPLAYER_HPP_

#include "../Model3d.hpp"
#include "../Bomb/Bomb.hpp"

namespace IS {
    class Player : public Model3d {
        public:
            Player(const Vector3 &position, const Vector3 &dimensions, const Vector3 &scale, const Vector3 &speed, const Vector3 &rotation_axis, const float &rotation_angle,  const std::string &texture_path, const std::string &model_path, const std::string &model_animation_path);
            ~Player() = default;
            Vector3 getPrevPosition();
            int getNbBomb();
            int getBombRange();
            std::vector<std::shared_ptr<Bomb>> getBombList();
            void setSpeed(float increase);
            void setNbBomb(int bomb);
            void setBombRange(int range);
            void setPrevPosition(const Vector3 &pos);
            virtual void moveLeft() = 0;
            virtual void moveRight() = 0;
            virtual void moveUp() = 0;
            virtual void moveDown() = 0;
            void dropBomb();
        protected:
            Vector3 _prev_position;
            int _animFrameCounter;
            std::string _model_animation_path;
            int _nb_bomb;
            int _bomb_range;
            std::vector<std::shared_ptr<Bomb>> _bomb_list;
    };
}

#endif /* !MYPLAYER_HPP_ */

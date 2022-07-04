/*
** EPITECH PROJECT, 2022
** Error.hpp
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace IS {
    class Error : public std::exception {
        public:
            Error(std::string what, std::string where) noexcept;
            ~Error() = default;

            const char *what() const noexcept override;
            const char *where() const noexcept;
        protected:
        private:
            std::string _what;
            std::string _where;
    };
}

#endif /* !ERROR_HPP_ */


#include "../../include/exceptions.hpp"

struct custom_exception : public std::exception {

    explicit custom_exception(const char *message) : message(message) {};

    const char *what() const noexcept override {
        return message;
    }

private:
    const char *message;
};
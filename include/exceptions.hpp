#include <exception>

struct custom_exception : public std::exception {

    explicit custom_exception(const char*);
    const char *what() const noexcept override;

private:
    const char *message;
    
};
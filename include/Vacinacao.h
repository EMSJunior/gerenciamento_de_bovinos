#ifndef VACINACAO_H
#define VACINACAO_H

#include <string>

class Vacinacao {
private:
    std::string tipo;
    std::string data;

public:
    Vacinacao(std::string tipo, std::string data);

    std::string getTipo() const;
    std::string getData() const;
};

#endif
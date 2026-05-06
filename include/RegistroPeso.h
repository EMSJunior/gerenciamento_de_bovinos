#ifndef REGISTROPESO_H
#define REGISTROPESO_H

#include <string>

class RegistroPeso {
private:
    float peso;
    std::string data;

public:
    RegistroPeso(float peso, std::string data);

    float getPeso() const;
    std::string getData() const;
};

#endif
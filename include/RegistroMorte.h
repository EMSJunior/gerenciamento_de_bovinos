#ifndef REGISTROMORTE_H
#define REGISTROMORTE_H

#include <string>

class RegistroMorte {
private:
    std::string causa;
    std::string data;

public:
    RegistroMorte(std::string causa, std::string data);

    std::string getCausa() const;
    std::string getData() const;
};

#endif
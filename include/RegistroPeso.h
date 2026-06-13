#ifndef REGISTROPESO_H
#define REGISTROPESO_H

#include <string>

/**
 * @brief Registra uma pesagem de um bovino em uma data.
 */
class RegistroPeso {
private:
    float peso;        ///< Peso aferido, em quilogramas.
    std::string data;  ///< Data da pesagem (DD/MM/AAAA).

public:
    /**
     * @brief Cria um registro de peso.
     * @param peso Peso em quilogramas.
     * @param data Data da pesagem.
     */
    RegistroPeso(float peso, std::string data);

    float getPeso() const;        ///< @return O peso registrado.
    std::string getData() const;  ///< @return A data da pesagem.
};

#endif

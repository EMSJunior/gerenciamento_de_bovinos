#ifndef REGISTROMORTE_H
#define REGISTROMORTE_H

#include <string>

/**
 * @brief Registra a morte de um bovino, com causa e data.
 */
class RegistroMorte {
private:
    std::string causa;  ///< Causa da morte.
    std::string data;   ///< Data da morte (DD/MM/AAAA).

public:
    /**
     * @brief Cria um registro de morte.
     * @param causa Causa da morte.
     * @param data  Data da morte.
     */
    RegistroMorte(std::string causa, std::string data);

    std::string getCausa() const;  ///< @return A causa da morte.
    std::string getData() const;   ///< @return A data da morte.
};

#endif

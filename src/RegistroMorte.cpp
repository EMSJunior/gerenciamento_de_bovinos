#include "../include/RegistroMorte.h"

RegistroMorte::RegistroMorte(std::string causa, std::string data) : causa(causa), data(data){

}
std::string RegistroMorte::getCausa() const {
    return causa;
}
std::string RegistroMorte::getData() const{
    return data;
}
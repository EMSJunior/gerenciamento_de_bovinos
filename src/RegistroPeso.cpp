#include "../include/RegistroPeso.h"
#include <iostream>

RegistroPeso::RegistroPeso(float peso, std::string data): peso(peso), data(data){
}
float RegistroPeso::getPeso()const{
    return peso;
}
std::string RegistroPeso::getData() const{
    return data;
}
#include "../include/RelatorioOperacional.h"
#include <iostream>

int RelatorioOperacional::totalMortes(const GerenciadorBovinos& g){
    int total = 0;
    std::vector<Bovino> listaParaAnalisar = g.listar();
    
    for(size_t i=0; i<listaParaAnalisar.size(); i++){
        if(!listaParaAnalisar[i].isVivo()){
        total++;
        }
    }
    return total;
}

float RelatorioOperacional::mediaPesos(const GerenciadorBovinos& g){
    int boisPesados = 0;
    float somaPesos = 0.0f;
    std::vector<Bovino> listaParaAnalisar = g.listar();
    
    for(size_t i = 0; i < listaParaAnalisar.size(); i++){
        if(listaParaAnalisar[i].isVivo()){
            std::vector<RegistroPeso> historico = listaParaAnalisar[i].getPesos();
            int tamanho = historico.size();
            
            if (tamanho > 0) {
                somaPesos = somaPesos + historico[tamanho - 1].getPeso();
                boisPesados++;
            }
        }
    }

    if (boisPesados == 0) {
        return 0.0f;
    }

    float media = somaPesos / boisPesados;
    return media;
}
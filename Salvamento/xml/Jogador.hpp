#pragma once

#include "tinyxml2.h"

class Jogador {
private:
    std::vector<float> posicao;
    std::vector<float> tamanho;
    int vida;
public:
    Jogador(
        std::vector<float> pos = {0.f, 0.f}, 
        std::vector<float> tam = {0.f, 0.f},
        int v = 10 
        ):
        posicao(pos),
        tamanho(tam), 
        vida(v) {
            // Nada aqui!
    }
    ~Jogador() {

    }
    void salvar(tinyxml2::XMLElement& jogadorElement, tinyxml2::XMLDocument& doc) {
        // nome do atributo, valor do atributo:
        jogadorElement.SetAttribute("posicaoX", posicao[0]);
        jogadorElement.SetAttribute("posicaoY", posicao[1]);
        jogadorElement.SetAttribute("tamanhoX", tamanho[0]);
        jogadorElement.SetAttribute("tamanhoY", tamanho[1]);
        jogadorElement.SetAttribute("vida", vida);
    }
    void carregar(tinyxml2::XMLElement& xml) {
        posicao = {
            xml.FloatAttribute("posicaoX"),
            xml.FloatAttribute("posicaoY")
        };
        tamanho = {
            xml.FloatAttribute("tamanhoX"),
            xml.FloatAttribute("tamanhoY")
        };
        vida = xml.IntAttribute("vida");
    }
    void mostrarInfo() {
        std::cout << "Posição: " <<  posicao[0] << " " << posicao[1] << std::endl << "Tamanho: " << tamanho[0] << " " << tamanho[1] << std::endl << "Vida: " << vida << std::endl;
    }
    // ...
};
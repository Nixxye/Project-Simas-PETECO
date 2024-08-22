#pragma once
#include "json.hpp"

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
    void salvar(nlohmann::ordered_json& json) {
        // json[chave] = {info}
        json["posicao"] = { {"x", posicao[0]}, {"y", posicao[1]}};
        json["tamanho"] = { {"x", tamanho[0]}, {"y", tamanho[1]}};
        json["vida"] = vida;
    }
    void carregar(nlohmann::ordered_json& json) {
        posicao = {json["posicao"]["x"], json["posicao"]["y"]};
        tamanho = {json["tamanho"]["x"], json["tamanho"]["y"]};
        vida = json["vida"];
    }
    void mostrarInfo() {
        std::cout << "Posição: " <<  posicao[0] << " " << posicao[1] << std::endl << "Tamanho: " << tamanho[0] << " " << tamanho[1] << std::endl << "Vida: " << vida << std::endl;
    }
    // ...
};
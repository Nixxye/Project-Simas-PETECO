#pragma once

// Incluir arquivo gerado pelo protobuf:
#include "protobuf/jogador.pb.h"

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
    void salvar(const std::string& caminho) {
        JogadorProto jogador;
        jogador.add_posicao(posicao[0]);
        jogador.add_posicao(posicao[1]);
        jogador.add_tamanho(tamanho[0]);
        jogador.add_tamanho(tamanho[1]);
        jogador.set_vida(vida);

        std::ofstream output(caminho, std::ios::binary);
        jogador.SerializeToOstream(&output);
    }
    void carregar(const std::string& caminho) {
        JogadorProto jogador;
        std::ifstream input(caminho, std::ios::binary);
        jogador.ParseFromIstream(&input);

        posicao[0] = jogador.posicao(0);
        posicao[1] = jogador.posicao(1);

        tamanho[0] = jogador.tamanho(0);
        tamanho[1] = jogador.tamanho(1);
        vida = jogadorProto.vida();
    }
    void mostrarInfo() {
        std::cout << "Posição: " <<  posicao[0] << " " << posicao[1] << std::endl << "Tamanho: " << tamanho[0] << " " << tamanho[1] << std::endl << "Vida: " << vida << std::endl;
    }
    // ...
};
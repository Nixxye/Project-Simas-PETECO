#include <iostream>
#include <vector>
#include <fstream>

#include "Jogador.hpp"


#define CAMINHO_ARQUIVO_SALVAMENTO "protobuf/arquivoSalvamento.bin"
#define CAMINHO_ARQUIVO_CARREGAMENTO "protobuf/arquivoCarregamento.bin"

void salvar(std::vector<Jogador>& jogadores) {
    
    for (Jogador& j : jogadores) {
        j.salvar(CAMINHO_ARQUIVO_SALVAMENTO);
    }
}

void carregar(std::vector<Jogador>& jogadores) {
    for (Jogador& j : jogadores) {
        j.carregar(CAMINHO_ARQUIVO_CARREGAMENTO);
    }

}

int main(void) {
    std::vector<Jogador> jogadores = {Jogador()};
    // carregar(jogadores);
    salvar(jogadores);
}
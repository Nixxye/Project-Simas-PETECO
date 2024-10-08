#include <iostream>
#include <vector>
#include <fstream>

#include "Jogador.hpp"
#include "json.hpp"

#define CAMINHO_ARQUIVO_SALVAMENTO "json/arquivoSalvamento.json"
#define CAMINHO_ARQUIVO_CARREGAMENTO "json/arquivoCarregamento.json"

void salvar(std::vector<Jogador>& jogadores) {
    // Um json para adicionar todos os jogadores:
    nlohmann::ordered_json infoJogadores;
    
    for (Jogador& j : jogadores) {
        // json para salvar as informações de cada jogador
        nlohmann::ordered_json infoJogador;
        j.salvar(infoJogador);
        infoJogadores.push_back(infoJogador);
    }
    std::ofstream jsonOut(CAMINHO_ARQUIVO_SALVAMENTO);

    if(!jsonOut) {
        std::cerr << "Arquivo de salvamento não encontrado" << std::endl;
        exit(1);
    }
    // Define um espaçamento de 4
    jsonOut << std::setw(4) << infoJogadores;
    jsonOut.close();
}

void carregar(std::vector<Jogador>& jogadores) {
    std::ifstream jsonIn(CAMINHO_ARQUIVO_CARREGAMENTO);
    if(!jsonIn) {
        std::cerr << "Arquivo de carregamento não encontrado" << std::endl;
        exit(1);
    }

    // Um json para adicionar todos os jogadores:
    nlohmann::ordered_json infoJogadores = nlohmann::ordered_json::parse(jsonIn);
    nlohmann::ordered_json::iterator it = infoJogadores.begin();

    for (Jogador& j : jogadores) {
        if (it != infoJogadores.end()) {
            j.carregar(*it);
            j.mostrarInfo();
        }
    }

    jsonIn.close();
}

int main(void) {
    std::vector<Jogador> jogadores = {Jogador()};
    carregar(jogadores);
    salvar(jogadores);
}
#include <iostream>
#include <vector>
#include <fstream>

#include "Jogador.hpp"
#include "rapidcsv.h"

#define CAMINHO_ARQUIVO_SALVAMENTO "csv/arquivoSalvamento.csv"
#define CAMINHO_ARQUIVO_CARREGAMENTO "csv/arquivoCarregamento.csv"

void salvar(std::vector<Jogador>& jogadores) {
    // Um csv para adicionar todos os jogadores:   
    rapidcsv::Document infoJogadores(CAMINHO_ARQUIVO_SALVAMENTO, rapidcsv::LabelParams(-1, -1));
    for (Jogador& j : jogadores) {
        infoJogadores.InsertRow(1, j.salvar());
    }
    infoJogadores.Save();
}

void carregar(std::vector<Jogador>& jogadores) {
    rapidcsv::Document infoJogadores(CAMINHO_ARQUIVO_CARREGAMENTO, rapidcsv::LabelParams(0, -1));

    // Ler os dados das colunas
    std::vector<float> posicao_x = infoJogadores.GetColumn<float>("posicao_x");
    std::vector<float> posicao_y = infoJogadores.GetColumn<float>("posicao_y");
    std::vector<float> tamanho_x = infoJogadores.GetColumn<float>("tamanho_x");
    std::vector<float> tamanho_y = infoJogadores.GetColumn<float>("tamanho_y");
    std::vector<int> vida = infoJogadores.GetColumn<int>("vida");

    int i = 0;
    for (Jogador& j : jogadores) {
        // Adiciona o dado referente ao jogador (i representa a linha no csv)
        j.carregar({posicao_x[i], posicao_y[i], tamanho_x[i], tamanho_y[i], (float) vida[i]});
        j.mostrarInfo();
        i++;
    }
}

int main(void) {
    std::vector<Jogador> jogadores = {Jogador()};
    carregar(jogadores);
    salvar(jogadores);
}
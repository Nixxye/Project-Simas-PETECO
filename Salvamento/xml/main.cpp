#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Jogador.hpp"
#include "tinyxml2.h"

#define CAMINHO_ARQUIVO_SALVAMENTO "xml/arquivoSalvamento.xml"
#define CAMINHO_ARQUIVO_CARREGAMENTO "xml/arquivoCarregamento.xml"

void salvar(std::vector<Jogador>& jogadores) {
    // Um xml para adicionar todos os jogadores:
    tinyxml2::XMLDocument infoJogadores;

    tinyxml2::XMLNode* root = infoJogadores.NewElement("Jogadores");
    infoJogadores.InsertFirstChild(root);
    
    int i = 0;
    for (Jogador& j : jogadores) {
        // json para salvar as informações de cada jogador:
        tinyxml2::XMLElement* jogadorElement = infoJogadores.NewElement("Jogador");
        j.salvar(*jogadorElement, infoJogadores);
        root->InsertEndChild(jogadorElement);
        i++;
    }

    if(infoJogadores.SaveFile(CAMINHO_ARQUIVO_SALVAMENTO) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Arquivo de salvamento não encontrado" << std::endl;
        exit(1);
    }
}

void carregar(std::vector<Jogador>& jogadores) {
    tinyxml2::XMLDocument infoJogadores;
    if(infoJogadores.LoadFile(CAMINHO_ARQUIVO_CARREGAMENTO) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Arquivo de carregamento não encontrado" << std::endl;
        exit(1);
    }
    // Procura por jogadores no arquivo:
    tinyxml2::XMLNode* root = infoJogadores.FirstChildElement("Jogadores");
    if (root == nullptr) {
        std::cerr << "Elemento raiz 'Jogadores' não encontrado" << std::endl;
        exit(1);
    }

    tinyxml2::XMLElement* jogadorElement = root->FirstChildElement("Jogador");
    for (Jogador& j : jogadores) {
        if (jogadorElement != nullptr) {
            j.carregar(*jogadorElement);
            j.mostrarInfo();
            jogadorElement = jogadorElement->NextSiblingElement("Jogador");
        }
    }
}

int main(void) {
    std::vector<Jogador> jogadores = {Jogador()};
    carregar(jogadores);
    salvar(jogadores);
}
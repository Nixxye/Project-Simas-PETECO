#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "nlohmann/json.hpp"
#include <vector>
#include <fstream>
#include <string>



/*
    Classe Tilemap
    - Classe responsável por carregar o mapa do jogo
    - Cria as entidades do jogo
    - Cria o mapa do jogo

    LEIA OS COMENTARIOS DO .CPP E AJUSTE NO SEU CÓDIGO

*/

class Entidade;

class Tilemap{
    private:
        nlohmann::json mapa; // mapa.json  

    public:
        Tilemap(std::string mapJson);
        ~Tilemap();

        void carregarMapa(std::string mapJson, std::string caminhoImagem);
        Entidade* criarEntidade (sf::Vector2f posicao, sf::Vector2f tamanho, int tipo);
        void criarMapa(std::vector<Entidade*>* entidades, sf::Texture* textura_mapa);
};
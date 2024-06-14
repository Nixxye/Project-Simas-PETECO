#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class GerenciadorTexturas{
    private:
        std::unordered_map<std::string, sf::Texture*> map_texturas;
        
        static GerenciadorTexturas* instancia;
        GerenciadorTexturas();
    
    public:
        ~GerenciadorTexturas();

        static GerenciadorTexturas* getInstancia();

        void adicionarTextura(std::string chave, std::string caminho);
        sf::Texture* getTextura(std::string chave);
        void criarMapaTexturas();
};
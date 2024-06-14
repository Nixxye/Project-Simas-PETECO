#pragma once
#include "Animacao.hpp"

class Jogador{
    private:
        sf::RectangleShape corpo;
        
        Animacao parado;
        Animacao andando;

        bool direcao;
        sf::Vector2f posAntiga;
        
    public:
        Jogador();
        ~Jogador();

        void executar();
        void mover();
        void desenhar(sf::RenderWindow* janela);
        void setDirecao(bool direcao);
};
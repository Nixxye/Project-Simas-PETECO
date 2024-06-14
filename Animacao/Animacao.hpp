#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Animacao{
    private:
        sf::Texture* imagem;
        sf::Texture frame;

        std::vector<sf::IntRect> frames;
        
        int numFrames;
        int frameAtual;
        
        int tempoFrame;
        int tempoFrameAtual;
        
    public:
        Animacao(std::string chaveSprite, int numFrames, int tempoFrame);
        ~Animacao();


        void cortarFrames();

        // direcao = true -> direita | direcao = false -> esquerda
        void atualizar(sf::RectangleShape* corpo, bool direcao);

        void atualizar(sf::RectangleShape* corpo);

        void reiniciar();
};
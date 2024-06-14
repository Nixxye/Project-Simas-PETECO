#include "Animacao.hpp"
#include "GerenciadorTexturas.hpp"


Animacao::Animacao(std::string chaveSprite, int numFrames, int tempoFrame)
{   
    imagem = GerenciadorTexturas::getInstancia()->getTextura(chaveSprite);
    this->numFrames = numFrames;
    this->tempoFrame = tempoFrame;
    this->tempoFrameAtual = tempoFrame;
    this->frameAtual = 0;
    this->cortarFrames();
}

Animacao::~Animacao()
{
}

void Animacao::cortarFrames()
{   
    int tamX = imagem->getSize().x;
    int tamY = imagem->getSize().y;

    int dimX = tamX / numFrames;

    for(int i = 0; i < numFrames; i++){
        sf::IntRect frame;
        frame.left = i * dimX;
        frame.top = 0;
        frame.width = dimX;
        frame.height = tamY;
        frames.push_back(frame);
    }
}

void Animacao::atualizar(sf::RectangleShape *corpo, bool direcao)
{
    tempoFrameAtual++;
    if(tempoFrameAtual < tempoFrame)
        return;

    tempoFrameAtual = 0;
    
    sf::Image temp = imagem->copyToImage();

    if(!direcao){
        temp.flipHorizontally();
    }
    frame.loadFromImage(temp);
    corpo->setTexture(&frame);
    corpo->setTextureRect(frames[frameAtual]);
    corpo->getScale();

    frameAtual = (frameAtual + 1) % numFrames;

}

void Animacao::atualizar(sf::RectangleShape *corpo)
{
    tempoFrameAtual++;
    if(tempoFrameAtual < tempoFrame)
        return;

    tempoFrameAtual = 0;

    corpo->setTexture(imagem);
    corpo->setTextureRect(frames[frameAtual]);
    corpo->getScale();

    frameAtual = (frameAtual + 1) % numFrames;
}

void Animacao::reiniciar()
{
    frameAtual = 0;
    tempoFrameAtual = 0;
}

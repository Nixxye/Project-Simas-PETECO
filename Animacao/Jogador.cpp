#include "Jogador.hpp"

Jogador::Jogador() : parado("ESQUELETO PARADO", 19, 3), andando("ESQUELETO ANDANDO", 20, 3), direcao(true)
{
    corpo.setSize(sf::Vector2f(70, 100));
}

Jogador::~Jogador()
{
}

void Jogador::executar()
{   
    posAntiga = corpo.getPosition();

    mover();
    
    if (posAntiga != corpo.getPosition()){
        andando.atualizar(&corpo, direcao);
    }
    else{
        parado.atualizar(&corpo, direcao);
    }

}

void Jogador::mover()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        corpo.move(1.5, 0);
        direcao = true;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        corpo.move(-1.5, 0);
        direcao = false;
    }

    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        corpo.move(0, -2);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        corpo.move(0, 2);
    }
}

void Jogador::desenhar(sf::RenderWindow *janela)
{
    janela->draw(corpo);
}

void Jogador::setDirecao(bool direcao)
{
    this->direcao = direcao;
}

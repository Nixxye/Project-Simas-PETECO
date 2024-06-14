#include <iostream>
#include "Jogador.hpp"
#include "GerenciadorTexturas.hpp"


int main(){
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Animacao", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    GerenciadorTexturas* gr = GerenciadorTexturas::getInstancia();
    
    sf::RectangleShape back(sf::Vector2f(1920, 1080));
    Animacao fundo("LAVA", 8, 3);
    
    Jogador jogador;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }

        window.clear();
        
        fundo.atualizar(&back);
        jogador.executar();

        window.draw(back);
        jogador.desenhar(&window);

        window.display();
    }
}
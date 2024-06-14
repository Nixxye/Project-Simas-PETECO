#include "GerenciadorTexturas.hpp"

GerenciadorTexturas *GerenciadorTexturas::instancia = nullptr;
GerenciadorTexturas::GerenciadorTexturas()
{
    criarMapaTexturas();
}

GerenciadorTexturas::~GerenciadorTexturas()
{
}


GerenciadorTexturas *GerenciadorTexturas::getInstancia()
{
    if(instancia == nullptr){
        instancia = new GerenciadorTexturas();
    }
    return instancia;
}


void GerenciadorTexturas::adicionarTextura(std::string chave, std::string caminho)
{
    sf::Texture *textura = new sf::Texture();
    if(!textura->loadFromFile(caminho)){
        std::cerr<<"Erro ao carregar textura (caminho nao encontrado)"<<std::endl;
        return;
    }

    map_texturas[chave] = textura;
}

sf::Texture *GerenciadorTexturas::getTextura(std::string chave)
{
    auto it = map_texturas.find(chave);
    if(it != map_texturas.end()){
        return it->second;
    }

    std::cerr<<"Textura nao encontrada"<<std::endl;
    
    return nullptr;
}


void GerenciadorTexturas::criarMapaTexturas(){

    adicionarTextura("ESQUELETO PARADO", "imagens/esqueleto_parado.png");
    adicionarTextura("ESQUELETO ANDANDO", "imagens/esqueleto_andando.png");

    adicionarTextura("LAVA", "imagens/lava.png");
    adicionarTextura("VULCAO", "imagens/vulcao.png");
    adicionarTextura("CAVERNA", "imagens/caverna.png");
    adicionarTextura("MENU_INICIAL", "imagens/menu_inicial.png");

}
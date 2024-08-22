#pragma once

class Jogador {
private:
    std::vector<float> posicao;
    std::vector<float> tamanho;
    int vida;
public:
    Jogador(
        std::vector<float> pos = {0.f, 0.f}, 
        std::vector<float> tam = {0.f, 0.f},
        int v = 10 
        ):
        posicao(pos),
        tamanho(tam), 
        vida(v) {
            // Nada aqui!
    }
    ~Jogador() {

    }
    std::vector<float> salvar() {
        // vetor com os valores do jogador na ordem correta do csv:
        return std::vector<float> {
            posicao[0], posicao[1], tamanho[0], tamanho[1], (float) vida
        };
    }
    void carregar(std::vector<float> valores) {
        posicao = {valores[0], valores[1]};
        tamanho = {valores[2], valores[3]};
        vida = valores[4];
    }
    void mostrarInfo() {
        std::cout << "Posição: " <<  posicao[0] << " " << posicao[1] << std::endl << "Tamanho: " << tamanho[0] << " " << tamanho[1] << std::endl << "Vida: " << vida << std::endl;
    }
    // ...
};
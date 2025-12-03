#include "despesa.hpp"
#include "morador.hpp" // Agora incluímos o morador.hpp pois precisamos da definição completa

// Implementação do Construtor
// Inicializa todos os atributos protegidos usando a lista de inicialização
Despesa::Despesa(float valor, std::string data, std::string categoria, Morador* pagador)
    : valor_(valor), data_(data), categoria_(categoria), pagador_(pagador) {
}

// Implementação do Destrutor
// Mesmo vazio, é necessário implementá-lo pois foi declarado no .hpp
Despesa::~Despesa() {
}

// Implementação dos Getters

float Despesa::getValor() const {
    return valor_;
}

std::string Despesa::getData() const {
    return data_;
}

std::string Despesa::getCategoria() const {
    return categoria_;
}

Morador* Despesa::getPagador() const {
    return pagador_;
}

// Nota: O método dividir() NÃO é implementado aqui porque é virtual puro (= 0)

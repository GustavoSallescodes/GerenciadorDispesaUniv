#include "pagamento.hpp"
#include "morador.hpp" // Necessário para conhecer a definição completa de Morador

// Implementação do Construtor
// Inicializa os atributos usando a lista de inicialização
Pagamento::Pagamento(float valor, std::string data, Morador* pagador)
    : valor_(valor), data_(data), pagador_(pagador) {
}

// Implementação dos Getters

float Pagamento::getValor() const {
    return valor_;
}

std::string Pagamento::getData() const {
    return data_;
}

Morador* Pagamento::getPagador() const {
    return pagador_;
}

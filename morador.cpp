#include "morador.hpp"
// Construtor: Inicializa nome, email e define o saldo como 0.
Morador::Morador(std::string nome, std::string email) 
    : nome_(nome), email_(email), saldo_(0.0f) {
}
// Destrutor (vazio, pois não há alocação dinâmica manual aqui)
Morador::~Morador() {
}
// Retorna o nome do morador
std::string Morador::getNome() const {
    return nome_;
}
// Retorna o email do morador
std::string Morador::getEmail() const {
    return email_;
}
// Retorna o saldo atual
float Morador::getSaldo() const {
    return saldo_;
}
// Atualiza o saldo somando o valor informado
void Morador::atualizarSaldo(float valor) {
    saldo_ += valor;
}

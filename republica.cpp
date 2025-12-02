#include "republica.hpp"
#include "morador.hpp"
#include "despesa.hpp"
#include "despesa_comum.hpp"
#include "despesa_individual.hpp"
#include "pagamento.hpp"
#include <iostream>
// Construtor vazio
Republica::Republica() {
}
// Destrutor: Limpeza de memória é crucial em C++ (evita memory leaks)
Republica::~Republica() {
    // Deleta todos os moradores alocados dinamicamente
    for (Morador* m : moradores_) {
        delete m;
    }
    // Deleta todas as despesas (o destrutor virtual de Despesa garante a limpeza correta)
    for (Despesa* d : despesas_) {
        delete d;
    }
    // Deleta todos os pagamentos
    for (Pagamento* p : pagamentos_) {
        delete p;
    }
}
void Republica::adicionarMorador(std::string nome, std::string email) {
    // Cria um novo objeto Morador na heap e guarda o ponteiro no vetor
    moradores_.push_back(new Morador(nome, email));
}
Morador* Republica::buscarMorador(std::string nome) {
    // Itera sobre o vetor buscando pelo nome
    for (Morador* m : moradores_) {
        if (m->getNome() == nome) {
            return m;
        }
    }
    return nullptr; // Retorna nulo se não encontrar
}
void Republica::registrarDespesaComum(Morador* pagador, float valor, std::string data, std::string categoria, std::vector<Morador*> envolvidos) {
    // Instancia uma DespesaComum (Polimorfismo: guardada como Despesa*)
    Despesa* nova_despesa = new DespesaComum(valor, data, categoria, pagador, envolvidos);
    // Chama o método dividir(), que calcula as cotas e atualiza o saldo de cada morador
    nova_despesa->dividir();   
    // Armazena no histórico
    despesas_.push_back(nova_despesa);
}
void Republica::registrarDespesaIndividual(Morador* pagador, float valor, std::string data, std::string categoria, Morador* responsavel) {
    // Instancia uma DespesaIndividual
    Despesa* nova_despesa = new DespesaIndividual(valor, data, categoria, pagador, responsavel);
    // Chama dividir() para efetuar a transação nos saldos
    nova_despesa->dividir();
    // Armazena no histórico
    despesas_.push_back(nova_despesa);
}
void Republica::registrarPagamento(Morador* pagador, Morador* recebedor, float valor, std::string data) {
    // Cria o registro do pagamento
    Pagamento* novo_pagamento = new Pagamento(pagador, recebedor, valor, data);
    pagamentos_.push_back(novo_pagamento);
    // Ajuste manual dos saldos (Amortização):
    // Quem paga, "recupera" saldo (sua dívida diminui, ou seja, vai em direção ao positivo)
    pagador->atualizarSaldo(valor);
    // Quem recebe, "perde" saldo (seu crédito diminui, pois já foi pago)
    recebedor->atualizarSaldo(-valor);
}
void Republica::exibirSaldos() {
    std::cout << "--- Saldos Atuais ---" << std::endl;
    for (Morador* m : moradores_) {
        // Exibe o saldo. Positivo = Tem a receber. Negativo = Tem a pagar.
        std::cout << m->getNome() << ": R$ " << m->getSaldo() << std::endl;
    }
}
void Republica::exibirHistorico() {
    std::cout << "\n--- Historico de Despesas ---" << std::endl;
    for (Despesa* d : despesas_) {
        // Aqui você pode melhorar a formatação usando getters da classe Despesa
        std::cout << "Valor: R$ " << d->getValor() 
                  << " | Data: " << d->getData() 
                  << " | Categoria: " << d->getCategoria() << std::endl;
    }
    std::cout << "\n--- Historico de Pagamentos ---" << std::endl;
    // O código aqui depende da implementação dos getters em Pagamento
    // for (Pagamento* p : pagamentos_) { ... }
}
void Republica::gerarRelatorioFechamento() {
    std::cout << "\n=== Relatorio de Fechamento ===" << std::endl;
    exibirSaldos();
    // Futuramente: Implementar lógica para sugerir quem deve pagar quem
    // para zerar as contas com o mínimo de transações.
}

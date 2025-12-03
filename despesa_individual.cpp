#include "despesa_individual.hpp"

DespesaIndividual::DespesaIndividual(float valor,
                                     std::string data,
                                     std::string categoria,
                                     Morador* pagador)
    : Despesa(valor, data, categoria, pagador) {}

void DespesaIndividual::dividir() {
    // O pagador arca sozinho com a despesa
    pagador_->atualizarSaldo(-valor_);
}

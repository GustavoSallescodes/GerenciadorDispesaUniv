#include "despesa_comum.hpp"
#include "morador.hpp"

DespesaComum::DespesaComum(float valor,
                           std::string data,
                           std::string categoria,
                           Morador* pagador,
                           std::vector<Morador*> envolvidos)
    : Despesa(valor, data, categoria, pagador),
      moradores_envolvidos_(envolvidos) {}


void DespesaComum::dividir() {
    if (moradores_envolvidos_.empty()) return;

    // 1. Calcula cota individual
    float cota = valor_ / moradores_envolvidos_.size();

    // 2. Pagador recebe crédito (ele pagou a despesa inteira)
    pagador_->atualizarSaldo(valor_);

    // 3. Todos os envolvidos (inclusive o pagador) pagam sua parte
    for (Morador* m : moradores_envolvidos_) {
        m->atualizarSaldo(-cota);
    }
}

#include "despesa_comum.hpp"
#include "morador.hpp"

DespesaComum::DespesaComum(float valor,
                           std::string data,
                           std::string categoria,
                           Morador* pagador,
                           std::vector<Morador*> envolvidos)
    : Despesa(valor, data, categoria, pagador),
      envolvidos_(envolvidos) {}

void DespesaComum::dividir() {
    if (envolvidos_.empty()) {
        return; // Sem envolvidos, nada a dividir
    }

    // Cada morador paga uma parte igual
    float cota = valor_ / envolvidos_.size();

    // Pagador recebe crédito pelo valor total pago
    pagador_->atualizarSaldo(valor_);

    // Todos os envolvidos pagam sua parte
    for (Morador* m : envolvidos_) {
        m->atualizarSaldo(-cota);
    }
}


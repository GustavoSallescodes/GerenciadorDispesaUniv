#ifndef DESPESA_COMUM_HPP
#define DESPESA_COMUM_HPP

#include "despesa.hpp"
#include <vector>

/**
 * @brief Classe que representa uma despesa comum entre vários moradores.
 * * Uma DespesaComum é dividida igualmente entre todos os envolvidos.
 * * O pagador recebe crédito pelo valor total pago e cada morador paga sua cota.
 */
class DespesaComum : public Despesa {
private:
    std::vector<Morador*> envolvidos_; ///< Vetor contendo todos os moradores participantes da despesa.

public:
    /**
     * @brief Construtor da classe DespesaComum.
     * * Inicializa a despesa comum com valor total, data, categoria,
     *   morador pagador e lista de moradores envolvidos.
     *
     * @param valor Valor total da despesa.
     * @param data Data em que a despesa ocorreu.
     * @param categoria Categoria da despesa (ex: supermercado, gás, internet).
     * @param pagador Morador que realizou o pagamento.
     * @param envolvidos Vetor contendo os moradores que participarão da divisão.
     */
    DespesaComum(float valor,
                 std::string data,
                 std::string categoria,
                 Morador* pagador,
                 std::vector<Morador*> envolvidos);

    /**
     * @brief Realiza a divisão da despesa entre os moradores envolvidos.
     * * O pagador recebe crédito pelo valor total pago.
     * * Cada morador (incluindo o pagador) paga uma cota igual.
     */
    void dividir() override;
};

#endif // DESPESA_COMUM_HPP


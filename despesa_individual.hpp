#ifndef DESPESA_INDIVIDUAL_HPP
#define DESPESA_INDIVIDUAL_HPP

#include "despesa.hpp"

/**
 * @brief Representa uma despesa individual, paga e pertencente a um único morador.
 * * Neste caso, não há divisão: o pagador arca sozinho com o valor.
 */
class DespesaIndividual : public Despesa {
public:
    /**
     * @brief Construtor da classe DespesaIndividual.
     */
    DespesaIndividual(float valor, std::string data, std::string categoria, Morador* pagador);

    /**
     * @brief O pagador recebe o débito integral da despesa.
     */
    void dividir() override;
};

#endif // DESPESA_INDIVIDUAL_HPP


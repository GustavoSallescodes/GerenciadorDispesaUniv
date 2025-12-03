#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

#include <string>
#include "morador.hpp"

/**
 * @brief Classe que representa um pagamento realizado na república.
 * 
 * Esta classe armazena informações sobre um pagamento efetuado por um morador,
 * como o valor pago, a data e uma descrição opcional. O pagamento impacta o
 * saldo do morador, já que representa um crédito (valor positivo).
 */
class Pagamento {
private:
    Morador* morador_;     ///< Morador que realizou o pagamento.
    float valor_;          ///< Valor pago (positivo = crédito para o morador).
    std::string data_;     ///< Data em que o pagamento foi realizado.
    std::string descricao_;///< Descrição opcional do pagamento.

public:
    /**
     * @brief Construtor da classe Pagamento.
     * 
     * Inicializa um pagamento com valor, data e morador responsável.
     * O pagamento é um crédito, portanto aumenta o saldo do morador.
     * 
     * @param morador Pointer para o morador que realizou o pagamento.
     * @param valor Valor do pagamento (deve ser positivo).
     * @param data Data do pagamento.
     * @param descricao Descrição opcional para exibir nos relatórios.
     */
    Pagamento(Morador* morador, float valor, std::string data, std::string descricao);

    /**
     * @brief Destrutor padrão.
     */
    ~Pagamento();

    /**
     * @brief Obtém o morador que realizou o pagamento.
     * @return Ponteiro para o morador.
     */
    Morador* getMorador() const;

    /**
     * @brief Obtém o valor pago.
     * @return Valor do pagamento.
     */
    float getValor() const;

    /**
     * @brief Obtém a data do pagamento.
     * @return String com a data.
     */
    std::string getData() const;

    /**
     * @brief Obtém a descrição do pagamento.
     * @return String contendo a descrição.
     */
    std::string getDescricao() const;
};

#endif // PAGAMENTO_HPP


#ifndef DESPESA_HPP
#define DESPESA_HPP

#include <string>
#include "morador.hpp"

/**
 * @brief Classe base abstrata que representa uma despesa da república.
 * * Armazena informações comuns a todas as despesas: valor, data, categoria e pagador.
 */
class Despesa {
protected:
    float valor_;             ///< Valor total da despesa.
    std::string data_;        ///< Data em que a despesa ocorreu.
    std::string categoria_;   ///< Categoria (ex.: supermercado, gás, internet).
    Morador* pagador_;        ///< Morador responsável pelo pagamento.

public:
    /**
     * @brief Construtor padrão da classe Despesa.
     *
     * @param valor Valor da despesa.
     * @param data Data da despesa.
     * @param categoria Categoria da despesa.
     * @param pagador Morador que efetuou o pagamento.
     */
    Despesa(float valor, std::string data, std::string categoria, Morador* pagador);

    /**
     * @brief Destrutor virtual para permitir herança.
     */
    virtual ~Despesa() = default;

    /**
     * @brief Divide a despesa entre os moradores.
     * * Método abstrato que deve ser implementado pelas subclasses.
     */
    virtual void dividir() = 0;

    float getValor() const;
    std::string getData() const;
    std::string getCategoria() const;
    Morador* getPagador() const;
};

#endif // DESPESA_HPP

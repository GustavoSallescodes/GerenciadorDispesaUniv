#ifndef MORADOR_HPP
#define MORADOR_HPP
#include <string>
/**
 * @brief Classe que representa um morador da república.
 * * Esta classe armazena informações pessoais do morador (nome, email)
 * e gerencia seu saldo financeiro em relação à república.
 */
class Morador {
private:
    std::string nome_;  ///< Nome do morador.
    std::string email_; ///< Email do morador.
    float saldo_;       ///< Saldo atual do morador (Positivo = Crédito, Negativo = Débito).
public:
    /**
     * @brief Construtor da classe Morador.
     * * Inicializa um morador com nome e email. O saldo inicial é 0.
     * * @param nome O nome do morador.
     * @param email O email do morador.
     */
    Morador(std::string nome, std::string email);
    /**
     * @brief Destrutor padrão.
     */
    ~Morador();
    /**
     * @brief Obtém o nome do morador.
     * @return String contendo o nome.
     */
    std::string getNome() const;
    /**
     * @brief Obtém o email do morador.
     * @return String contendo o email.
     */
    std::string getEmail() const;
    /**
     * @brief Obtém o saldo atual do morador.
     * @return Float representando o saldo.
     */
    float getSaldo() const;
    /**
     * @brief Atualiza o saldo do morador.
     * * Adiciona o valor passado ao saldo atual.
     * Se o valor for positivo, o saldo aumenta (alguém pagou algo ou foi reembolsado).
     * Se o valor for negativo, o saldo diminui (sua parte em uma despesa).
     * * @param valor Valor a ser somado ao saldo.
     */
    void atualizarSaldo(float valor);
};
#endif // MORADOR_HPP

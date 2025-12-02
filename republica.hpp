#ifndef REPUBLICA_HPP
#define REPUBLICA_HPP
#include <vector>
#include <string>
// Forward declarations para evitar inclusão circular e reduzir tempo de compilação
class Morador;
class Despesa;
class Pagamento;
/**
 * @brief Classe principal que gerencia a república.
 * * A classe Republica atua como o controlador central do sistema.
 * Suas responsabilidades incluem:
 * - Gerenciar a lista de moradores (adicionar, buscar).
 * - Gerenciar o histórico de despesas e pagamentos.
 * - Realizar o registro de novas transações financeiras.
 * - Gerar relatórios de saldo e fechamento.
 */
class Republica {
private:
    /**
     * @brief Lista de ponteiros para os moradores da república.
     */
    std::vector<Morador*> moradores_;
    /**
     * @brief Histórico de todas as despesas registradas (Comuns e Individuais).
     * Armazena ponteiros para a classe base Despesa (Polimorfismo).
     */
    std::vector<Despesa*> despesas_;
    /**
     * @brief Histórico de pagamentos (amortizações) entre moradores.
     */
    std::vector<Pagamento*> pagamentos_;
public:
    /**
     * @brief Construtor padrão da República.
     */
    Republica();
    /**
     * @brief Destrutor da República.
     * Responsável por liberar a memória de todos os objetos (Moradores, Despesas, Pagamentos)
     * alocados dinamicamente.
     */
    ~Republica();
    /**
     * @brief Adiciona um novo morador à república.
     * * @param nome Nome do morador.
     * @param email Email do morador.
     */
    void adicionarMorador(std::string nome, std::string email);
    /**
     * @brief Busca um morador pelo nome.
     * * @param nome Nome do morador a ser buscado.
     * @return Morador* Ponteiro para o morador encontrado ou nullptr se não existir.
     */
    Morador* buscarMorador(std::string nome);
    /**
     * @brief Registra uma despesa comum (dividida entre vários moradores).
     * * Cria uma nova DespesaComum, calcula a divisão e atualiza os saldos.
     * * @param pagador Ponteiro para o morador que pagou a despesa.
     * @param valor Valor total da despesa.
     * @param data Data da despesa (string).
     * @param categoria Categoria da despesa (ex: "Alimentação").
     * @param envolvidos Vetor de ponteiros para os moradores que dividirão a conta.
     */
    void registrarDespesaComum(Morador* pagador, float valor, std::string data, std::string categoria, std::vector<Morador*> envolvidos);
    /**
     * @brief Registra uma despesa individual (atribuída a um único morador).
     * * @param pagador Ponteiro para o morador que pagou a despesa.
     * @param valor Valor total da despesa.
     * @param data Data da despesa.
     * @param categoria Categoria da despesa.
     * @param responsavel Ponteiro para o morador responsável pela despesa (quem deve pagar).
     */
    void registrarDespesaIndividual(Morador* pagador, float valor, std::string data, std::string categoria, Morador* responsavel);
    /**
     * @brief Registra um pagamento direto (amortização) entre dois moradores.
     * * Útil para quando um morador paga sua dívida para outro.
     * O saldo do pagador aumenta (menos dívida) e o do recebedor diminui (menos crédito).
     * * @param pagador Quem está pagando a dívida.
     * @param recebedor Quem está recebendo o dinheiro.
     * @param valor Valor pago.
     * @param data Data do pagamento.
     */
    void registrarPagamento(Morador* pagador, Morador* recebedor, float valor, std::string data);
    /**
     * @brief Exibe no terminal o saldo atual de todos os moradores.
     */
    void exibirSaldos();
    /**
     * @brief Exibe no terminal o histórico de despesas e pagamentos.
     */
    void exibirHistorico();
    /**
     * @brief Gera o relatório de fechamento de contas.
     * Pode incluir sugestões de pagamentos para zerar as dívidas.
     */
    void gerarRelatorioFechamento();
};
#endif // REPUBLICA_HPP

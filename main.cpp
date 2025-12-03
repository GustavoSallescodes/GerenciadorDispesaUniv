#include <iostream>
#include "morador.hpp"
#include "pagamento.hpp"
#include "despesa_comum.hpp"
#include "despesa_individual.hpp"
#include "republica.hpp"

using namespace std;

int main() {

    // Criando a república
    Republica rep("República do Salles");

    // Criando moradores
    Morador* guga = new Morador("Gustavo Salles", "guga@email.com");
    Morador* joao = new Morador("João Silva", "joao@email.com");
    Morador* ana  = new Morador("Ana Clara", "ana@email.com");

    rep.adicionarMorador(guga);
    rep.adicionarMorador(joao);
    rep.adicionarMorador(ana);

    // Pagamentos feitos por moradores
    Pagamento p1(guga, 120.0f, "01/02/2025", "Pagamento do aluguel");
    Pagamento p2(joao, 80.0f, "02/02/2025", "Pagamento parcial do mercado");

    // Despesa comum (divide entre todos da república)
    DespesaComum luz("Conta de Luz", 150.0f, guga);
    luz.distribuir(rep.getMoradores());

    // Despesa individual (só afeta um morador específico)
    DespesaIndividual compra("Headset novo", 200.0f, ana);
    compra.aplicar();

    // --- EXIBIÇÃO DE RESULTADOS ---
    cout << "\n========== SALDOS FINAIS ==========\n";
    rep.listarMoradoresComSaldo();

    // Liberação de memória
    rep.liberarMemoria();

    return 0;
}
 

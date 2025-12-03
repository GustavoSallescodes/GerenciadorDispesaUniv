#ifndef DESPESA_COMUM_HPP
#define DESPESA_COMUM_HPP

#include "despesa.hpp"
#include <vector>

class Morador;

class DespesaComum : public Despesa {
private:
    std::vector<Morador*> moradores_envolvidos_;

public:
    DespesaComum(float valor,
                 std::string data,
                 std::string categoria,
                 Morador* pagador,
                 std::vector<Morador*> envolvidos);

    void dividir() override;
};

#endif


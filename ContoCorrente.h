

#ifndef CONTO_CORRENTE_CONTOCORRENTE_H
#define CONTO_CORRENTE_CONTOCORRENTE_H
#include <string>
#include <vector>
#include "Transazione.h"


class ContoCorrente {
public :
    explicit ContoCorrente (const std::string& intestatario);
    void addTransazione (const Transazione& transazione);
    double getSaldoAttuale() const;
    std::vector <Transazione> getStoricoTransazioni() const;
    bool caricaDaFile ();
    bool salvaSuFile () const;

private:
    std::string nomeFile;
    std::vector <Transazione> transazioni;




};


#endif //CONTO_CORRENTE_CONTOCORRENTE_H

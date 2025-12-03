#ifndef CONTO_CORRENTE_CONTOCORRENTE_H
#define CONTO_CORRENTE_CONTOCORRENTE_H
#include <string>
#include <vector>
#include "Transazione.h"


class ContoCorrente {
public :
    ContoCorrente (const std::string& nomeFile, const std::string& intestatario, const std::string& iban);

    void addTransazione (const Transazione& transazione);
    double getSaldo() const;
    std::string getIntestatario() const;
    std::vector <Transazione> getTransazioni() const;
    bool caricaDaFile ();
    bool salvaSuFile () const;
    std::string getIban() const;

private:
    std::string nomeFile;
    std::vector <Transazione> transazioni;
    std::string intestatario;
    std::string iban;




};


#endif //CONTO_CORRENTE_CONTOCORRENTE_H

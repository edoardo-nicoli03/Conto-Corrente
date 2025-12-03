#include "../include/ContoCorrente.h"
#include <fstream>
#include <iostream>


ContoCorrente::ContoCorrente(const std::string& nF, const std::string& intes, const std::string& ib)
        : nomeFile(nF), intestatario(intes), iban(ib){
}

void ContoCorrente::addTransazione(const Transazione& t) {
    transazioni.push_back(t);
}


std::string ContoCorrente::getIntestatario() const{
    return intestatario;
}
std::string ContoCorrente::getIban() const{
    return iban;
}


double ContoCorrente::getSaldo() const {
    double saldo = 0.0;
    for (const auto& t : transazioni){
        saldo += t.getImporto();
    }
    return saldo;
}

std::vector<Transazione> ContoCorrente::getTransazioni() const {
    return transazioni;
}

bool ContoCorrente::caricaDaFile() {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cout << "Il file " << nomeFile << " non è stato aperto correttamente" << std::endl;
        return false;
    }
    transazioni.clear();
    std::string dataLetta;
    std::string descrizioneLetta;
    double importoLetto;

    while (file >> dataLetta >> importoLetto >> descrizioneLetta) {
        Transazione t(importoLetto, descrizioneLetta, dataLetta);
        transazioni.push_back(t);

    }
    file.close();
    return true;
}




bool ContoCorrente::salvaSuFile() const {
    std::ofstream file(nomeFile);

    if (!file.is_open()) {
        std::cout << "Il file " << nomeFile << " non è stato aperto correttamente" << std::endl;
        return false;

    }


    for (const auto& t : transazioni) {
        file << t.getData() << " " << t.getImporto() << " " << t.getDescrizione() << "\n";
    }

    file.close();
    return true;
}

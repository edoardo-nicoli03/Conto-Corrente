
#include "../include/ContoCorrente.h"
#include <fstream>
#include <sstream>
#include <iostream>


ContoCorrente::ContoCorrente(const std::string& nomeFile)
        : nomeFile(nomeFile) {
}
void ContoCorrente::addTransazione(const Transazione& transazione) {
    transazioni.push_back(transazione);
}

double ContoCorrente::getSaldoAttuale() const {
    double saldo = 0.0;
    for (const auto& transazione : transazioni){
        saldo += transazione.getImporto();
    }
    return saldo;
}

std::vector<Transazione> ContoCorrente::getStoricoTransazioni() const {
    return transazioni;
}

bool ContoCorrente ::caricaDaFile() {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cout << "Impossibile aprire il file: " << nomeFile << std::endl;
        return false;
    }

    transazioni.clear();
    std::string riga;
    while (std::getline(file, riga)) {
        try {
            Transazione transazione = Transazione::daStringaCsv(riga);
            transazioni.push_back(transazione);
        } catch (const std::exception& e) {
            std::cerr << "Errore nel caricamento della transazione: " << e.what() << std::endl;
        }
    }

    file.close();
    return true;
}
bool ContoCorrente::salvaSuFile() const {
    std::ofstream file(nomeFile);

    if (!file.is_open()) {
        std::cerr << "Errore fatale: Impossibile aprire il file '" << nomeFile << "' in scrittura." << std::endl;
        return false;
    }

    for (const auto& t : transazioni) {
        file << t.aStringaCsv() << "\n";
    }

    file.close();
    return true;
}
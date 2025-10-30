#include <iostream>
#include <iomanip>
#include "../include/ContoCorrente.h"

void stampaStorico(const std::vector<Transazione>& transazioni) {
    std::cout << "\n--- Storico Transazioni ---\n";
    std::cout << std::left << std::setw(12) << "Data"
              << std::right << std::setw(12) << "Importo"
              << "  " << std::left << "Descrizione\n";

    for (const auto& t : transazioni) {
        std::cout << std::left << std::setw(12) << t.getData()
                  << std::right << std::setw(10) << std::fixed << std::setprecision(2)
                  << t.getImporto() << " euro "
                  << "  " << std::left << t.getDescrizione() << "\n";
    }
}

int main() {
    std::cout << "Gestione Conto Corrente\n\n";

    ContoCorrente conto("conto.csv");

    conto.addTransazione(Transazione(2500.00, "Stipendio", "2025-10-01"));
    conto.addTransazione(Transazione(500.00, "Bonus", "2025-10-05"));
    conto.addTransazione(Transazione(-800.00, "Affitto", "2025-10-05"));
    conto.addTransazione(Transazione(-150.50, "Spesa supermercato", "2025-10-08"));
    conto.addTransazione(Transazione(-85.30, "Bolletta", "2025-10-10"));
    conto.addTransazione(Transazione(-45.00, "Palestra", "2025-10-12"));
    conto.addTransazione(Transazione(120.00, "Rimborso", "2025-10-15"));
    conto.addTransazione(Transazione(-65.00, "Ristorante", "2025-10-18"));


    stampaStorico(conto.getStoricoTransazioni());

    std::cout << "\nSaldo: " << std::fixed << std::setprecision(2)
              << conto.getSaldoAttuale() << " euro\n";


    std::cout << "\nSalvataggio su file... ";
    if (conto.salvaSuFile()) {
        std::cout << "OK\n";
    } else {
        std::cout << "ERRORE\n";
        return 1;
    }

    std::cout << "Caricamento da file... ";
    ContoCorrente conto2("conto.csv");
    if (conto2.caricaDaFile()) {
        std::cout << "OK\n";
        std::cout << "Transazioni caricate: " << conto2.getStoricoTransazioni().size() << "\n";
        std::cout << "Saldo verificato: " << std::fixed << std::setprecision(2)
                  << conto2.getSaldoAttuale() << " euro\n";
    } else {
        std::cout << "ERRORE\n";
        return 1;
    }

    std::cout << "\nTest validazione date:\n";
    try {
        Transazione t(100.0, "Test", "2025-10-30");
        std::cout << "Validazione fallita\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Data errata rilevata correttamente\n";
    }

    return 0;
}

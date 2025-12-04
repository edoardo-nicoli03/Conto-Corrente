#include <iostream>
#include <iomanip>
#include "../include/ContoCorrente.h"


int main() {

    ContoCorrente conto1("conto_mario.csv", "Mario Rossi", "IT60X0542811101000000123456");
    std::cout << "Conto di " << conto1 .getIntestatario() << " con IBAN: " << conto1 .getIban() << "\n";
    conto1.addTransazione(Transazione(30.00, "Stipendio", "2025-10-01"));
    conto1.addTransazione(Transazione(500.00, "Bonus", "2025-10-05"));
    conto1.addTransazione(Transazione(-800.00, "Affitto", "2025-10-05"));
    conto1.addTransazione(Transazione(-150.50, "Spesa_supermercato", "2025-10-08"));
    conto1.addTransazione(Transazione(-85.30, "Bolletta", "2025-10-10"));
    conto1.addTransazione(Transazione(-45.00, "Palestra", "2025-10-12"));
    conto1.addTransazione(Transazione(120.00, "Rimborso", "2025-10-15"));
    conto1.addTransazione(Transazione(-65.00, "Ristorante", "2025-10-18"));

    std::cout << "Storico transazioni\n";

    conto1.stampaStorico();

    std::cout << "\nStatistiche sul conto \n";
    std::cout << "Saldo attuale: " << conto1.getSaldo() << " euro\n";
    std::cout << "Totale entrate: " << conto1.getTotEntrate() << " euro\n";
    std::cout << "Totale uscite: " << conto1.getTotUscite() << " euro\n";

    std::cout << "\nSalvataggio su file... ";
    if (conto1.salvaSuFile()) {
        std::cout << "\nIl file e' stato salvato correttamente\n";
    } else {
        std::cout << "\nIl file non e' stato salvato correttamente\n";
        return 1;
    }

    std::cout << "Caricamento da file... ";

    ContoCorrente conto2("conto_mario.csv", "Mario Rossi", "IT60X0542811101000000123456");
    if (conto2.caricaDaFile()) {
        std::cout << "\nDati del conto caricati correttamente\n";
       conto2.stampaStorico();
    }
    else {
        std::cout << "Errore nel caricamento del file\n";
    }



    ContoCorrente conto3 ("conto_Luca.csv", "Luca Verdi", "IT60X0542811101000000123456");
    std::cout <<"\nConto di " << conto3.getIntestatario() << " con IBAN: " << conto3.getIban() << "\n";
    conto3 .addTransazione(Transazione(-300.00, "Acquisto computer", "2024-11-20"));
    conto3 .addTransazione(Transazione(1500.00, "Stipendio", "2024-11-19"));
    conto3 .addTransazione(Transazione(-200.00, "Spese viaggio", "2024-11-24"));
    std::cout << "Storico transazioni\n";
    conto3.stampaStorico();
    std::cout << "\nStatistiche sul conto \n";
    std::cout << "Saldo : " << conto3 .getSaldo() << " euro\n";
    std::cout << "Totale entrate: " << conto3 .getTotEntrate() << " euro\n";
    std::cout << "Totale uscite: " << conto3 .getTotUscite() << " euro\n";

    std::cout << "\nSalvataggio su file...";
    if (conto3.salvaSuFile()) {
        std::cout << "\nIl file e' stato salvato correttamente\n";
    } else {
        std::cout << "\nIl file non e' stato salvato correttamente\n";
    }

    return 0;
}

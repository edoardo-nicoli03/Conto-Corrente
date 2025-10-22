#include "Transazione.h"
#include <sstream>
#include <stdexcept>
#include <vector>

Transazione::Transazione(double importo, const std::string& descrizione, const std::string& data)
    : importo(importo), descrizione(descrizione), data(data) {

}

double Transazione::getImporto() const {
    return importo;
}

std::string Transazione::getDescrizione() const {
    return descrizione;
}

std::string Transazione::getData() const {
    return data;
}

std::string Transazione::aStringaCsv() const {
    std::stringstream ss;
    ss << importo << "," << descrizione << "," << data;
    return ss.str();
}
Transazione Transazione::daStringaCsv(const std::string& rigaCsv) {
    std::stringstream ss(rigaCsv);
    std::string item;
    std::vector<std::string> elementi;

    while (std::getline(ss, item, ',')) {
        elementi.push_back(item);
    }

    if (elementi.size() != 3) {
        throw std::invalid_argument("Formato CSV non valido per Transazione" + rigaCsv);
    }

    try{
    double importo = std::stod(elementi[0]);
    std::string descrizione = elementi[1];
    std::string data = elementi[2];

    return Transazione(importo, descrizione, data);

 } catch (const std::exception& e){
        throw std::runtime_error("Errore nel parsing della Transazione da CSV:" + rigaCsv + "| Errore: "+ e.what());

    }
}
#include "../include/Transazione.h"
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cctype>

bool Transazione::controlloData(const std::string& data) {
   if (data.size() != 10) {
       return false;
   }
   if (data[4] != '-'|| data[7] != '-') {
       return false;
   }
   for (int i = 0; i <= 3; i++) {
       if (!isdigit(data[i])) {
           return false;
       }
   }
   if (!isdigit(data[8]) || !isdigit(data[9])){
       return false;
   }
   return true;
}

Transazione::Transazione(double importo, const std::string& descrizione, const std::string& data)
        : importo(importo), descrizione(descrizione), data(data) {
    if (!controlloData(data)) {
        throw std::invalid_argument("Formato data non valido: " + data + " (usa YYYY-MM-DD)");
    }

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



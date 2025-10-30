#ifndef CONTO_CORRENTE_TRANSAZIONE_H
#define CONTO_CORRENTE_TRANSAZIONE_H
#include <string>

class Transazione {
public :
    Transazione (double importo, const std::string& descrizione, const std::string& data);

    double getImporto() const;
    std::string getDescrizione() const;
    std::string getData() const;

    std::string aStringaCsv() const;

    static Transazione daStringaCsv(const std::string& rigaCsv);

private:
    double importo;
    std::string descrizione;
    std::string data;
    static bool isDataValida(const std::string& data) ;
};







#endif //CONTO_CORRENTE_TRANSAZIONE_H
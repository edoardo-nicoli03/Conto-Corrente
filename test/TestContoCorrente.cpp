
#include "gtest/gtest.h" // Include la libreria GoogleTest
#include "ContoCorrente.h" // Include la classe che vogliamo testare



TEST(TestContoCorrente, SaldoInizialeZero) {
    ContoCorrente conto("test_file.csv");
    ASSERT_EQ(conto.getSaldoAttuale(), 0.0);
}

TEST(TestContoCorrente, SaldoDopoSingolaEntrata) {
    ContoCorrente conto("test_file.csv");
    Transazione entrata(100.50, "Stipendio", "2025-10-24");

    conto.addTransazione(entrata);
    ASSERT_NEAR(conto.getSaldoAttuale(), 100.50, 0.001);
}


TEST(TestContoCorrente, SaldoMistoEntrataEUscita) {
    ContoCorrente conto("test_file.csv");

    Transazione entrata(500.0, "Stipendio", "2025-10-24");
    Transazione uscita(-75.50, "Bolletta", "2025-10-25"); // Uscita negativa

    conto.addTransazione(entrata);
    conto.addTransazione(uscita);

    ASSERT_NEAR(conto.getSaldoAttuale(), 424.50, 0.001);
}

TEST(TestContoCorrente, SaldoConPiuUscite) {
    ContoCorrente conto("test_file.csv");

    Transazione entrata(100.0, "Regalo", "2025-10-24");
    Transazione uscita1(-15.0, "Caffè", "2025-10-25");
    Transazione uscita2(-30.0, "Pizza", "2025-10-25");

    conto.addTransazione(entrata);
    conto.addTransazione(uscita1);
    conto.addTransazione(uscita2);

    ASSERT_NEAR(conto.getSaldoAttuale(), 55.0, 0.001);
}

TEST(TestContoCorrente, SalvataggioECaricamento) {
    ContoCorrente conto1("test_io.csv");
    conto1.addTransazione(Transazione(1000.0, "Stipendio", "2025-10-01"));
    conto1.addTransazione(Transazione(-50.0, "Spesa", "2025-10-05"));
    conto1.addTransazione(Transazione(-200.0, "Affitto", "2025-10-10"));

    ASSERT_TRUE(conto1.salvaSuFile());

    ContoCorrente conto2("test_io.csv");
    ASSERT_TRUE(conto2.caricaDaFile());

    ASSERT_NEAR(conto2.getSaldoAttuale(), 750.0, 0.001);

    ASSERT_EQ(conto2.getStoricoTransazioni().size(), 3);
}

TEST(TestContoCorrente, CaricamentoDaFileInesistente) {
    ContoCorrente conto("file_che_non_esiste.csv");
    ASSERT_FALSE(conto.caricaDaFile());
    ASSERT_EQ(conto.getSaldoAttuale(), 0.0);
}

TEST(TestTransazione, ConversioneCsvAndata_e_Ritorno) {
    Transazione originale(123.45, "Test descrizione", "2025-10-30");


    std::string csv = originale.aStringaCsv();

    Transazione ricostruita = Transazione::daStringaCsv(csv);

    // Verifica che i dati siano identici
    ASSERT_NEAR(ricostruita.getImporto(), 123.45, 0.001);
    ASSERT_EQ(ricostruita.getDescrizione(), "Test descrizione");
    ASSERT_EQ(ricostruita.getData(), "2025-10-30");
}
TEST(TestTransazione, DataValida) {
    // Questo deve funzionare
    ASSERT_NO_THROW({
                        Transazione t(100.0, "Test", "2025-10-30");
                    });
}

TEST(TestTransazione, DataNonValida_FormatoErrato) {
    // Data senza trattini
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "20251030");
                 }, std::invalid_argument);
}

TEST(TestTransazione, DataNonValida_Lettere) {
    // Data con lettere
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "202A-10-30");
                 }, std::invalid_argument);
}

TEST(TestTransazione, DataNonValida_Corta) {
    // Data troppo corta
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "2025-1-1");
                 }, std::invalid_argument);
}
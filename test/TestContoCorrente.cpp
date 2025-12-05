#include "gtest/gtest.h"
#include "ContoCorrente.h"



TEST(TestContoCorrente, SaldoInizialeZero) {
    ContoCorrente conto("test_file.csv", "Mario Rossi", "IT60X0542811101000000123456");
    ASSERT_EQ(conto.getSaldo(), 0.0);
}

TEST(TestContoCorrente, SaldoDopoSingolaEntrata) {
    ContoCorrente conto("test_file.csv", "Mario Rossi", "IT60X0542811101000000123456");
    Transazione entrata(100.50, "Stipendio", "2025-10-24");

    conto.addTransazione(entrata);
    ASSERT_NEAR(conto.getSaldo(), 100.50, 0.001);
}


TEST(TestContoCorrente, SaldoMistoEntrataEUscita) {
    ContoCorrente conto("test_file.csv", "Mario Rossi", "IT60X0542811101000000123456");

    Transazione entrata(500.0, "Stipendio", "2025-10-24");
    Transazione uscita(-75.50, "Bolletta", "2025-10-25");

    conto.addTransazione(entrata);
    conto.addTransazione(uscita);

    ASSERT_NEAR(conto.getSaldo(), 424.50, 0.001);
}

TEST(TestContoCorrente, SaldoConPiuUscite) {
    ContoCorrente conto("test_file.csv", "Mario Rossi", "IT60X0542811101000000123456");

    Transazione entrata(100.0, "Regalo", "2025-10-24");
    Transazione uscita1(-15.0, "Caffè", "2025-10-25");
    Transazione uscita2(-30.0, "Pizza", "2025-10-25");

    conto.addTransazione(entrata);
    conto.addTransazione(uscita1);
    conto.addTransazione(uscita2);

    ASSERT_NEAR(conto.getSaldo(), 55.0, 0.001);
}

TEST(TestContoCorrente, SalvataggioECaricamento) {
    ContoCorrente conto1("test_io.csv", "Mario Rossi", "IT60X0542811101000000123456");
    conto1.addTransazione(Transazione(1000.0, "Stipendio", "2025-10-01"));
    conto1.addTransazione(Transazione(-50.0, "Spesa", "2025-10-05"));
    conto1.addTransazione(Transazione(-200.0, "Affitto", "2025-10-10"));

    ASSERT_TRUE(conto1.salvaSuFile());

    ContoCorrente conto2("test_io.csv", "Giovanni Rossi", "IT60X054281110100000012356");
    ASSERT_TRUE(conto2.caricaDaFile());

    ASSERT_NEAR(conto2.getSaldo(), 750.0, 0.001);

}
TEST(TestContoCorrente, CaricamentoDaFileInesistente) {
    ContoCorrente conto("file_che_non_esiste.csv", "Mario Rossi", "IT60X0542811101000000123456");
    ASSERT_FALSE(conto.caricaDaFile());
    ASSERT_EQ(conto.getSaldo(), 0.0);
}


TEST(TestTransazione, DataValida) {
    ASSERT_NO_THROW({
                        Transazione t(100.0, "Test", "2025-10-30");
                    });
}

TEST(TestTransazione, DataNonValida_FormatoErrato) {
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "20251030");
                 }, std::invalid_argument);
}

TEST(TestTransazione, DataNonValida_Lettere) {
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "202A-10-30");
                 }, std::invalid_argument);
}

TEST(TestTransazione, DataNonValida_Corta) {
    ASSERT_THROW({
                     Transazione t(100.0, "Test", "2025-1-1");
                 }, std::invalid_argument);
}


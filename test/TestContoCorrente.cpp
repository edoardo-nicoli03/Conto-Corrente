
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
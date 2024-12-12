#include <gtest/gtest.h>
#include "../include/Studentas.h"
#include <vector>

// Testas konstruktoriui su parametrais
TEST(StudentasTest, ParametrizedConstructor) {
    std::vector<double> nd = {8.5, 9.0, 7.5};
    Studentas s("Jonas", "Jonaitis", nd, 9.0);

    EXPECT_EQ(s.getVardas(), "Jonas");
    EXPECT_EQ(s.getPavarde(), "Jonaitis");
    EXPECT_EQ(s.getNd().size(), 3);
    EXPECT_EQ(s.getEgz(), 9.0);
    EXPECT_EQ(s.getGalutinis(), 0);
}

// Testas priskyrimo operatoriui
TEST(StudentasTest, AssignmentOperator) {
    std::vector<double> nd = {9.0, 8.0, 7.5};
    Studentas s1("Jonas", "Jonaitis", nd, 9.0);
    Studentas s2("Rimas", "Rimaitis", nd, 7.5);

    s2 = s1;

    EXPECT_EQ(s2.getVardas(), s1.getVardas());
    EXPECT_EQ(s2.getPavarde(), s1.getPavarde());
    EXPECT_EQ(s2.getNd(), s1.getNd());
    EXPECT_EQ(s2.getEgz(), s1.getEgz());
    EXPECT_EQ(s2.getGalutinis(), s1.getGalutinis());
}

// Testas galutinio įvertinimo apskaičiavimui pagal vidurkį
TEST(StudentasTest, IvertinimasVidurkis) {
    std::vector<double> nd = {8.0, 7.0, 9.0};
    Studentas s("Marius", "Mariunaitis", nd, 8.0);
    
    s.Ivertinimas_vid();

    double expectedGalutinis = 0.4 * 8.0 + 0.6 * 8.0;
    EXPECT_EQ(s.getGalutinis(), expectedGalutinis);
}

// Testas galutinio įvertinimo apskaičiavimui pagal medianą
TEST(StudentasTest, IvertinimasMediana) {
    std::vector<double> nd = {8.0, 7.0, 9.0};
    Studentas s("Petras", "Petraitis", nd, 8.0);

    s.Ivertinimas_med();

    double expectedGalutinis = 0.4 * 8.0 + 0.6 * 8.0;
    EXPECT_EQ(s.getGalutinis(), expectedGalutinis);
}




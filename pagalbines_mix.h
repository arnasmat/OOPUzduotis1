#ifndef PAGALBINES_MIX_H
#define PAGALBINES_MIX_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

struct Studentas {
    std::string vardas{}, pavarde{};
    unsigned int pazymiu_kiekis{0};
    unsigned int *pazymiai{nullptr};
    unsigned int egzamino_rezultatas{};
};

void studentu_ivestis(std::vector<Studentas>& studentai);
float galutinis_pazymys_vidurkis(Studentas &studentas);
float galutinis_pazymys_mediana(Studentas &studentas);
void isvestis(std::vector<Studentas>& studentai);

#endif // PAGALBINES_MIX_H
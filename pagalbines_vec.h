#ifndef PAGALBINES_VEC_H
#define PAGALBINES_VEC_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
};

void studentu_ivestis(std::vector<Studentas>& studentai);
float galutinis_pazymys_vidurkis(Studentas &studentas);
float galutinis_pazymys_mediana(Studentas &studentas);
void isvestis(std::vector<Studentas>& studentai);

#endif // PAGALBINES_VEC_H
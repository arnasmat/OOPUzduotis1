#ifndef PAGALBINES_VEC_H
#define PAGALBINES_VEC_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <fstream>

struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
    float galutinis_vidurkis{};
    float galutinis_mediana{};
};

float galutinis_pazymys_vidurkis(Studentas &studentas);

#endif // PAGALBINES_VEC_H
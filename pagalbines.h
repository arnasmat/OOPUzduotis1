#ifndef PAGALBINES_H
#define PAGALBINES_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>

struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
    float galutinis_vidurkis{};
    float galutinis_mediana{};
};

float galutinis_pazymys_vidurkis(Studentas &studentas);
void isvestis(std::vector<Studentas>& studentai, std::ostream& output_method);

#endif // PAGALBINES_H
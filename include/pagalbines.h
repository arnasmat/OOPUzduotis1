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
#include <filesystem>
namespace fs = std::filesystem;

struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
    float galutinis_vidurkis{};
    float galutinis_mediana{};
};

extern std::random_device rd;
extern std::mt19937 mt;

#endif // PAGALBINES_H
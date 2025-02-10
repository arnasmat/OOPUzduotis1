#ifndef PAGALBINES_MIX_H
#define PAGALBINES_MIX_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <random>

struct Studentas {
    std::string vardas{}, pavarde{};
    unsigned int pazymiu_kiekis{0};
    unsigned int *pazymiai{nullptr};
    unsigned int egzamino_rezultatas{};
};

#endif // PAGALBINES_MIX_H
//
// Created by User on 2025-02-07.
//

#ifndef PAGALBINES_H
#define PAGALBINES_H

#include <iostream>
#include <vector>
#include <cmath>

struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
};

void galutinis_pazymys(Studentas &studentas);

#endif //PAGALBINES_H

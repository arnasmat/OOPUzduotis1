//
// Created by User on 2025-02-19.
//

#ifndef IVESTIES_PAGALBINES_H
#define IVESTIES_PAGALBINES_H

#include "pagalbines.h"

int ivesties_patikrinimas(int nuo, int iki);
int ivesties_patikrinimas(int nuo, int iki, int sustabdymo_salyga);
void random_pazymiu_generavimas(Studentas& laikinas_studentas);

//Apibrezti template faile. Naudoja ne vector, o template
/*void vardu_ivestis(const std::vector<Studentas>& studentai, Studentas &laikinas_studentas);*/

#include <template/ivesties_pagalbines.tpp>

#endif //IVESTIES_PAGALBINES_H

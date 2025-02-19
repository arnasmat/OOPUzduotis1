//
// Created by User on 2025-02-19.
//

#ifndef IVESTIES_PAGALBINES_H
#define IVESTIES_PAGALBINES_H

#include "pagalbines.h"



int ivesties_patikrinimas(const int nuo, const int iki);
int ivesties_patikrinimas(const int nuo, const int iki, const int sustabdymo_salyga);
void vardu_ivestis(const std::vector<Studentas>& studentai, Studentas &laikinas_studentas);
void random_pazymiu_generavimas(Studentas& laikinas_studentas);


#endif //IVESTIES_PAGALBINES_H

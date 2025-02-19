//
// Created by User on 2025-02-19.
//

#ifndef IVESTIES_FUNKCIJOS_H
#define IVESTIES_FUNKCIJOS_H

#include "pagalbines.h"

int meniu(const fs::path &ivesties_failo_pavadinimas);
void studentu_ivestis(std::vector<Studentas>& studentai);
void studentu_ivestis_random_2(std::vector<Studentas>& studentai);
void studentu_ivestis_random_3(std::vector<Studentas>& studentai);
void studentu_ivestis_is_failo(std::vector<Studentas>& studentai, const fs::path& failo_pavadinimas, bool& praejo);
double ivesties_testavimas(bool& praejo);

#endif //IVESTIES_FUNKCIJOS_H

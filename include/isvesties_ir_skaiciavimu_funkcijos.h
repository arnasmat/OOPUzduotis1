//
// Created by User on 2025-02-19.
//

#ifndef ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H
#define ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

#include "pagalbines.h"

float galutinis_pazymys_vidurkis(Studentas &studentas);
float galutinis_pazymys_mediana(Studentas &studentas);
void isvesties_meniu(std::vector<Studentas>& studentai, const std::string &isvesties_failo_pavadinimas);
void isvestis(std::vector<Studentas>& studentai, std::ostream& isvesties_metodas);

#endif //ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

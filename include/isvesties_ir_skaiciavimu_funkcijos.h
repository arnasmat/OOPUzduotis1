//
// Created by User on 2025-02-19.
//

#ifndef ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H
#define ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

#include "pagalbines.h"
#include "rusiavimo_funkcijos.h"
#include "ivesties_pagalbines.h"

void failu_generavimas(int studentu_kiekis);
float galutinis_pazymys_vidurkis(Studentas &studentas);
float galutinis_pazymys_mediana(Studentas &studentas);

//Apibrezti template faile. Naudoja ne vector, o template
/* void isvesties_meniu(Container& studentai, const std::string &isvesties_failo_pavadinimas)
 * void isvestis(Container& studentai, std::ostream& isvesties_metodas, const int rodyti_pasirinkimas) */

#include "template/isvesties_ir_skaiciavimu_funkcijos.tpp"

#endif //ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

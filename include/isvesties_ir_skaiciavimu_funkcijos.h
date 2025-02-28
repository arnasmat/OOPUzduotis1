//
// Created by User on 2025-02-19.
//

#ifndef ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H
#define ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

#include "pagalbines.h"

void failu_generavimas(int studentu_kiekis);
float galutinis_pazymys_vidurkis(Studentas &studentas);
float galutinis_pazymys_mediana(Studentas &studentas);
void isvesties_meniu(std::vector<Studentas>& studentai, const std::string &isvesties_failo_pavadinimas);
void isvestis(std::vector<Studentas>& studentai, std::ostream& isvesties_metodas, int rodyti_pasirinkimas);
void studentu_kategorizacija(std::vector<Studentas>& studentai, int rodyti_pasirinkimas, int rusiavimo_pasirinkimas);
void studentu_kategorizacija_testavimas(std::vector<Studentas>& studentai, int rodyti_pasirinkimas, int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, int i);

#endif //ISVESTIES_IR_SKAICIAVIMU_FUNKCIJOS_H

//
// Created by User on 2025-03-06.
//

#ifndef TESTAVIMO_FUNKCIJOS_H
#define TESTAVIMO_FUNKCIJOS_H

#include <pagalbines.h>
#include <failu_pasirinkimo_funkcijos.h>
#include <ivesties_funkcijos.h>
#include <ivesties_pagalbines.h>
#include <rusiavimo_funkcijos.h>
#include <isvesties_ir_skaiciavimu_funkcijos.h>

void testavimo_rezimas(bool& praejo);
void failu_kurimo_testavimas(const std::vector<int>& kiekiai);
void ivesties_testavimas(bool& praejo);


void nuskaitymo_ir_isvesties_testavimas(const std::vector<int>& kiekiai, bool& praejo);
/*void studentu_kategorizacija_testavimas(std::vector<Studentas>& studentai, int rodyti_pasirinkimas, int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, int i);*/

#include <template/testavimo_funkcijos.tpp>

#endif //TESTAVIMO_FUNKCIJOS_H

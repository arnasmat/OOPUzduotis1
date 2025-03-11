//
// Created by User on 2025-02-19.
//

#ifndef IVESTIES_FUNKCIJOS_H
#define IVESTIES_FUNKCIJOS_H

#include "pagalbines.h"
#include <ivesties_pagalbines.h>
#include <failu_pasirinkimo_funkcijos.h>

int meniu(const fs::path &ivesties_failo_pavadinimas);
//Apibrezti template faile. Naudoja ne vector, o template
/*void studentu_ivestis(std::vector<Studentas>& studentai);
void studentu_ivestis_random_2(std::vector<Studentas>& studentai);
void studentu_ivestis_random_3(std::vector<Studentas>& studentai);
void studentu_ivestis_is_failo(std::vector<Studentas>& studentai, const fs::path& failo_pavadinimas, bool& praejo);*/

#include <template/ivesties_funkcijos.tpp>

#endif //IVESTIES_FUNKCIJOS_H

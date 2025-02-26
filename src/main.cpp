//
// Created by User on 2025-02-10.
//

#include "../include/pagalbines.h"
#include "../include/ivesties_funkcijos.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"
#include "../include/failu_pasirinkimo_funkcijos.h"
#include "../include/failu_generavimas.h"
#include "../include/ivesties_pagalbines.h"

int main() {
    const std::string isvesties_failo_pavadinimas{"rezultatai.txt"};
    fs::path ivesties_failas{"../data/input/kursiokai.txt"};

    std::vector<Studentas> studentai;
    while(true){

        int menu{meniu(ivesties_failas)};
        bool praejo{true};
        switch(menu) {
            case 1:
                studentu_ivestis(studentai);
            break;
            case 2:
                studentu_ivestis_random_2(studentai);
            break;
            case 3:
                studentu_ivestis_random_3(studentai);
            break;
            case 4:
                studentu_ivestis_is_failo(studentai, ivesties_failas, praejo);
            break;
            case 5:
                ivesties_failas = pasirinkti_faila_is_visu();
                praejo = false;
            break;
            case 6: {
                double laikas{ivesties_testavimas(praejo)};
                std::cout<<"Vidutinis failo skaitymo laikas: "<<laikas<<"\n";
                praejo=false;
                break;
            }
            case 7: {
                std::cout<<"Iveskite studentu kieki generuojame faile: \n";
                int studentu_kiekis{ivesties_patikrinimas(1,10000000)};
                failu_generavimas(studentu_kiekis);
                praejo = false;
                break;
            }
            default:
                return 0;
        }
        if(praejo)
            isvesties_meniu(studentai, isvesties_failo_pavadinimas);
    }

}


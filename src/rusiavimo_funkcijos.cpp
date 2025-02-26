//
// Created by User on 2025-02-26.
//

#include "../include/rusiavimo_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"

void studentu_kategorizacija(std::vector<Studentas>& studentai) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog graziau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    std::cout<<"Pagal ka rusiuoti studentus: \n"
    <<"1. Galutini pazymi pagal vidurki"
    <<"2. Galutini pazymi pagal mediana";

    int rusiuoti_pagal = ivesties_patikrinimas(1,2);
    if(rusiuoti_pagal == 1) {
        for(auto& i: studentai) {
                i.galutinis_vidurkis = galutinis_pazymys_vidurkis(i);
        }
    } else {
        for(auto& i: studentai) {
            i.galutinis_vidurkis = galutinis_pazymys_mediana(i);
        }
    }
}

void studentu_rusiavimas(std::vector<Studentas>& studentai, int rusiavimo_pasirinkimas) {
    switch(rusiavimo_pasirinkimas) {
        case 1:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.vardas < b.vardas;
            }); break;
        case 2:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.pavarde < b.pavarde;
            }); break;
        case 3:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.galutinis_vidurkis > b.galutinis_vidurkis;
            }); break;
        case 4:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.galutinis_vidurkis < b.galutinis_vidurkis;
            }); break;
        case 5:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
            return a.galutinis_mediana > b.galutinis_mediana;
            }); break;
        case 6:
            std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
            return a.galutinis_mediana < b.galutinis_mediana;
            }); break;
        default:
            break;
    }
}

void studentu_galutiniu_pazymiu_skaiciavimas(std::vector<Studentas>& studentai) {
    //Patikrina, ar paskutinio studento galutinis pazymys apskaiciuotas, kad nebutu pertekliniu skaiciavimu
    if(studentai.back().galutinis_vidurkis == 0 || studentai.back().galutinis_mediana == 0) {
        for(auto &i: studentai) {
            i.galutinis_vidurkis = galutinis_pazymys_vidurkis(i);
            i.galutinis_mediana = galutinis_pazymys_mediana(i);
        }
    }
}

//
// Created by User on 2025-02-26.
//

#include "../include/rusiavimo_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"

void studentu_kategorizacija(std::vector<Studentas>& studentai) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    std::cout<<"Pagal ka kategorizuoti studentus: \n"
    <<"1. Galutini pazymi pagal vidurki\n"
    <<"2. Galutini pazymi pagal mediana\n";

    int kategorizuoti_pagal = ivesties_patikrinimas(1,2);

    //jeigu jie visad surusiuoti, tai gal su kokiu binary searcho algoritmu?
    //std::partition_point turbut, bet tng db, kol kas ir O(n) tiks, nebutina O(logn) lol
    //Tik tada butinai reiketu patikrinimus, kad vektorius surusiuotas pagal vid arba med.. aaaajjjj echhhh
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    if(kategorizuoti_pagal == 1) {
        for(auto& i: studentai) {
            if(i.galutinis_vidurkis >= 5.0f) {
                islaike_studentai.push_back(i);
            } else {
                neislaike_studentai.push_back(i);
            }
        }
    } else {
        for(auto& i: studentai) {
            if(i.galutinis_mediana >= 5.0f) {
                islaike_studentai.push_back(i);
            } else {
                neislaike_studentai.push_back(i);
            }
        }
    }
    try {
        std::ofstream islaike_output("../data/output/islaike_studentai.txt");
        isvestis(islaike_studentai, islaike_output, 3, 3);
        islaike_output.close();
        std::ofstream neislaike_output("../data/output/neislaike_studentai.txt");
        isvestis(neislaike_studentai, neislaike_output, 3, 3);
        neislaike_output.close();
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida isvedant i failus failus: "<<e.what()<<"\n";
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

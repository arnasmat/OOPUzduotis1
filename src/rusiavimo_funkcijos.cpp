//
// Created by User on 2025-02-26.
//

#include "../include/rusiavimo_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"

void studentu_kategorizacija(std::vector<Studentas>& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    std::vector<Studentas> islaike_studentai{};
    std::vector<Studentas> neislaike_studentai{};

    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    if(rusiuoti_pagal==1 || rusiuoti_pagal==2) {
        std::cout<<"Studentu kategorizacija automatiskai vykdoma pagal vidurki, nes jusu pasirinkimas netinkamas kategorizacijai";
        studentu_rusiavimas(studentai, 3);
    } else {
        studentu_rusiavimas(studentai, rusiuoti_pagal);
    }

    if(rusiuoti_pagal == 3) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal == 4) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
    }else if(rusiuoti_pagal==5){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal==6){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
    }

    studentai.clear();
    try {
        std::ofstream islaike_output("../data/output/islaike_studentai.txt");
        isvestis(islaike_studentai, islaike_output, rodyti_pasirinkimas);
        islaike_output.close();
        std::ofstream neislaike_output("../data/output/neislaike_studentai.txt");
        isvestis(neislaike_studentai, neislaike_output, rodyti_pasirinkimas);
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

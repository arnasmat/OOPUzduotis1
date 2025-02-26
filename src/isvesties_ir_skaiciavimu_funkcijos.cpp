//
// Created by User on 2025-02-19.
//

#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/rusiavimo_funkcijos.h"

void failu_generavimas(int studentu_kiekis){
    // std::vector<Studentas> studentai{};
    // studentai.reserve(studentu_kiekis);

    std::ostringstream output{""};
    std::uniform_int_distribution<int> random_kiekis(5, 15);

    int isvesties_vardo_ilgis{static_cast<int>(("Vardas"+ std::to_string(studentu_kiekis)).length() > 6 ? ("Vardas"+ std::to_string(studentu_kiekis)).length() + 2 : 8)};
    int isvesties_pavardes_ilgis{static_cast<int>(("Pavarde"+ std::to_string(studentu_kiekis)).length() > 7 ? ("Pavarde"+ std::to_string(studentu_kiekis)).length() + 2 : 8)};

    int pazymiu_kiekis = random_kiekis(mt);
    output<<std::left<<std::setw(isvesties_vardo_ilgis)
        <<"Vardas"
        <<std::left<<std::setw(isvesties_pavardes_ilgis)
        <<"Pavarde";
    for(int i=0; i<pazymiu_kiekis; i++) {
        //jei netingesiu paziuret kaip cia padaryt be to_str nes kazkaip negraziai kodas atrodo, bet su << susimaiso ju layoutas
        output<<std::left<<std::setw(5)<<"ND"+std::to_string(i+1);
    }
    output<<"Egz.\n";

    std::uniform_int_distribution<int> random_pazymys(1, 10);

    for(int i=0; i<studentu_kiekis; i++) {
        //Vardo ir pavardes generavimas failui
        output<<std::left<<std::setw(isvesties_vardo_ilgis)<<"Vardas" + std::to_string(i+1)
            <<std::left<<std::setw(isvesties_pavardes_ilgis)<<"Pavarde" + std::to_string(i+1);
        //Namu darbu ivertinimu generavimas
        for(int j=0; j<pazymiu_kiekis; j++) {
            output<<std::left<<std::setw(5)<< random_pazymys(mt);
        }
        //Egzamino rezultato generavimas
        output<<random_pazymys(mt)<<"\n";
    }

    std::ofstream isvesties_failas("../data/output/studentai_isvestis" + std::to_string(studentu_kiekis) + ".txt");
    isvesties_failas<<output.str();
    isvesties_failas.close();
}

float galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    if(studentas.pazymiai.empty()) return 0;;
    for(const auto &i: studentas.pazymiai) {
        pazymiu_suma+=i;
    }
    return static_cast<float>(static_cast<float>(pazymiu_suma) / static_cast<float>(studentas.pazymiai.size()) * 0.4 + studentas.egzamino_rezultatas * 0.6);
}

float galutinis_pazymys_mediana(Studentas &studentas) {
    float mediana{0};
    std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
if(studentas.pazymiai.size() % 2 == 0) {
    mediana = static_cast<float>(studentas.pazymiai[studentas.pazymiai.size() / 2]
        + studentas.pazymiai[studentas.pazymiai.size() / 2 - 1]) / 2.0f;
} else {
    mediana = static_cast<float>(studentas.pazymiai[studentas.pazymiai.size() / 2]);
}
    return mediana * 0.4f + static_cast<float>(studentas.egzamino_rezultatas) * 0.6f;
}

void isvesties_meniu(std::vector<Studentas>& studentai, const std::string &isvesties_failo_pavadinimas) {
    std::cout<<"Kaip norite isvesti gautus rezultatus: \n"
            <<"1. I terminala\n"
            <<"2. I faila\n";
    int isvesties_pasirinkimas{ivesties_patikrinimas(1, 2)};

    std::cout<<"Pasirinkite ka norite matyti isvedant studentus: "<<"\n"
        <<"1. Vidurki\n"
        <<"2. Mediana\n"
        <<"3. Abu (ir vidurki, ir mediana)\n";
    int rodyti_pasirinkimas{ivesties_patikrinimas(1,3)};

    std::cout<<"Pasirinkite kaip norite rusiuoti: \n"
        <<"1. Rusiuoti pagal varda\n"
        <<"2. Rusiuoti pagal pavarde\n"
        <<"3. Rusiuoti pagal galutini pazymi pagal vidurki mazejanciai\n"
        <<"4. Rusiuoti pagal galutini pazymi pagal vidurki didejanciai\n"
        <<"5. Rusiuoti pagal galutini pazymi pagal mediana mazejanciai\n"
        <<"6. Rusiuoti pagal galutini pazymi pagal mediana didejanciai\n";

    int rusiavimo_pasirinkimas{ivesties_patikrinimas(1,6)};
    if(isvesties_pasirinkimas==1) {
        isvestis(studentai, std::cout, rodyti_pasirinkimas, rusiavimo_pasirinkimas);
    } else {
        std::ofstream file(isvesties_failo_pavadinimas);
        if (file.is_open()) {
            isvestis(studentai, file, rodyti_pasirinkimas, rusiavimo_pasirinkimas);
            file.close();
        } else {
            std::cerr << "Nepavyko atidaryti isvesties failo \n";
        }
    }
}

void isvestis(std::vector<Studentas>& studentai, std::ostream& isvesties_metodas, const int rodyti_pasirinkimas, const int rusiavimo_pasirinkimas) {
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);

    studentu_rusiavimas(studentai, rusiavimo_pasirinkimas);

    int longest_name{0};
    int longest_surname{0};
    for(auto &i: studentai) {
        if(i.vardas.length() > longest_name) {
            longest_name = static_cast<int>(i.vardas.length());
        }
        if(i.pavarde.length() > longest_surname) {
            longest_surname = static_cast<int>(i.pavarde.length());
        }
    }

    int isvesties_pavardes_ilgis{((longest_surname > 7 ? longest_surname + 2 : 8))};
    int isvesties_vardo_ilgis{((longest_name > 6 ? longest_name + 2 : 8))};

    //Konvertuoti visa isvesti i viena eilute, kad ji butu greitesne.
    std::stringstream isvestis{};

    isvestis<<std::left<<std::setw(isvesties_pavardes_ilgis)<<"Pavarde"
    <<std::left<<std::setw(isvesties_vardo_ilgis)<<"Vardas";
    if(rodyti_pasirinkimas==1 || rodyti_pasirinkimas==3) {
        isvestis<<std::setw(17)<<std::left<<"Galutinis (Vid.)";
    }
    if(rodyti_pasirinkimas==2 || rodyti_pasirinkimas==3) {
        isvestis<<std::setw(17)<<std::left<<"Galutinis (Med.)";
    }
    isvestis<<"\n"
              "------------------------------------------------------------\n";

    isvestis << std::left<<std::fixed << std::setprecision(2);

    if (rodyti_pasirinkimas == 1) {
        for (auto& i : studentai) {
            isvestis << std::setw(isvesties_pavardes_ilgis) << i.pavarde
                   << std::setw(isvesties_vardo_ilgis) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "\n";
        }
    } else if (rodyti_pasirinkimas == 2) {
        for (auto& i : studentai) {
            isvestis << std::setw(isvesties_pavardes_ilgis) << i.pavarde
                   << std::setw(isvesties_vardo_ilgis) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    } else if (rodyti_pasirinkimas == 3) {
        for (auto& i : studentai) {
            isvestis << std::setw(isvesties_pavardes_ilgis) << i.pavarde
                   << std::setw(isvesties_vardo_ilgis) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "   "
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    }
    try {
        isvesties_metodas << isvestis.str();
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida isvedant duomenis: "<<e.what()<<"\n";
    }
}
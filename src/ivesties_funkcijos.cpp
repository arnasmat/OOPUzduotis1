//
// Created by User on 2025-02-19.
//

#include "../include/ivesties_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/failu_pasirinkimo_funkcijos.h"

int meniu(const fs::path &ivesties_failo_pavadinimas) {
    std::cout<<"------------------------------------------------------------\n"
            <<"Pasirinkite programos eiga: \n"
            <<"1. Studentus ir pazymius ivesti ranka\n"
            <<"2. Generuoti pazymius, bet studentus ivesti ranka\n"
            <<"3. Generuoti pazymius ir studentus\n"
            <<"4. Ivesti pazymius is failo, siuo metu pasirinktas failas: "<<ivesties_failo_pavadinimas.filename()<<"\n"
            <<"5. Pasirinkti ivesties faila\n"
            <<"6. Nuskaitymo greicio testavimas\n"
            <<"7. Generuoti faila\n"
            <<"8. Pilnas testavimas\n"
            <<"9. Baigti programos darba\n"
            <<"------------------------------------------------------------\n";
    int meniu{ivesties_patikrinimas(1,9)};
    return meniu;
}

void studentu_ivestis(std::vector<Studentas>& studentai) {
    while(true) {
        Studentas laikinas_studentas{};

        vardu_ivestis(studentai, laikinas_studentas);

        if(laikinas_studentas.vardas == "n" && !studentai.empty()) {
            return;
        }

        std::cout<<"Iveskite pazymius (jeigu norite baigti pazymiu ivedima, iveskite -1): ";
        int pazymys{0};
        while(true) {
            pazymys = ivesties_patikrinimas(1,10, -1);
            while(pazymys == -1 && laikinas_studentas.pazymiai.empty()) {
                std::cout << "Iveskite bent viena pazymi: ";
                pazymys = ivesties_patikrinimas(1, 10);
            }
            if(pazymys == -1)
                break;
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
        std::cout<<"Iveskite egzamino rezultata: ";
        laikinas_studentas.egzamino_rezultatas = 0;
        laikinas_studentas.egzamino_rezultatas = ivesties_patikrinimas(1, 10);
        studentai.push_back(laikinas_studentas);
    }
}

void studentu_ivestis_random_2(std::vector<Studentas>& studentai) {
    while(true) {
        Studentas laikinas_studentas{};

        vardu_ivestis(studentai, laikinas_studentas);

        if(laikinas_studentas.vardas == "n" && !studentai.empty()) {
            return;
        }

        random_pazymiu_generavimas(laikinas_studentas);

        studentai.push_back(laikinas_studentas);
    }
}

void studentu_ivestis_random_3(std::vector<Studentas>& studentai) {
    try {
        //Random vardu generavimas
        std::vector<std::string> vyriski_vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Tomas", "Darius", "Marius", "Rokas", "Mantas", "Mantas"};
        std::vector<std::string> moteriski_vardai = {"Ona", "Petra", "Antanina", "Kazyte", "Toma", "Darija", "Marija", "Rokas", "Mante", "Mante"};

        std::vector<std::string> vyriskos_pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazaitis", "Tomaitis", "Dariukaitis", "Mariukaitis", "Rokaitis", "Mantaitis"};
        std::vector<std::string> moteriskos_pavardes = {"Jonaitiene", "Petraitiene", "Antanaitiene", "Kazaitiene", "Tomaitiene", "Dariukaite", "Mariukaite", "Rokaite", "Mantaite"};

        std::uniform_int_distribution<int> random(1, 10);
        //Inicializuoju random reiskme kiekvienam, jeigu keisis ju dydziai ateityje.
        //Pasiklausti, ar teisingai esu padares, nes kazkaip labai daznai generuoja identiska varda kelis kartus is eiles.
        std::uniform_int_distribution<int> random_vyriskas_vardas(0, static_cast<int>(vyriski_vardai.size())-1);
        std::uniform_int_distribution<int> random_moteriskas_vardas(0, static_cast<int>(moteriski_vardai.size())-1);
        std::uniform_int_distribution<int> random_vyriska_pavarde(0, static_cast<int>(vyriskos_pavardes.size())-1);
        std::uniform_int_distribution<int> random_moteriska_pavarde(0, static_cast<int>(moteriskos_pavardes.size())-1);

        int zmoniu_kiekis = random(mt);
        for(int i=0; i<zmoniu_kiekis; i++) {
            Studentas laikinas_studentas{};
            if(random(mt)%2 == 1) {
                laikinas_studentas.vardas = vyriski_vardai[random_vyriskas_vardas(mt)];
                laikinas_studentas.pavarde = vyriskos_pavardes[random_vyriska_pavarde(mt)];
            } else {
                laikinas_studentas.vardas = moteriski_vardai[random_moteriskas_vardas(mt)];
                laikinas_studentas.pavarde = moteriskos_pavardes[random_moteriska_pavarde(mt)];
            }

            random_pazymiu_generavimas(laikinas_studentas);

            studentai.push_back(laikinas_studentas);
        }
    } catch(std::exception& e){
        std::cerr<<"Ivyko klaida generuojant studentus: "<<e.what()<<"\n";
    }
}

void studentu_ivestis_is_failo(std::vector<Studentas>& studentai, const fs::path& ivesties_failo_pavadinimas, bool& praejo) {
    std::ifstream ivesties_failas(ivesties_failo_pavadinimas);
    std::stringstream buffer{};
    try {
        if(!ivesties_failas || !ivesties_failas.is_open()) {
            praejo = false;
            throw std::runtime_error("Failas nerastas.");
        }
    buffer << ivesties_failas.rdbuf();
    ivesties_failas.close();
    } catch(const std::exception& e){
        std::cerr<<"Klaida su failu: "<<e.what()<<"\n";
        return;
    }

    std::vector<std::string> split_linijos{};
    std::string linija{};

    //Skips the first line of ivesties_failas as it stores the information about each column.
    std::getline(buffer, linija);

    while (std::getline(buffer, linija)) {
        Studentas laikinas_studentas{};
        //pakeiciau i istringstreama, nes pratestavus atrodo greiciau xd, jeigu sukels bedu - pakeist atgal
        std::istringstream ivestis(linija);
        std::string vardas{}, pavarde{};
        ivestis>>vardas;
        laikinas_studentas.vardas = vardas;
        ivestis>>pavarde;
        laikinas_studentas.pavarde = pavarde;
        int pazymys{0};
        while(ivestis>>pazymys) {
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
        laikinas_studentas.egzamino_rezultatas = laikinas_studentas.pazymiai.back();
        laikinas_studentas.pazymiai.pop_back();
        studentai.push_back(laikinas_studentas);
    }
}

double ivesties_testavimas(bool& praejo) {
    fs::path testavimo_failas{pasirinkti_faila_is_testiniu()};
    std::cout<<"Iveskite kiek testu norite daryti (nuo 1 iki 100): \n";
    int testu_kiekis{ivesties_patikrinimas(1,100)};

    std::chrono::duration<double> nuskaitymo_laiku_suma{0};
try {
    std::vector<Studentas> test_studentai;
    for(int i=0; i<testu_kiekis; i++) {
        auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        studentu_ivestis_is_failo(test_studentai, testavimo_failas, praejo);
        std::chrono::duration<double> sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        nuskaitymo_laiku_suma+=sugaistas_laikas;
        std::cout<<"Failo nuskaitymas uztruko: "<<sugaistas_laikas.count()<<"\n";
        test_studentai.clear();
    }
    return nuskaitymo_laiku_suma.count()/testu_kiekis;
} catch(std::exception& e) {
    std::cerr<<"Ivyko klaida testuojant nuskaityma: "<<e.what()<<"\n";
    return 0;
}
}
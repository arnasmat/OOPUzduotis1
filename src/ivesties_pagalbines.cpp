//
// Created by User on 2025-02-19.
//

#include <ivesties_pagalbines.h>

//Globalus rd ir mt, kad ju seedinimas butu tik viena karta inicializuojant programa,
//extern apibreztas pagalbines.h, bet normalus apibrezimas cia.
std::random_device rd;
std::mt19937 mt(rd());

//Ivesties patikrinimo funkcija, kuri patikrina ar ivestas skaicius yra tarp nurodytu reziu (nuo - iki).
int ivesties_patikrinimas(const int nuo, const int iki) {
        int input{0};
    try {
        while(input<nuo || input>iki) {
            std::cin>>input;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<"\n";
                continue;
            }
            if(input<nuo || input>iki)
                std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<"\n";
        }
        return input;
    } catch(std::exception& e){
        std::cerr<<"Ivyko ivedimo klaida: "<<e.what()<<"\n";
        return -1;
    }
}

//Ivesties patikrinimo funkcijos pletinys turintis sustabdymo salyga (sustabdymo_salyga).
int ivesties_patikrinimas(const int nuo, const int iki, const int sustabdymo_salyga) {
    int input{0};
    try {
        while(input<nuo || input>iki) {
            std::cin>>input;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<"\n";
                continue;
            }
            if(input==sustabdymo_salyga) {
                return input;
            }
            if(input<nuo || input>iki)
                std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<"\n";
        }
        return input;
    } catch(std::exception& e) {
        std::cerr<<"Ivyko ivedimo klaida: "<<e.what()<<"\n";
        return -1;
    }
}

void random_pazymiu_generavimas(Studentas& laikinas_studentas) {
    try {
        std::uniform_int_distribution<int> random(1, 10);
        int random_pazymiu_kiekis = random(mt);
        for(int i=0; i<random_pazymiu_kiekis; i++) {
            laikinas_studentas.pazymiai.push_back(random(mt));

        }
        laikinas_studentas.egzamino_rezultatas = random(mt);
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida generuojant pazymius: "<<e.what()<<"\n";
    }
}
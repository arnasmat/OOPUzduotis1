//
// Created by User on 2025-02-10.
//

#ifndef PAGALBINES_MIX_H
#define PAGALBINES_MIX_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

struct Studentas {
    std::string vardas{}, pavarde{};
    unsigned int pazymiu_kiekis{0};
    unsigned int *pazymiai{nullptr};
    unsigned int egzamino_rezultatas{};
};

void prideti_nauja_pazymi(Studentas& studentas, unsigned int naujas_pazymys) {
    unsigned int* nauji_pazymiai = new unsigned int[studentas.pazymiu_kiekis];
    for (unsigned int i = 0; i < studentas.pazymiu_kiekis - 1; ++i) {
        nauji_pazymiai[i] = studentas.pazymiai[i];
    }
    nauji_pazymiai[studentas.pazymiu_kiekis - 1] = naujas_pazymys;
    delete[] studentas.pazymiai;
    studentas.pazymiai = nauji_pazymiai;
}

void studentu_ivestis(std::vector<Studentas>& studentai) {
    while(true) {
        std::cout<<"Iveskite studentus arba noredami baigti iveskite 'n': "<<std::endl;
        Studentas laikinas_studentas{};
        std::cout<<"Iveskit studento varda ir pavarde: ";
        std::cin>>laikinas_studentas.vardas;

        if(laikinas_studentas.vardas == "n") {
            break;
        }

        std::cin>>laikinas_studentas.pavarde;
        std::cout<<"Iveskite pazymius, iveskite -1, jeigu norite baigti pazymiu ivedima: ";
        int pazymys{0};
        while(true) {
            std::cin >> pazymys;
            if(pazymys == -1) {
                break;
            }
            if(pazymys >= 1 && pazymys <= 10) {
                laikinas_studentas.pazymiu_kiekis++;
                prideti_nauja_pazymi(laikinas_studentas , pazymys);
            } else {
                std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi is naujo: ";
            }
        }
        std::cout<<"Iveskite egzamino rezultata: ";
        laikinas_studentas.egzamino_rezultatas = 0;
        while(laikinas_studentas.egzamino_rezultatas < 1 || laikinas_studentas.egzamino_rezultatas > 10) {
            std::cin>>laikinas_studentas.egzamino_rezultatas;
            if(laikinas_studentas.egzamino_rezultatas < 1 || laikinas_studentas.egzamino_rezultatas > 10) {
                std::cout<<"Ivestas netinkamas egzamino rezultatas. Iveskite egzamino rezultata is naujo: ";
            }
        }
        studentai.push_back(laikinas_studentas);
    }
}

unsigned int galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    for(int i=0; i<studentas.pazymiu_kiekis; i++) {
        pazymiu_suma+=studentas.pazymiai[i];
    }
    return static_cast<int>(round(pazymiu_suma / studentas.pazymiu_kiekis * 0.4 + studentas.egzamino_rezultatas * 0.6));
}

unsigned int galutinis_pazymys_mediana(Studentas &studentas) {
    unsigned int mediana{0};
    std::sort(studentas.pazymiai, studentas.pazymiai+studentas.pazymiu_kiekis);
    if(studentas.pazymiu_kiekis%2==0) {
        mediana = round((studentas.pazymiai[studentas.pazymiu_kiekis/2] + studentas.pazymiai[studentas.pazymiu_kiekis/2-1])/2.0);
    } else {
        mediana = studentas.pazymiai[studentas.pazymiu_kiekis/2];
    }
    return static_cast<int>(mediana*0.4 + studentas.egzamino_rezultatas*0.6);
}


#endif //PAGALBINES_MIX_H

//
// Created by User on 2025-02-07.
//

#ifndef PAGALBINES_VEC_H
#define PAGALBINES_VEC_H

#include <iostream>
#include <iomanip>
#include <vector>


struct Studentas {
    std::string vardas{}, pavarde{};
    std::vector<unsigned int> pazymiai{};
    unsigned int egzamino_rezultatas{};
};

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
                laikinas_studentas.pazymiai.push_back(pazymys);
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
    for(const auto i: studentas.pazymiai) {
        pazymiu_suma+=i;
    }
    return static_cast<int>(round(pazymiu_suma / studentas.pazymiai.size() * 0.4 + studentas.egzamino_rezultatas * 0.6));
}

unsigned int galutinis_pazymys_mediana(Studentas &studentas) {
    unsigned int mediana{0};
    std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
    if(studentas.pazymiai.size()%2==0) {
        mediana = round((studentas.pazymiai[studentas.pazymiai.size()/2.0] + studentas.pazymiai[studentas.pazymiai.size()/2.0-1])/2.0);
    } else {
        mediana = studentas.pazymiai[(studentas.pazymiai.size()/2.0)];
    }
    return static_cast<int>(mediana*0.4 + studentas.egzamino_rezultatas*0.6);
}



#endif //PAGALBINES_VEC_H

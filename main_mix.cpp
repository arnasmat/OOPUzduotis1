//
// Created by User on 2025-02-10.
//

#include "pagalbines_mix.h"

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

float galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    for(int i=0; i<studentas.pazymiu_kiekis; i++) {
        pazymiu_suma+=studentas.pazymiai[i];
    }
    return pazymiu_suma / studentas.pazymiu_kiekis * 0.4 + studentas.egzamino_rezultatas * 0.6;
}

float galutinis_pazymys_mediana(Studentas &studentas) {
    unsigned int mediana{0};
    std::sort(studentas.pazymiai, studentas.pazymiai+studentas.pazymiu_kiekis);
    if(studentas.pazymiu_kiekis%2==0) {
        mediana = (studentas.pazymiai[studentas.pazymiu_kiekis/2] + studentas.pazymiai[studentas.pazymiu_kiekis/2-1])/2.0;
    } else {
        mediana = studentas.pazymiai[studentas.pazymiu_kiekis/2];
    }
    return mediana*0.4 + studentas.egzamino_rezultatas*0.6;
}

void isvestis(std::vector<Studentas>& studentai) {
    char pasirinkimas{};
    std::cout<<"Pasirinkite ka norite matyti: v - vidurkis, m - mediana, a - abu: ";
    while(pasirinkimas != 'v' && pasirinkimas != 'm' && pasirinkimas != 'a') {
        std::cin>>pasirinkimas;
        if(pasirinkimas != 'v' && pasirinkimas !=  'm' && pasirinkimas != 'a') {
            std::cout<<"Neteisingas pasirinkimas. Prasome ivesti v, m arba a.";
        }
    }

    int longest_name{0};
    int longest_surname{0};
    for(auto i: studentai) {
        if(i.vardas.length() > longest_name) {
            longest_name = i.vardas.length();
        }
        if(i.pavarde.length() > longest_surname) {
            longest_surname = i.pavarde.length();
        }
    }

    std::cout<<std::left<<std::setw(longest_surname > 7 ? longest_surname+2 : 8)<<"Pavarde";
    std::cout<<std::left<<std::setw(longest_name > 6 ? longest_surname+2 : 8)<<"Vardas";
    if(pasirinkimas=='v' || pasirinkimas=='a') {
        std::cout<<std::setw(17)<<std::left<<"Galutinis (Vid.)";
    }
    if(pasirinkimas=='a') std::cout<<"   ";
    if(pasirinkimas=='m' || pasirinkimas=='a') {
        std::cout<<std::setw(17)<<std::left<<"Galutinis (Med.)";
    }
    std::cout<<std::endl;
    std::cout<<"------------------------------------------------------------"<<std::endl;
    for(auto i: studentai) {
        std::cout<<std::left<<std::setw(longest_surname > 7 ? longest_surname+2 : 8)
            <<i.pavarde<<std::left<<std::setw(longest_name > 6 ? longest_surname+2 : 8)<<i.vardas;
        if(pasirinkimas=='v' || pasirinkimas=='a') {
            std::cout<<std::setw(17)<<std::left<<std::fixed<<std::setprecision(2)<<galutinis_pazymys_vidurkis(i);
        }
        if(pasirinkimas=='a') std::cout<<"   ";
        if(pasirinkimas=='m' || pasirinkimas=='a') {
            std::cout<<std::setw(17)<<std::left<<std::fixed<<std::setprecision(2)<<galutinis_pazymys_mediana(i);
        }
        std::cout<<std::endl;
    }
}

int main() {
    std::vector<Studentas> studentai;
    studentu_ivestis(studentai);
    isvestis(studentai);
}
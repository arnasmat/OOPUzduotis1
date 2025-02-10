//
// Created by User on 2025-02-10.
//

#ifndef PAGALBINES_H
#define PAGALBINES_H

#include <iostream>
#include <iomanip>
#include <vector>

void isvestis(std::vector<Studentas>& studentai) {
    char pasirinkimas{};
    std::cout<<"Pasirinkite ka norite matyti: v - vidurkis, m - mediana, a - abu: ";
    while(pasirinkimas != 'v' && pasirinkimas != 'm' && pasirinkimas != 'a') {
        std::cin>>pasirinkimas;
        if(pasirinkimas != 'v' && pasirinkimas !=  'm' && pasirinkimas != 'a') {
            std::cout<<"Neteisingas pasirinkimas. Prasome ivesti v, m arba a.";
        }
    }

    std::cout<<std::left<<std::setw(15)<<"Pavarde"<<" ";
    std::cout<<std::left<<std::setw(15)<<"Vardas";
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
        std::cout<<std::left<<std::setw(15)<<i.pavarde<<" "<<std::left<<std::setw(15)<<i.vardas<<" ";
        if(pasirinkimas=='v' || pasirinkimas=='a') {
            std::cout<<std::setw(17)<<std::left<<galutinis_pazymys_vidurkis(i);
        }
        if(pasirinkimas=='a') std::cout<<"   ";
        if(pasirinkimas=='m' || pasirinkimas=='a') {
            std::cout<<std::setw(17)<<std::left<<galutinis_pazymys_mediana(i);
        }
        std::cout<<std::endl;
    }
}


#endif //PAGALBINES_H

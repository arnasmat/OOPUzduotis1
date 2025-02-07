#include "pagalbines.h"

void studentu_ivestis(int studentu_kiekis, std::vector<Studentas>& studentai) {
    for(int i=0; i<studentu_kiekis; i++) {
        Studentas laikinas_studentas{};
        std::cout<<"Iveskit studento varda ir pavarde: ";
        std::cin>>laikinas_studentas.vardas>>laikinas_studentas.pavarde;
        std::cout<<"Iveskite kiek pazymiu gavo studentas: ";
        int pazymiu_kiekis{};
        std::cin>>pazymiu_kiekis;
        std::cout<<"Iveskite pazymius: ";
        for(int j=0; j<pazymiu_kiekis; j++) {
            int pazymys{};
            std::cin>>pazymys;
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
        std::cout<<"Iveskite egzamino rezultata: ";
        std::cin>>laikinas_studentas.egzamino_rezultatas;
        studentai.push_back(laikinas_studentas);
    }
}

void studentu_atspausdinimas(std::vector<Studentas>& studentai) {
    for(auto i: studentai.size()) {
        std::cout<<studentai[i].vardas<<" "<<studentai[i].pavarde<<std::endl;
        for(int j=0; j<studentai[i].pazymiai.size(); j++) {
            std::cout<<studentai[i].pazymiai[j]<<" ";
        }
        std::cout<<std::endl;
        std::cout<<studentai[i].egzamino_rezultatas<<std::endl;
    }
}

unsigned int galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    for(auto i: studentas.pazymiai.size()) {
        pazymiu_suma+=studentas.pazymiai[i];
    }
    return static_cast<int>(pazymiu_suma / studentas.pazymiai.size() * 0.4 + studentas.egzamino_rezultatas * 0.6);
}

unsigned int galutinis_pazymys_mediana(Studentas &studentas) {
    unsigned int mediana{0};
    if(studentas.pazymiai.size()%2==0) {
        mediana = studentas.pazymiai[studentas.pazymiai.size()/2] + studentas.pazymiai[studentas.pazymiai.size()/2-1];
    } else {
        mediana = studentas.pazymiai[round((studentas.pazymiai.size())/2.0)];
    }
    return static_cast<int>(mediana*0.4 + studentas.egzamino_rezultatas*0.6);
}


int main() {
    constexpr int studentu_kiekis{2};
    std::vector<Studentas> studentai(studentu_kiekis);
    studentu_ivestis(studentu_kiekis, studentai);
    studentu_atspausdinimas(studentai);
}
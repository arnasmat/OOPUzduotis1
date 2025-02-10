//
// Created by User on 2025-02-10.
//

#include "pagalbines_vec.h"

int meniu() {
    int meniu{0};
    std::cout<<"------------------------------------------------------------"<<std::endl;
    std::cout<<"Pasirinkite programos eiga: "<<std::endl;
    std::cout<<"1. Studentus ir pazymius ivesti ranka"<<std::endl;
    std::cout<<"2. Generuoti pazymius, bet studentus ivesti ranka"<<std::endl;
    std::cout<<"3. Generuoti pazymius ir studentus"<<std::endl;
    std::cout<<"4. Baigti programos darba"<<std::endl;
    std::cout<<"------------------------------------------------------------"<<std::endl;
    while(meniu<1 || meniu>4) {
        std::cin>>meniu;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo 1 iki 4"<<std::endl;
            continue;
        }
        if(meniu<1 || meniu>4)
            std::cout<<"Iveskite skaiciu nuo 1 iki 4"<<std::endl;
    }
    return meniu;
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
            if(!std::cin.fail()) {
                if(pazymys == -1) {
                    break;
                }
                if(pazymys >= 1 && pazymys <= 10) {
                    laikinas_studentas.pazymiai.push_back(pazymys);
                } else {
                    std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi is naujo: ";
                }
            } else {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi is naujo: ";
            }

        }
        std::cout<<"Iveskite egzamino rezultata: ";
        laikinas_studentas.egzamino_rezultatas = 0;
        while(laikinas_studentas.egzamino_rezultatas < 1 || laikinas_studentas.egzamino_rezultatas > 10) {
            laikinas_studentas.egzamino_rezultatas = 0;
            std::cin>>laikinas_studentas.egzamino_rezultatas;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Ivestas netinkamas pazymys. Iveskite pazymi is naujo: ";
                continue;
            }
            if(laikinas_studentas.egzamino_rezultatas < 1 || laikinas_studentas.egzamino_rezultatas > 10) {
                std::cout<<"Ivestas netinkamas egzamino rezultatas. Iveskite egzamino rezultata is naujo: ";
            }
        }
        studentai.push_back(laikinas_studentas);
    }
}

void studentu_ivestis_random_2(std::vector<Studentas>& studentai) {
    while(true) {
        std::cout<<"Iveskite studentus arba noredami baigti iveskite 'n': "<<std::endl;
        Studentas laikinas_studentas{};
        std::cout<<"Iveskit studento varda ir pavarde: ";
        std::cin>>laikinas_studentas.vardas;

        if(laikinas_studentas.vardas == "n") {
            break;
        }
        std::cin>>laikinas_studentas.pavarde;

        srand(time(nullptr));
        int random_pazymiu_kiekis{rand() % 10 + 1};
        for(int i=0; i<random_pazymiu_kiekis; i++) {
            laikinas_studentas.pazymiai.push_back(rand()%10 + 1);

        }
        laikinas_studentas.egzamino_rezultatas = rand() % 10 + 1;
        studentai.push_back(laikinas_studentas);
    }
}

void studentu_ivestis_random_3(std::vector<Studentas>& studentai) {

    std::vector<std::string> vyriski_vardai = {"Jonas", "Petras", "Antanas", "Kazys", "Tomas", "Darius", "Marius", "Rokas", "Mantas", "Mantas"};
    std::vector<std::string> moteriski_vardai = {"Ona", "Petra", "Antanina", "Kazyte", "Toma", "Darija", "Marija", "Rokas", "Mante", "Mante"};

    std::vector<std::string> vyriskos_pavardes = {"Jonaitis", "Petraitis", "Antanaitis", "Kazaitis", "Tomaitis", "Dariukaitis", "Mariukaitis", "Rokaitis", "Mantaitis"};
    std::vector<std::string> moteriskos_pavardes = {"Jonaitiene", "Petraitiene", "Antanaitiene", "Kazaitiene", "Tomaitiene", "Dariukaite", "Mariukaite", "Rokaite", "Mantaite"};
    srand(time(nullptr));
    int zmoniu_kiekis = rand()%10 + 1;
    for(int i=0; i<zmoniu_kiekis; i++) {
        Studentas laikinas_studentas{};
        if(rand()%2 == 1) {
            laikinas_studentas.vardas = vyriski_vardai[rand()%vyriski_vardai.size()];
            laikinas_studentas.pavarde = vyriskos_pavardes[rand()%vyriskos_pavardes.size()];
        } else {
            laikinas_studentas.vardas = moteriski_vardai[rand()%vyriski_vardai.size()];
            laikinas_studentas.pavarde = moteriskos_pavardes[rand()%vyriskos_pavardes.size()];
        }


        int random_pazymiu_kiekis{rand() % 10 + 1};
        for(int i=0; i<random_pazymiu_kiekis; i++) {
            laikinas_studentas.pazymiai.push_back(rand()%10 + 1);
        }
        laikinas_studentas.egzamino_rezultatas = rand() % 10 + 1;
        studentai.push_back(laikinas_studentas);
    }
}

float galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    if(studentas.pazymiai.size()==0) return 0;;
    for(const auto i: studentas.pazymiai) {
        pazymiu_suma+=i;
    }
    return pazymiu_suma / studentas.pazymiai.size() * 0.4 + studentas.egzamino_rezultatas * 0.6;
}

float galutinis_pazymys_mediana(Studentas &studentas) {
    unsigned int mediana{0};
    if(studentas.pazymiai.size()==0) return 0;;
    std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
    if(studentas.pazymiai.size()%2==0) {
        mediana = (studentas.pazymiai[studentas.pazymiai.size()/2.0] + studentas.pazymiai[studentas.pazymiai.size()/2.0-1])/2.0;
    } else {
        mediana = studentas.pazymiai[(studentas.pazymiai.size()/2.0)];
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
    while(true){
        int menu = meniu();
        switch(menu) {
            case 1:
                studentu_ivestis(studentai);
            break;
            case 2:
                studentu_ivestis_random_2(studentai);
            break;
            case 3:
                studentu_ivestis_random_3(studentai);
            break;
            case 4:
                return 0;

        }
        isvestis(studentai);
    }
}


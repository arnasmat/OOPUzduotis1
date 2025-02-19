//
// Created by User on 2025-02-10.
//

#include "pagalbines.h"

//Ivesties patikrinimo funkcija, kuri patikrina ar ivestas skaicius yra tarp nurodytu reziu (nuo - iki).
int ivesties_patikrinimas(const int nuo, const int iki) {
    int input{0};
    while(input<nuo || input>iki) {
        std::cin>>input;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo"<<nuo<<" iki "<<iki<<std::endl;
            continue;
        }
        if(input<nuo || input>iki)
            std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<std::endl;
    }
    return input;
}

//Ivesties patikrinimo funkcijos pletinys turintis sustabdymo salyga (sustabdymo_salyga).
int ivesties_patikrinimas(const int nuo, const int iki, const int sustabdymo_salyga) {
    int input{0};
    while(input<nuo || input>iki) {
        std::cin>>input;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo"<<nuo<<" iki "<<iki<<std::endl;
            continue;
        }
        if(input==sustabdymo_salyga) {
            return input;
        }
        if(input<nuo || input>iki)
            std::cout<<"Iveskite skaiciu nuo "<<nuo<<" iki "<<iki<<std::endl;
    }
    return input;
}

int meniu(const std::string &ivesties_failo_pavadinimas) {
    std::cout<<"------------------------------------------------------------"<<std::endl;
    std::cout<<"Pasirinkite programos eiga: "<<std::endl;
    std::cout<<"1. Studentus ir pazymius ivesti ranka"<<std::endl;
    std::cout<<"2. Generuoti pazymius, bet studentus ivesti ranka"<<std::endl;
    std::cout<<"3. Generuoti pazymius ir studentus"<<std::endl;
    std::cout<<"4. Ivesti pazymius is failo, siuo metu pasirinktas failas: "<<ivesties_failo_pavadinimas<<std::endl;
    std::cout<<"5. Nuskaitymo greicio testavimas"<<std::endl;
    std::cout<<"6. Baigti programos darba"<<std::endl;
    std::cout<<"------------------------------------------------------------"<<std::endl;
    int meniu{ivesties_patikrinimas(1,6)};
    return meniu;
}

void isvesties_meniu(std::vector<Studentas>& studentai, const std::string &isvesties_failo_pavadinimas) {
    std::cout<<"Kaip norite isvesti gautus rezultatus: "<<std::endl;
    std::cout<<"1. I terminala"<<std::endl;
    std::cout<<"2. I faila"<<std::endl;
    int isvesties_pasirinkimas{ivesties_patikrinimas(1, 2)};
    if(isvesties_pasirinkimas==1) {
        isvestis(studentai, std::cout);
    } else {
        std::ofstream file(isvesties_failo_pavadinimas);
        if (file.is_open()) {
            isvestis(studentai, file);
            file.close();
        } else {
            std::cerr << "Nepavyko atidaryti isvesties failo";
        }
    }
}

void studentu_ivestis(std::vector<Studentas>& studentai) {
    while(true) {
        std::cout<<studentai.size();
        std::cout<<"Iveskite studentus arba noredami baigti iveskite 'n': "<<std::endl;
        Studentas laikinas_studentas{};
        std::cout<<"Iveskit studento varda ir pavarde: ";
        std::cin>>laikinas_studentas.vardas;

        while (laikinas_studentas.vardas == "n" && studentai.size() == 0) {
            std::cout<<"Iveskite bent viena studenta: "<<std::endl;
            std::cin>>laikinas_studentas.vardas;
        }

        if(laikinas_studentas.vardas == "n" && studentai.size() > 0) {
            break;
        }

        std::cin>>laikinas_studentas.pavarde;
        std::cout<<"Iveskite pazymius, iveskite -1, jeigu norite baigti pazymiu ivedima: ";
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

void studentu_ivestis_is_failo(std::vector<Studentas>& studentai, std::string failo_pavadinimas, bool& praejo) {
    std::ifstream ivesties_failas(failo_pavadinimas);
    if(!ivesties_failas) {
        std::cerr<<"Failas nerastas."<<std::endl;
        praejo = false;
        return;
    }
    std::stringstream buffer{};
    buffer << ivesties_failas.rdbuf();
    ivesties_failas.close();

    std::vector<std::string> split_linijos{};
    std::string linija{};

    //Skips the first line of ivesties_failas as it stores the information about each column.
    std::getline(buffer, linija);

    while (std::getline(buffer, linija)) {
        Studentas laikinas_studentas{};
        std::stringstream ivestis(linija);
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
    std::chrono::duration<double> nuskaitymo_laiku_suma{0};
    std::vector<Studentas> test_studentai;

    std::string testavimo_failo_pavadinimas{};
    std::cout<<"Pasirinkite koki testavimo faila norite nuskaityti: "<<std::endl;
    std::cout<<"1. 10000 studentu"<<std::endl;
    std::cout<<"2. 100000 studentu"<<std::endl;
    std::cout<<"3. 1000000 studentu"<<std::endl;
    int failo_pasirinkimas{ivesties_patikrinimas(1, 3)};
    std::cout<<"Iveskite kiek testu norite daryti (nuo 1 iki 100). Rekomenduojama: 10: ";
    int testu_kiekis{ivesties_patikrinimas(1,100)};

    switch(failo_pasirinkimas) {
        case 1: testavimo_failo_pavadinimas = "studentai10000.txt"; break;
        case 2: testavimo_failo_pavadinimas = "studentai100000.txt"; break;
        case 3: testavimo_failo_pavadinimas = "studentai1000000.txt"; break;
    }

    for(int i=0; i<testu_kiekis; i++) {
        auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        studentu_ivestis_is_failo(test_studentai, testavimo_failo_pavadinimas, praejo);
        std::chrono::duration<double> sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        nuskaitymo_laiku_suma+=sugaistas_laikas;
        std::cout<<"Failo nuskaitymas uztruko: "<<sugaistas_laikas.count()<<std::endl;
        test_studentai.clear();
    }
    return nuskaitymo_laiku_suma.count()/testu_kiekis;
}


float galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    if(studentas.pazymiai.size()==0) return 0;;
    for(const auto &i: studentas.pazymiai) {
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

void isvestis(std::vector<Studentas>& studentai, std::ostream& isvesties_metodas) {

    std::cout<<"Pasirinkite ka norite matyti isvedant studentus: "<<std::endl;
    std::cout<<"1. Vidurki"<<std::endl;
    std::cout<<"2. Mediana"<<std::endl;
    std::cout<<"3. Abu (ir vidurki, ir mediana)"<<std::endl;
    int rodyti_pasirinkimas{ivesties_patikrinimas(1,3)};

    std::cout<<"------------------------------------------------------------"<<std::endl;

    for(auto &i: studentai) {
            i.galutinis_vidurkis = galutinis_pazymys_vidurkis(i);
            i.galutinis_mediana = galutinis_pazymys_mediana(i);
    }


    std::cout<<"Pasirinkite kaip norite rusiuoti: "<<std::endl;
    std::cout<<"1. Rusiuoti pagal varda"<<std::endl;
    std::cout<<"2. Rusiuoti pagal pavarde"<<std::endl;
    std::cout<<"3. Rusiuoti pagal galutini pazymi pagal vidurki mazejanciai"<<std::endl;
    std::cout<<"4. Rusiuoti pagal galutini pazymi pagal vidurki didejanciai"<<std::endl;
    std::cout<<"5. Rusiuoti pagal galutini pazymi pagal mediana mazejanciai"<<std::endl;
    std::cout<<"6. Rusiuoti pagal galutini pazymi pagal mediana didejanciai"<<std::endl;
    int rusiavimo_pasirinkimas{ivesties_patikrinimas(1,6)};


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
    }

    int longest_name{0};
    int longest_surname{0};
    for(auto &i: studentai) {
        if(i.vardas.length() > longest_name) {
            longest_name = i.vardas.length();
        }
        if(i.pavarde.length() > longest_surname) {
            longest_surname = i.pavarde.length();
        }
    }

    //konvertuoti i viena eilute
    std::stringstream isvestis{};

    isvestis<<std::left<<std::setw(longest_surname > 7 ? longest_surname+2 : 8)<<"Pavarde"
    <<std::left<<std::setw(longest_name > 6 ? longest_name+2 : 8)<<"Vardas";
    if(rodyti_pasirinkimas==1 || rodyti_pasirinkimas==3) {
        isvestis<<std::setw(17)<<std::left<<"Galutinis (Vid.)";
    }
    if(rodyti_pasirinkimas==2 || rodyti_pasirinkimas==3) {
        isvestis<<std::setw(17)<<std::left<<"Galutinis (Med.)";
        isvestis<<std::endl;
        isvestis<<"------------------------------------------------------------"<<std::endl;
    }

    isvestis << std::left<<std::fixed << std::setprecision(2);

    if (rodyti_pasirinkimas == 1) {
        for (auto& i : studentai) {
            isvestis << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "\n";
        }
    } else if (rodyti_pasirinkimas == 2) {
        for (auto& i : studentai) {
            isvestis << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    } else if (rodyti_pasirinkimas == 3) {
        for (auto& i : studentai) {
            isvestis << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "   "
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    }

    isvesties_metodas << isvestis.str();
}

int main() {
    const std::string ivesties_failo_pavadinimas{"studentai10000.txt"};
    const std::string isvesties_failo_pavadinimas{"rezultatai.txt"};

    std::vector<Studentas> studentai;
    while(true){
        int menu{meniu(ivesties_failo_pavadinimas)};
        bool praejo{true};
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
                studentu_ivestis_is_failo(studentai, ivesties_failo_pavadinimas, praejo);
            break;
            case 5: {
                std::cout<<"Nuskaitymo testavimo laikas: "<<ivesties_testavimas(praejo)<<std::endl;
                praejo=false;
                break;
            }
            case 6:
                return 0;
        }
        if(praejo)
            isvesties_meniu(studentai, isvesties_failo_pavadinimas);
    }
}


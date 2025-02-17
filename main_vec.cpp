//
// Created by User on 2025-02-10.
//

#include <chrono>

#include "pagalbines_vec.h"

int meniu(const std::string &ivesties_failo_pavadinimas) {
    int meniu{0};
    std::cout<<"------------------------------------------------------------"<<std::endl;
    std::cout<<"Pasirinkite programos eiga: "<<std::endl;
    std::cout<<"1. Studentus ir pazymius ivesti ranka"<<std::endl;
    std::cout<<"2. Generuoti pazymius, bet studentus ivesti ranka"<<std::endl;
    std::cout<<"3. Generuoti pazymius ir studentus"<<std::endl;
    std::cout<<"4. Ivesti pazymius is failo, siuo metu pasirinktas failas: "<<ivesties_failo_pavadinimas<<std::endl;
    std::cout<<"5. Nuskaitymo greicio testavimas"<<std::endl;
    std::cout<<"6. Baigti programos darba"<<std::endl;
    std::cout<<"------------------------------------------------------------"<<std::endl;
    while(meniu<1 || meniu>6) {
        std::cin>>meniu;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo 1 iki 6"<<std::endl;
            continue;
        }
        if(meniu<1 || meniu>6)
            std::cout<<"Iveskite skaiciu nuo 1 iki 6"<<std::endl;
    }
    return meniu;
}

void isvesties_meniu(std::vector<Studentas>& studentai, std::string(isvesties_failo_pavadinimas)) {
    std::cout<<"Kaip norite isvesti gautus rezultatus: "<<std::endl;
    std::cout<<"1. I terminala"<<std::endl;
    std::cout<<"2. I faila"<<std::endl;
    int isvesties_pasirinkimas{0};
    while(isvesties_pasirinkimas<1 || isvesties_pasirinkimas>2) {
        std::cin>>isvesties_pasirinkimas;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo 1 iki 2"<<std::endl;
            continue;
        }
        if(isvesties_pasirinkimas<1 || isvesties_pasirinkimas>2)
            std::cout<<"Iveskite skaiciu nuo 1 iki 2"<<std::endl;
    }
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
            std::cout<<"Iveskite bent viena studenta. "<<std::endl;
            std::cin>>laikinas_studentas.vardas;
        }

        if(laikinas_studentas.vardas == "n" && studentai.size() > 0) {
            break;
        }

        std::cin>>laikinas_studentas.pavarde;
        std::cout<<"Iveskite pazymius, iveskite -1, jeigu norite baigti pazymiu ivedima: ";
        int pazymys{0};
        while(true) {
            std::cin >> pazymys;
            while(pazymys == -1 && laikinas_studentas.pazymiai.empty()) {
                std::cout << "Iveskite bent viena pazymi ";
                std::cin >> pazymys;
            }
            if(!std::cin.fail()) {


                if(pazymys == -1 && !laikinas_studentas.pazymiai.empty()) {
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

void studentu_ivestis_is_failo(std::vector<Studentas>& studentai, std::string failo_pavadinimas, bool& praejo) {
    std::ifstream input(failo_pavadinimas);
    if(!input) {
        std::cerr<<"Failas nerastas.";
        praejo = true;
        return;
    }
    std::stringstream buffer{};
    buffer << input.rdbuf();
    input.close();

    std::vector<std::string> split_linijos{};
    std::string linija{};

    //kad praleisti pirma eilute, kurioje yra legenda
    std::getline(buffer, linija);

    while (std::getline(buffer, linija)) {
        split_linijos.push_back(linija);
    }

    //Suskaidytu liniju konvertavimas i studentus
    for(auto i: split_linijos) {
        Studentas laikinas_studentas{};
        std::stringstream input(i);
        std::string vardas{}, pavarde{};
        input>>vardas;
        laikinas_studentas.vardas = vardas;
        input>>pavarde;
        laikinas_studentas.pavarde = pavarde;
        int pazymys{0};
        while(input>>pazymys) {
            laikinas_studentas.pazymiai.push_back(pazymys);
        }
        laikinas_studentas.egzamino_rezultatas = laikinas_studentas.pazymiai.back();
        laikinas_studentas.pazymiai.pop_back();
        studentai.push_back(laikinas_studentas);
    }
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

void isvestis(std::vector<Studentas>& studentai, std::ostream& output_method) {
    int rodyti_pasirinkimas{0};
    std::cout<<"Pasirinkite ka norite matyti isvedant studentus: "<<std::endl;
    std::cout<<"1. Vidurki"<<std::endl;
    std::cout<<"2. Mediana"<<std::endl;
    std::cout<<"3. Abu (ir vidurki, ir mediana)"<<std::endl;

    while(rodyti_pasirinkimas<1 || rodyti_pasirinkimas>3) {
        std::cin>>rodyti_pasirinkimas;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo 1 iki 3"<<std::endl;
            continue;
        }
        if(rodyti_pasirinkimas<1 || rodyti_pasirinkimas>3)
            std::cout<<"Iveskite skaiciu nuo 1 iki 3"<<std::endl;
    }
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
    int rusiavimo_pasirinkimas{0};

    while(rusiavimo_pasirinkimas<1 || rusiavimo_pasirinkimas>6) {
        std::cin>>rusiavimo_pasirinkimas;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Iveskite skaiciu nuo 1 iki 6"<<std::endl;
            continue;
        }
        if(rusiavimo_pasirinkimas<1 || rusiavimo_pasirinkimas>6)
            std::cout<<"Iveskite skaiciu nuo 1 iki 6"<<std::endl;
    }

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
    std::stringstream output;

    output<<std::left<<std::setw(longest_surname > 7 ? longest_surname+2 : 8)<<"Pavarde"
    <<std::left<<std::setw(longest_name > 6 ? longest_name+2 : 8)<<"Vardas";
    if(rodyti_pasirinkimas==1 || rodyti_pasirinkimas==3) {
        output<<std::setw(17)<<std::left<<"Galutinis (Vid.)";
    }
    if(rodyti_pasirinkimas==2 || rodyti_pasirinkimas==3) {
        output<<std::setw(17)<<std::left<<"Galutinis (Med.)";
        output<<std::endl;
        output<<"------------------------------------------------------------"<<std::endl;
    }

    output << std::left<<std::fixed << std::setprecision(2);

    if (rodyti_pasirinkimas == 1) {
        for (auto& i : studentai) {
            output << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "\n";
        }
    } else if (rodyti_pasirinkimas == 2) {
        for (auto& i : studentai) {
            output << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    } else if (rodyti_pasirinkimas == 3) {
        for (auto& i : studentai) {
            output << std::setw(longest_surname > 7 ? longest_surname + 2 : 8) << i.pavarde
                   << std::setw(longest_name > 6 ? longest_name + 2 : 8) << i.vardas
                   << std::setw(17) << std::left << i.galutinis_vidurkis << "   "
                   << std::setw(17) << std::left << i.galutinis_mediana << "\n";
        }
    }

    output_method << output.str();
}

int main() {
    const std::string ivesties_failo_pavadinimas{"studentai10000.txt"};
    const std::string isvesties_failo_pavadinimas{"rezultatai.txt"};
    bool praejo{true};

    std::vector<Studentas> studentai;
    while(true){
        int menu{meniu(ivesties_failo_pavadinimas)};
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
            case 5:
                std::chrono::duration<double> nuskaitymo_laiku_suma;
                for(int i=0; i<10; i++) {
                    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
                    studentu_ivestis_is_failo(studentai, ivesties_failo_pavadinimas, praejo);
                    std::chrono::duration<double> sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
                    nuskaitymo_laiku_suma+=sugaistas_laikas;
                    std::cout<<sugaistas_laikas.count()<<std::endl;
                }
            std::cout<<"Nuskaitymo is failo vidutinis laikas: "<<nuskaitymo_laiku_suma.count()/10<<std::endl;
            //cia nededu break'o, nes noriu, kad po jo vis tiek returnintu 0
            case 6:
                return 0;
        }
        if(praejo)
            isvesties_meniu(studentai, isvesties_failo_pavadinimas);
    }
}


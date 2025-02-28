//
// Created by User on 2025-02-10.
//

#include "../include/pagalbines.h"
#include "../include/ivesties_funkcijos.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"
#include "../include/failu_pasirinkimo_funkcijos.h"
#include "../include/ivesties_pagalbines.h"
#include "../include/rusiavimo_funkcijos.h"

int main() {
    const std::string isvesties_failo_pavadinimas{"../data/output/rezultatai.txt"};
    fs::path ivesties_failas{"../data/input/kursiokai.txt"};

    std::vector<Studentas> studentai;
    while(true){

        int menu{meniu(ivesties_failas)};
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
                studentu_ivestis_is_failo(studentai, ivesties_failas, praejo);
            break;
            case 5:
                ivesties_failas = pasirinkti_faila_is_visu();
                praejo = false;
            break;
            case 6: {
                double laikas{ivesties_testavimas(praejo)};
                std::cout<<"Vidutinis failo skaitymo laikas: "<<laikas<<"\n";
                praejo=false;
                break;
            }
            case 7: {
                std::cout<<"Iveskite studentu kieki generuojame faile: \n";
                int studentu_kiekis{ivesties_patikrinimas(1,10000000)};
                failu_generavimas(studentu_kiekis);
                praejo = false;
                break;
            }
            case 8: {
                std::vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};

                /*for(auto &i: kiekiai) {
                    std::chrono::duration<double> testavimo_laikas{0};
                    for(int j=0; j<3; j++) {
                        auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
                        failu_generavimas(i);
                        auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
                        std::cout<<"Failo su "<<i<<" studentais generavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
                        testavimo_laikas+=sugaistas_laikas;
                    }
                    std::cout<<i << " vidurkis: " << testavimo_laikas.count()/3 <<"\n";
                }*/

                for(auto &i: kiekiai) {
                    std::chrono::duration<double> testavimo_laiku_suma{0};

                    for(int j=0; j<3; j++) {
                        std::vector<Studentas> temp_studentai{};
                        std::chrono::duration<double> testavimo_laikas{0};

                        fs::path failo_pavadinimas{"../data/input/studentai_isvestis" + std::to_string(i) + ".txt"};
                        auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
                        studentu_ivestis_is_failo(temp_studentai, failo_pavadinimas, praejo);
                        auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
                        std::cout<<"Failo su "<<i<<" studentais nuskaitymas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
                        testavimo_laikas+=sugaistas_laikas;

                        studentu_kategorizacija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);

                        std::cout<<i<<" irasu testavimo laikas: "<<testavimo_laikas.count()<<"\n";
                        std::cout<<"\n";
                        testavimo_laiku_suma +=testavimo_laikas;
                    }
                    std::cout<<i << " vidurkis: " << testavimo_laiku_suma.count()/3 <<"\n";
                    std::cout<<"\n---------------------------------------------------\n";
                    std::cout<<"\n---------------------------------------------------\n";
                    std::cout<<"\n---------------------------------------------------\n";
                }

            }
            default:
                return 0;
        }
        if(praejo)
            isvesties_meniu(studentai, isvesties_failo_pavadinimas);

    }

}


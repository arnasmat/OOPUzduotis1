//
// Created by User on 2025-02-10.
//

#include "../include/pagalbines.h"
#include "../include/ivesties_funkcijos.h"
#include "../include/isvesties_ir_skaiciavimu_funkcijos.h"
#include "../include/failu_pasirinkimo_funkcijos.h"


int main() {
    const std::string ivesties_failo_pavadinimas{"studentai1000000.txt"};
    const std::string isvesties_failo_pavadinimas{"rezultatai.txt"};

    isvardinti_failus_ivesties_direktorijoje();

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
                double laikas{ivesties_testavimas(praejo)};
                std::cout<<"Vidutinis failo skaitymo laikas: "<<laikas<<"\n";
                praejo=false;
                break;
            }
            default:
                return 0;
        }
        if(praejo)
            isvesties_meniu(studentai, isvesties_failo_pavadinimas);
    }

}


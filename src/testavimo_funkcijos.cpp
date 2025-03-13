//
// Created by User on 2025-03-06.
//

#include <testavimo_funkcijos.h>


void testavimo_rezimas(bool& praejo) {
        std::cout<<"Ka noretumete testuoti: \n"
                <<"1. Failu kurimo greiti\n"
                <<"2. Failu nuskaitymo greiti (su senos versijos testiniais failais)\n"
                <<"3. Failu nuskaitymo, rusiavimo, kategorizavimo ir isvesties greiti\n";
        praejo=false;
        int testavimo_pasirinkimas{ivesties_patikrinimas(1,3)};
        std::vector<int> kiekiai = {1000, 10000, 100000, 1000000, 10000000};
        switch(testavimo_pasirinkimas) {
            case 1:
                failu_kurimo_testavimas(kiekiai);
            break;
            case 2:
                ivesties_testavimas(praejo);
            break;
            case 3:
                konteineriu_pasirinkimas_testavimui(kiekiai, praejo);
            break;
            default:
                break;
        }
}

void ivesties_testavimas(bool& praejo) {
    try {
    fs::path testavimo_failas{pasirinkti_faila_is_testiniu()};
    std::cout<<"Iveskite kiek testu norite daryti (nuo 1 iki 100): \n";
    int testu_kiekis{ivesties_patikrinimas(1,100)};
    praejo=false;

    std::chrono::duration<double> nuskaitymo_laiku_suma{0};

        std::vector<Studentas> test_studentai;
        for(int i=0; i<testu_kiekis; i++) {
            auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
            studentu_ivestis_is_failo(test_studentai, testavimo_failas, praejo);
            std::chrono::duration<double> sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
            nuskaitymo_laiku_suma+=sugaistas_laikas;
            std::cout<<"Failo nuskaitymas uztruko: "<<sugaistas_laikas.count()<<"\n";
            test_studentai.clear();
        }
        std::cout<<"Vidutinis failo skaitymo laikas: "<<nuskaitymo_laiku_suma.count()/testu_kiekis<<"\n";
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida testuojant nuskaityma: "<<e.what()<<"\n";
    }
}

void failu_kurimo_testavimas(const std::vector<int>& kiekiai) {
    for(auto &i: kiekiai) {
        std::chrono::duration<double> testavimo_laikas{0};
        for(int j=0; j<3; j++) {
            auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
            failu_generavimas(i);
            auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
            std::cout<<"Failo su "<<i<<" studentais generavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
            testavimo_laikas+=sugaistas_laikas;
        }
        std::cout<<i << " vidurkis: " << testavimo_laikas.count()/3 <<"\n";
    }
}

void konteineriu_pasirinkimas_testavimui(const std::vector<int>& kiekiai, bool& praejo) {
    std::cout<<"Su kokiu konteineriu tipu noretumete testuoti: \n"
        <<"1. Vektoriais\n"
        <<"2. List'ais\n"
        <<"3. Deque\n";
    int konteineriu_pasirinkimas = ivesties_patikrinimas(1,3);

    if(konteineriu_pasirinkimas == 1) {
        std::vector<Studentas> temp_studentai{};
        nuskaitymo_ir_isvesties_testavimas(temp_studentai, kiekiai, praejo);
    } else if(konteineriu_pasirinkimas ==2) {
        std::list<Studentas> temp_studentai{};
        nuskaitymo_ir_isvesties_testavimas(temp_studentai, kiekiai, praejo);
    } else {
        std::deque<Studentas> temp_studentai{};
        nuskaitymo_ir_isvesties_testavimas(temp_studentai, kiekiai, praejo);
    }
}
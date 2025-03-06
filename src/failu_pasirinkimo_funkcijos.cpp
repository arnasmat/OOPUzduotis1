//
// Created by User on 2025-02-19.
//

#include <failu_pasirinkimo_funkcijos.h>
#include <pagalbines.h>
#include <ivesties_pagalbines.h>

std::vector<fs::path> gauti_failus_ivesties_direktorijoje(){
    try {
        std::vector<fs::path> failai{};
        for (const auto & entry : fs::directory_iterator("../data/input"))
            if(entry.path().extension() == ".txt") {
                failai.push_back(entry.path());
            }
        return failai;
    } catch(std::exception& e) {
    std::cerr<<"Ivyko klaida nuskaitant testinius failus: "<<e.what()<<"\n";
    return {};
    }
}

std::vector<fs::path> gauti_failus_ivesties_testu_direktorijoje(){
    try {
        std::vector<fs::path> failai{};
        for (const auto & entry : fs::directory_iterator("../data/test_inputs"))
            if(entry.path().extension() == ".txt") {
                failai.push_back(entry.path());
            }
        return failai;
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida nuskaitant testinius failus: "<<e.what()<<"\n";
        return {};
    }
}

fs::path pasirinkti_faila_is_visu() {
    try {
        std::vector<fs::path> visi_failai {gauti_failus_ivesties_direktorijoje()};
        std::vector<fs::path> testiniai_failai {gauti_failus_ivesties_testu_direktorijoje()};
        for(const auto& i : testiniai_failai) {
            visi_failai.push_back(i);
        }

        std::cout<<"Pasirinkite faila, su kuriuo norite dirbti: \n";
        for(int i=0; i<visi_failai.size(); i++) {
            std::cout<<i+1<<". "<<visi_failai[i].filename()<<"\n";
        }
        int failo_pasirinkimas{ivesties_patikrinimas(1, static_cast<int>(visi_failai.size()))};
        return visi_failai[failo_pasirinkimas-1];
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida pasirenkant faila: "<<e.what()<<"\n";
        return "";
    }
}

fs::path pasirinkti_faila_is_testiniu() {
    try{
    std::vector<fs::path> testiniai_failai {gauti_failus_ivesties_testu_direktorijoje()};
    std::cout<<"Pasirinkite testini faila, su kuriuo norite dirbti: \n";
    for(int i=0; i<static_cast<int>(testiniai_failai.size()); i++) {
        std::cout<<i+1<<". "<<testiniai_failai[i].filename()<<"\n";
    }
    int failo_pasirinkimas{ivesties_patikrinimas(1, static_cast<int>(testiniai_failai.size()))};
    return testiniai_failai[failo_pasirinkimas-1];
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida pasirenkant faila: "<<e.what()<<"\n";
        return "";
    }
}
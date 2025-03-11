//
// Created by User on 2025-02-19.
//

#include <isvesties_ir_skaiciavimu_funkcijos.h>

//globalus kintamieji testavimo laikams
extern std::chrono::duration<double> testavimo_laikas;

void failu_generavimas(int studentu_kiekis){
    // std::vector<Studentas> studentai{};
    // studentai.reserve(studentu_kiekis);

    std::ostringstream output{""};
    std::uniform_int_distribution<int> random_kiekis(5, 15);

    int isvesties_vardo_ilgis{static_cast<int>(("Vardas"+ std::to_string(studentu_kiekis)).length() > 6 ? ("Vardas"+ std::to_string(studentu_kiekis)).length() + 2 : 8)};
    int isvesties_pavardes_ilgis{static_cast<int>(("Pavarde"+ std::to_string(studentu_kiekis)).length() > 7 ? ("Pavarde"+ std::to_string(studentu_kiekis)).length() + 2 : 8)};

    int pazymiu_kiekis = random_kiekis(mt);
    output<<std::left<<std::setw(isvesties_vardo_ilgis)
        <<"Vardas"
        <<std::left<<std::setw(isvesties_pavardes_ilgis)
        <<"Pavarde";
    for(int i=0; i<pazymiu_kiekis; i++) {
        //jei netingesiu paziuret kaip cia padaryt be to_str nes kazkaip negraziai kodas atrodo, bet su << susimaiso ju layoutas
        output<<std::left<<std::setw(5)<<"ND"+std::to_string(i+1);
    }
    output<<"Egz.\n";

    std::uniform_int_distribution<int> random_pazymys(1, 10);

    for(int i=0; i<studentu_kiekis; i++) {
        //Vardo ir pavardes generavimas failui
        output<<std::left<<std::setw(isvesties_vardo_ilgis)<<"Vardas" + std::to_string(i+1)
            <<std::left<<std::setw(isvesties_pavardes_ilgis)<<"Pavarde" + std::to_string(i+1);
        //Namu darbu ivertinimu generavimas
        for(int j=0; j<pazymiu_kiekis; j++) {
            output<<std::left<<std::setw(5)<< random_pazymys(mt);
        }
        //Egzamino rezultato generavimas
        output<<random_pazymys(mt)<<"\n";
    }

    std::ofstream isvesties_failas("../data/input/studentai_isvestis" + std::to_string(studentu_kiekis) + ".txt");
    isvesties_failas<<output.str();
    isvesties_failas.close();
}

float galutinis_pazymys_vidurkis(Studentas &studentas) {
    unsigned int pazymiu_suma{0};
    if(studentas.pazymiai.empty()) return 0;;
    for(const auto &i: studentas.pazymiai) {
        pazymiu_suma+=i;
    }
    return static_cast<float>(static_cast<float>(pazymiu_suma) / static_cast<float>(studentas.pazymiai.size()) * 0.4 + studentas.egzamino_rezultatas * 0.6);
}

float galutinis_pazymys_mediana(Studentas &studentas) {
    float mediana{0};
    std::sort(studentas.pazymiai.begin(), studentas.pazymiai.end());
if(studentas.pazymiai.size() % 2 == 0) {
    mediana = static_cast<float>(studentas.pazymiai[studentas.pazymiai.size() / 2]
        + studentas.pazymiai[studentas.pazymiai.size() / 2 - 1]) / 2.0f;
} else {
    mediana = static_cast<float>(studentas.pazymiai[studentas.pazymiai.size() / 2]);
}
    return mediana * 0.4f + static_cast<float>(studentas.egzamino_rezultatas) * 0.6f;
}

//Void isvestis ir isvesties_meniu implementuota .tpp faile

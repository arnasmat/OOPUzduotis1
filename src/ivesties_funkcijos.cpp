//
// Created by User on 2025-02-19.
//

#include <ivesties_funkcijos.h>

int meniu(const fs::path &ivesties_failo_pavadinimas) {
    std::cout<<"------------------------------------------------------------\n"
            <<"Pasirinkite programos eiga: \n"
            <<"1. Studentus ir pazymius ivesti ranka\n"
            <<"2. Generuoti pazymius, bet studentus ivesti ranka\n"
            <<"3. Generuoti pazymius ir studentus\n"
            <<"4. Ivesti pazymius is failo, siuo metu pasirinktas failas: "<<ivesties_failo_pavadinimas.filename()<<"\n"
            <<"5. Pasirinkti ivesties faila\n"
            <<"6. Generuoti faila\n"
            <<"7. Testavimo rezimas\n"
            <<"8. Baigti programos darba\n"
            <<"------------------------------------------------------------\n";
    int meniu{ivesties_patikrinimas(1,8)};
    return meniu;
}

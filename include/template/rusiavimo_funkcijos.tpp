
template <typename Container>
void studentu_rusiavimas(Container& studentai, int rusiavimo_pasirinkimas) {
    auto comparator_vardas = [](const Studentas &a, const Studentas &b) {
        return a.vardas < b.vardas;
    };
    auto comparator_pavarde = [](const Studentas &a, const Studentas &b) {
        return a.pavarde < b.pavarde;
    };
    auto comparator_vidurkis_asc = [](const Studentas &a, const Studentas &b) {
        return a.galutinis_vidurkis < b.galutinis_vidurkis;
    };
    auto comparator_vidurkis_desc = [](const Studentas &a, const Studentas &b) {
        return a.galutinis_vidurkis > b.galutinis_vidurkis;
    };
    auto comparator_mediana_asc = [](const Studentas &a, const Studentas &b) {
        return a.galutinis_mediana < b.galutinis_mediana;
    };
    auto comparator_mediana_desc = [](const Studentas &a, const Studentas &b) {
        return a.galutinis_mediana > b.galutinis_mediana;
    };

    switch(rusiavimo_pasirinkimas) {
        case 1:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_vardas);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_vardas);
            }
            break;
        case 2:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_pavarde);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_pavarde);
            }
            break;
        case 3:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_vidurkis_desc);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_vidurkis_desc);
            }
            break;
        case 4:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_vidurkis_asc);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_vidurkis_asc);
            }
            break;
        case 5:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_mediana_desc);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_mediana_desc);
            }
            break;
        case 6:
            if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
                studentai.sort(comparator_mediana_asc);
            } else {
                std::sort(studentai.begin(), studentai.end(), comparator_mediana_asc);
            }
            break;
        default:
            break;
    }
}

template <typename Container>
void studentu_galutiniu_pazymiu_skaiciavimas(Container& studentai) {
    //Patikrina, ar paskutinio studento galutinis pazymys apskaiciuotas, kad nebutu pertekliniu skaiciavimu
    if(studentai.back().galutinis_vidurkis == 0 || studentai.back().galutinis_mediana == 0) {
        for(auto &i: studentai) {
            i.galutinis_vidurkis = galutinis_pazymys_vidurkis(i);
            i.galutinis_mediana = galutinis_pazymys_mediana(i);
        }
    }
}

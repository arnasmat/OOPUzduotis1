template <typename Container>
void vardu_ivestis(const Container& studentai, Studentas &laikinas_studentas) {
    try {
        std::cout<<"Iveskit studento varda ir pavarde (noredami baigti iveskite 'n'): ";
        std::cin>>laikinas_studentas.vardas;

        while (laikinas_studentas.vardas == "n" && studentai.empty()) {
            std::cout<<"Iveskite bent viena studenta: \n";
            std::cin>>laikinas_studentas.vardas;
        }

        if(laikinas_studentas.vardas == "n" && !studentai.empty()) {
            return;
        }

        std::cin>>laikinas_studentas.pavarde;

    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida ivedant varda ir pavarde: "<<e.what()<<"\n";
        laikinas_studentas.vardas = "Vardas";
        laikinas_studentas.pavarde = "Pavarde";
    }
}
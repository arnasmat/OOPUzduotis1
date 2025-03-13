
template <typename Container>
void studentu_kategorizacija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    Container islaike_studentai{};
    Container neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;


    nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    if(rusiuoti_pagal == 3) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal == 4) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
    }else if(rusiuoti_pagal==5){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana>=5.0f;}
            );
            islaike_studentai.assign(studentai.begin(), partition_iteratorius);
            neislaike_studentai.assign(partition_iteratorius, studentai.end());
    } else if(rusiuoti_pagal==6){
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_mediana<=5.0f;}
            );
        neislaike_studentai.assign(studentai.begin(), partition_iteratorius);
        islaike_studentai.assign(partition_iteratorius, studentai.end());
        if constexpr (!std::is_same_v<Container, std::list<Studentas>>) {
            neislaike_studentai.shrink_to_fit();
            islaike_studentai.shrink_to_fit();
        }
        studentai.clear();
    }

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    try {
        nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        std::ofstream islaike_output("../data/output/islaike_studentai.txt");
        isvestis(islaike_studentai, islaike_output, rodyti_pasirinkimas);
        islaike_output.close();
        sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        std::cout<<i<<" Irasu islaikiusiuju irasymo i faila laikas: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
        testavimo_laikas+=sugaistas_laikas;

        nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
        std::ofstream neislaike_output("../data/output/neislaike_studentai.txt");
        isvestis(neislaike_studentai, neislaike_output, rodyti_pasirinkimas);
        neislaike_output.close();
        sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
        std::cout<<i<<" Irasu neislaikiusiuju irasymo i faila laikas: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
        testavimo_laikas+=sugaistas_laikas;
    } catch(std::exception& e) {
        std::cerr<<"Ivyko klaida isvedant i failus failus: "<<e.what()<<"\n";
    }
}

template <typename Container>
void nuskaitymo_ir_isvesties_testavimas(Container& temp_studentai, const std::vector<int>& kiekiai, bool& praejo){
    try {
        for(auto &i: kiekiai) {
            std::chrono::duration<double> testavimo_laiku_suma{0};
            for(int j=0; j<3; j++) {
                std::chrono::duration<double> testavimo_laikas{0};
                fs::path failo_pavadinimas{"../data/input/studentai_isvestis" + std::to_string(i) + ".txt"};
                auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
                studentu_ivestis_is_failo(temp_studentai, failo_pavadinimas, praejo);
                auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
                // std::cout<<"Failo su "<<i<<" studentais nuskaitymas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
                testavimo_laikas+=sugaistas_laikas;
                //Greiciausias vis tiek senas metodas lol
                studentu_kategorizacija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
                // studentu_kategorizacija_1_strategija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
                // studentu_kategorizacija_2_strategija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
                // studentu_kategorizacija_3_strategija_testavimas(temp_studentai, 3, 3,testavimo_laikas, i);
                // std::cout<<i<<" irasu testavimo laikas: "<<testavimo_laikas.count()<<"\n";
                testavimo_laiku_suma +=testavimo_laikas;
                temp_studentai.clear();
            }
            std::cout<<i << " vidurkis: " << testavimo_laiku_suma.count()/3 <<"\n";
            // std::cout<<"\n---------------------------------------------------\n";
        }
    }
    catch(std::exception &e) {
        std::cerr<<"Ivyko klaida testuojant "<<e.what()<<"\n";
        std::cerr<<"Galbut testavimo failai nesugeneruoti? Pabandykite paleisti testavimo failu kurima. \n";
    }
}

template <typename Container>
void studentu_kategorizacija_1_strategija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    Container islaike_studentai{};
    Container neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    //Testavimui tik sis variantas, nes jis ir naudojamas testuoti :).
    if(rusiuoti_pagal==3) {
        for(auto &stud :studentai) {
            if(stud.galutinis_vidurkis >= 5.0) {
                islaike_studentai.push_back(stud);
            } else {
                neislaike_studentai.push_back(stud);
            }
        }
    }
    if constexpr (!std::is_same_v<Container, std::list<Studentas>>) {
        neislaike_studentai.shrink_to_fit();
        islaike_studentai.shrink_to_fit();
    }
    studentai.clear();

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;
    // Toliau nerasau, nes testavimui reikalinga tik tiek :)
}

template <typename Container>
void studentu_kategorizacija_2_strategija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    Container neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    //Testavimui tik sis variantas, nes jis ir naudojamas testuoti :).
    if (rusiuoti_pagal == 3) {
        while(studentai.back().galutinis_vidurkis < 5.0f) {
            neislaike_studentai.push_back(studentai.back());
            studentai.pop_back();
        }
    }
    if constexpr (!std::is_same_v<Container, std::list<Studentas>>) {
        neislaike_studentai.shrink_to_fit();
    }

    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;
    // Toliau nerasau, nes testavimui reikalinga tik tiek :)
}

template <typename Container>
void studentu_kategorizacija_3_strategija_testavimas(Container& studentai, const int rodyti_pasirinkimas, const int rusiuoti_pagal, std::chrono::duration<double>& testavimo_laikas, const int i) {
    //ekvivalentu "kietekams" ir "vargsiukams", tiesiog formaliau pavadinta
    Container neislaike_studentai{};

    auto nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    studentu_galutiniu_pazymiu_skaiciavimas(studentai);
    studentu_rusiavimas(studentai, rusiuoti_pagal);
    auto sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu rusiavimas truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

    nuskaitymo_laikas = std::chrono::high_resolution_clock::now();
    if(rusiuoti_pagal == 3) {
        auto partition_iteratorius = std::partition_point(
            studentai.begin(), studentai.end(),
            [](const Studentas& studentas) {return studentas.galutinis_vidurkis>=5.0f;}
            );
        neislaike_studentai.assign(partition_iteratorius, studentai.end());
        studentai.resize(std::distance(studentai.begin(), partition_iteratorius));
    }
    sugaistas_laikas = std::chrono::high_resolution_clock::now() - nuskaitymo_laikas;
    // std::cout<<i<<" Irasu kategorizavimas istrinant originalu vektoriu truko: "<<std::chrono::duration<double>(sugaistas_laikas).count()<<"\n";
    testavimo_laikas+=sugaistas_laikas;

}